import sys
from socket import *

def add(f):
    # Initialize a carry_next variable to 0 and an empty list to store the sum
    carry_next = 0
    stringg = []

    # Iterate over the two binary numbers f[0] and f[1] from right to left (i.e. index 15 to index 0)
    for i in range(15, -1, -1):
        # Calculate the sum of the two bits at position i in f[0] and f[1], and the carry_next
        s = int(f[0][i]) + int(f[1][i]) + carry_next

        # If the sum is 0, append '0' to the sum list and set carry_next to 0
        if s == 0:
            stringg.append('0')
        # If the sum is 1, append '1' to the sum list and set carry_next to 0 if it was 1, else set carry_next to 1
        elif s == 1:
            stringg.append('1')
            if carry_next == 1:
                carry_next = 0
        # If the sum is 2, append '0' to the sum list and set carry_next to 1
        elif s == 2:
            stringg.append('0')
            carry_next = 1
        # If the sum is 3, append '1' to the sum list and set carry_next to 1
        elif s == 3:
            stringg.append('1')
            carry_next = 1

    # If there is a final carry_next after the loop, add it to the sum list
    while carry_next != 0:
        for i in range(0, 16, 1):
            s = int(stringg[i]) + carry_next
            if s == int(stringg[i]):
                break
            if s == 1:
                stringg[i] = '1'
                if carry_next == 1:
                    carry_next = 0
            if s == 2:
                stringg[i] = '0'
                carry_next = 1

    # Return the sum list
    return stringg

# This function takes a msg string as input and returns its binary representation as a list of 0s and 1s
def checksum(msg):
    ascii_values = []
    flag=0
    # Convert each character of the msg string to its ASCII code and add it to a list
    for character in msg:
        ascii_values.append(ord(character))
    # Convert each ASCII code to its binary representation and add it to a list
    for i in ascii_values:
            f=[]
            while i!=0:
                i=int(i)
                f.append(str(i%2))
                i/=2
                i=int(i)
            f.append('0')
            if flag==0:
                binary_vals=list(f)
                flag=1
            else:
                binary_vals+=f
    # Return the list of binary values
    return binary_vals

# This function takes a list of binary strings as input and returns a checksum string
def checksum_calculations(f):
    sum=[['0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0']]
    count=0
    # If there are two binary strings in the input list, calculate their binary checksums and add them to a new list
    for  i in f:
        if len(i)==2:
            sum.append(checksum(i))
            count+=1
    # If there are exactly two binary checksums, sum them and return the result as a string
    if count==2:
        s=list(sum[1:3])
        s=add(s)
        s=''.join(s)
        return(s)
    # If there is only one binary checksum, return it as a string
    elif count==1:
        return(''.join(sum[1]))
    # If there are no binary checksums, return a default checksum string
    else:
        return(''.join(sum[0]))


# Define server port and socket
serverPort = 5555
serverSocket = socket(AF_INET, SOCK_DGRAM)

# Define server name and bind socket to server name and port
serverName = "localhost" 
serverSocket.bind((serverName, serverPort))

# Print waiting message
print("Waiting To Receive Message :")
print('')

# Initialize variables for acknowledgement sequence, request and message
ackseq=-1
req=0
messg=''

# Enter infinite loop to receive and process incoming messages
while True:
    try:
        # Receive incoming message and client address
        message, clientAddress = serverSocket.recvfrom(2048)
        
        # Decode incoming message
        message=message.decode()
        
        # If incoming message is a reset command, print the message received so far and reset variables
        if message=="/r/r":
            print('Sender==========> ',messg)
            print('')
            ackseq=-1
            req=0
            messg=''
            continue
        
        # Split incoming message by carriage return
        message=message.split('/r')
        
        # Calculate checksum of incoming message and add to list of checksums
        checksumm=[]
        checksumm.append(list(checksum_calculations(message[0].split())))
        checksumm.append(list(message[1]))
        sum=add(checksumm)
        
        # If checksum is correct and request number matches, send acknowledgement and update variables
        if ('0' not in sum) and (req==int(message[2])):
            if req==0:
                req=1
                ackseq=0
            else :
                req=0
                ackseq=1
            messg+=message[0]
            modifiedMessage = 'AK'+'/r'+'1011111010110100'+'/r'+message[2]
            serverSocket.sendto(modifiedMessage.encode(), clientAddress)
        
        # If checksum is incorrect or request number does not match, send negative acknowledgement
        elif ('0' in sum) or (req!=int(message[2])):
            modifiedMessage = 'AK'+'/r'+'1011111010110100'+'/r'+str(ackseq)
            serverSocket.sendto(modifiedMessage.encode(), clientAddress)
    
    # Exit program if keyboard interrupt occurs
    except KeyboardInterrupt as e:
        sys.exit()

# Close server socket
serverSocket.close()