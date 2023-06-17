from socket import *
import sys

# Function to find sum of 16 bit words of a packet
def summ(f):  
    carry_next=0
    stringg=[]
    for i in range(0,16,1):
        s=int(f[0][i])+int(f[1][i])+carry_next
        if s==0:
            stringg.append('0')
        elif s==1:
            stringg.append('1')
            if carry_next==1:
                carry_next=0
        elif s==2:
            stringg.append('0')
            carry_next=1
        elif s==3:
            stringg.append('1')
            carry_next=1
    while(carry_next!=0):
        for i in range(0,16,1):
            s=int(stringg[i])+carry_next
            if s==int(stringg[i]):
                break
            if s==1:
                stringg[i]='1'
                if carry_next==1:
                    carry_next=0
            if s==2:
                stringg[i]='0'
                carry_next=1
    return stringg

def bit_conversion(text):
    # This function takes a string 'text' as input and returns its binary representation as a list of bits
    ascii_values = [] # create an empty list to store the ASCII values of each character in 'text'
    flag=0 # create a flag variable and set it to 0
    for character in text:
        # loop through each character in the input string 'text'
        ascii_values.append(ord(character)) # append the ASCII value of the current character to the list 'ascii_values'
    for i in ascii_values:
        # loop through each ASCII value in 'ascii_values'
        f=[]
        while i!=0:
            i=int(i)
            f.append(str(i%2))
            i/=2
            i=int(i)
        f.append('0') # append a '0' at the end of the binary representation to signify the end of the current character
        if flag==0:
            # if this is the first character being converted to binary, store the binary representation in the list 'binary_vals'
            binary_vals=list(f)
            flag=1
        else:
            # if this is not the first character, append the binary representation to the existing list 'binary_vals'
            binary_vals+=f
    return binary_vals


def packet_distribution(data,packet_size):  # Divide message into packets
    try:
        packets=[]
        reminder=int(len(data)%packet_size) # calculate reminder
        number_of_packets=int(len(data)/packet_size) # calculate number of packets
        for i in range(number_of_packets):
            # append packets to packets list
            packets.append(list(data[(i*packet_size):(packet_size+(packet_size*i))]))
        rem=list(data[(number_of_packets*packet_size):(reminder+(packet_size*number_of_packets))])
        # if the last packet is not full, fill it with spaces
        for i in range((5-len(rem))):
            rem.append(' ')
        packets.append(rem)
        return packets
    except Exception as e:
        # handle exception
        print("Can't create packets")
        return []



# Function to find the first complement of a string of binary digits
def firstcom(s):  
    for i in range(len(s)):
        if s[i]=='0':
            s[i]='1'
        elif s[i]=='1':
            s[i]='0'
    return s

# Main function to find the checksum of a packet
def calculate_checksum(f):   
    # Initialize a list with a single element of all zeroes
    sum=[['0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0']]
    count=0
    for  i in f:
        # Check if the element has length 2, which indicates a packet
        if len(i)==2:
            # Convert the packet to bits and add it to the list
            sum.append(bit_conversion(i))
            count+=1
    if count==2:
        # If there are two packets, take the checksum of the first two packets
        s=list(sum[1:3])
        s=summ(s) # Function summ() adds binary numbers in list s
        s=firstcom(s) # Take the first complement of the sum
        s=''.join(s)
        return(s)
    elif count==1:
        # If there is only one packet, take the checksum of that packet
        return(''.join(firstcom(sum[1])))
    else:
        # If there are no packets, take the checksum of the all-zeroes list
        return(''.join(firstcom(sum[0])))


# Function to compute the checksum of all packets in a list of packets
def checksum_calculation(packets):  
    try:
        s=[]
        bit_conversion=[]
        for i in range(len(packets)):
            f=''.join(packets[i])
            s.append(f.split())
            bit_conversion.append(calculate_checksum(f.split()))
        return(bit_conversion)
    except Exception as e:
        print('cant do it')

# Function to create a packet with the given packet data, checksum, and sequence number
def paket_creation(packet,bit_conversion,seq):
    f=''.join(packet)+'/r'+bit_conversion+'/r'+str(seq)
    return(f)

# Main function for sending packets using the Reliable Data Transfer (RDT) protocol
def rdt_send(data,serverName,serverPort,clientSocket):
    packet_size=5
    packetss=packet_distribution(data,packet_size) # Divide the data into packets
    print("Number of packets made",int(len(packetss)))
    bit_conversion=checksum_calculation(packetss) # Compute the checksum of all packets
    seq_no=0
    prev_sequence=seq_no
    for i in range(len(packetss)):
        count=1
        timeoutflag=0
        message=paket_creation(packetss[i],bit_conversion[i],seq_no) # Create a packet with data, checksum, and sequence number
        print("Sending packet",i,"with checksum",str(bit_conversion[i]),"and sequence number",seq_no)
       
        if seq_no==1:
            seq_no=0
        else:
            seq_no=1
        clientSocket.sendto(message.encode(),(serverName, serverPort)) # Send the packet to the server
        while True:
            try:
                modifiedMessage, serverAddress = clientSocket.recvfrom(2048) # Receive the acknowledgement from the server
                break
            except Exception as aa:
                count+=1
               

                if count==100000:
                    print("Timeout")
                    timeoutflag=1
                    break
        if timeoutflag==1:
            i-=1
            if seq_no==1:
                seq_no=0
            else:
                seq_no=1
            continue
        modifiedMessage=modifiedMessage.decode()
        modifiedMessage= modifiedMessage.split('/r')
        s=[]
        s.append(list(str(modifiedMessage[1])))
        s.append(list('0100000101001011'))
        ff=summ(s)
        if ('0'  in ff) or (seq_no==int(modifiedMessage[2])):
            i-=1
            print("Error (Sequence Number is wrong)")
            if seq_no==1:
                seq_no=0
            else:
                seq_no=1
        else:
            print("Acknowledgement of packet with sequence number",modifiedMessage[2],"received")
    message="/r/r"
    clientSocket.sendto(message.encode(),(serverName, serverPort))
    return






# Define server name and port number
serverName = "localhost"
serverPort = 5555
# Create UDP socket and set to non-blocking mode
clientSocket = socket(AF_INET, SOCK_DGRAM)
clientSocket.setblocking(0)
# Loop to send messages to server
while True:
    try:
        # Get message from user
        message = input("Send the Packet From Here:")
        # Send message using RDT protocol
        rdt_send(message, serverName, serverPort, clientSocket)
    # If user presses Ctrl+C, exit program
    except KeyboardInterrupt as ee:
        sys.exit(1)
# Close socket connection
clientSocket.close()
