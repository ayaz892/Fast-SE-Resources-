# import necessary modules
import socket 
import sys
from _thread import *
import requests

# define variables for host name, port number, buffer size, and blocked URLs
host_name=''
bind_port=9999
buffer_size=8192
blocked=[]

# function to check if a given URL is blocked
def server_block(serv_url):
   # check if the URL is in the list of blocked URLs
   if serv_url in blocked:
      return True  # if it is, return True (i.e. the URL is blocked)
   return False  # if it's not, return False (i.e. the URL is not blocked)



# This function retrieves a file from the cache if it exists
# It takes in a filename as input
def retrieve_cache(filename):
   try:
        # Check if we have this file locally in the cache directory
        # The file name is modified by replacing any forward slashes with double underscores to avoid any path related issues
        fin = open('cache/' + filename.replace("/","__"),"rb")
        # Read the contents of the file
        content = fin.read()
        fin.close()
        # If the file exists in the cache, return its contents
        return content
   except IOError:
        # If the file does not exist in the cache, return None
        return 
        
# This function inserts a file into the cache
# It takes in a filename and the file content as input
def insert_to_cache(filename, content):
   # Print a message to indicate that a copy of the file is being saved in the cache
   print('Saving a copy of {} in the cache'.format(filename))
   # Print the path of the cached file
   print("cache/"+filename.replace("/","__"))
   
   try:
    # Open the cached file in binary write mode
    cached_file = open('cache/' + filename.replace("/","__"), 'wb')
    # Write the file content to the cached file
    cached_file.write(content)
    # Close the cached file
    cached_file.close()
   except IOError as e:
      # If there is an error in writing the file to the cache, print the error message
      print("File error")
      print(e)
      
# This function parses a string containing an HTTP request
# It takes in the request string as input
def parse_string(data):
   try: 
    # Decode the request string
    lines=data.decode()
    # Print the decoded request string
    print(lines)
    # Get the first line of the request string
    first_line=lines.split("\n")[0]
    # Get the URL from the first line
    url=first_line.split(" ")[1]
    # Set the default protocol to "http"
    prot=url
    # Check if the URL has a protocol specified
    http_pos=url.find("://")
    if http_pos == -1:
      # If there is no protocol specified, assume "http"
      temp = url
      protocol='http'
    else:
      # If there is a protocol specified, extract it from the URL
      protocol = url[:http_pos]
      # Remove the protocol from the URL
      url=url[(http_pos+3):]
      # Store the modified URL in a temporary variable
      temp = url  

    # Check if the URL specifies a port
    port_pos=temp.find(":")
    # Get the position of the web server
    webserver_pos=temp.find("/")
    if webserver_pos == -1:
      # If there is no web server specified, assume the entire URL is the server address
      webserver_pos = len(temp)
    # Initialize the web server and port
    webserver=""
    port=-1

    if port_pos == -1 or webserver_pos < port_pos:
      # If there is no port specified or the web server is before the port in the URL
      # Set the default port to 80
      port=80
      # Get the web server address
      webserver = temp[:webserver_pos]
    else:
      # If there is a port specified
      # Get the port number
            # Extract the port substring and convert it to an integer

      port = int((temp[(port_pos+1):])[:webserver_pos-port_pos-1])
      
      # Extract the web server substring
      webserver=temp[:port_pos]

      # Return the protocol, web server, port, and URL path as a tuple

    return webserver,port,url,prot
   except Exception as e:
     print(e)   


def client_thread(conn,data,addr):

  webserver,port,url,proto=parse_string(data)

  if server_block(webserver):
      conn.send(bytes("HTTP/1.0 404 OK\r\n",'utf-8'))
      conn.send(bytes("Content-Length: 11\r\n",'utf-8'))
      conn.send(bytes("\r\n",'utf-8'))
      conn.send(bytes("Blocked\r\n",'utf-8'))
      conn.send(bytes("\r\n\r\n",'utf-8'))
      print(webserver, "is blacklisted")
      conn.close()
  else:    
   s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)   #ipv4 and   TCP connection
   if proto[:5] == 'http:': 
    print("http")
    try:
      
      s.connect((webserver,port))
      s.send(data)

      while True:
         content=retrieve_cache(url)
         
         if content:
           print("got from cache")
           reply=content        #if in cache
         else:   
      
           reply = s.recv(buffer_size)
                      
         if len(reply)>0:
            conn.sendall(reply)
            print("Request done : {}  <= {}".format(addr[0],webserver))
            insert_to_cache(url,reply)
         else:
             break
      s.close()
      conn.close()      
    except socket.error:
      s.close()
      conn.close()
      sys.exit(1)
   else:
    print("https") 
    try:
     s.connect((webserver,port))
     GET = "GET / HTTP/1.1\r\nHost: " + webserver + "\r\nConnection: close\r\n\r\n"
     reply = "HTTP/1.0 200 Connection established\r\n"
     reply += "Proxy-agent: Pyx\r\n"
     reply += "\r\n"
     conn.sendall(reply.encode())
     conn.setblocking(0)
     s.setblocking(0)
     while True:
        try:
            request = s.recv(1024)
            conn.sendall(request)
        except socket.error as err:
            pass
        try:
            reply = conn.recv(1024)
            s.sendall(reply)
        except socket.error as err:
            pass

     s.close()
    except socket.error as e:
      print(e)
      s.close()
      conn.close()

if __name__ =="__main__":

   f = open('blacklist.txt', "rb")
   data = ""
   while True:
    chunk = f.read()
    if not len(chunk):
        break
    data += chunk.decode()
   f.close()
   blocked = data.splitlines()

   try:
    pserver=socket.socket(socket.AF_INET, socket.SOCK_STREAM)# Create a new socket object using the socket module with the AF_INET address family and SOCK_STREAM socket type

   # pserver.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    pserver.bind(('',bind_port))   #port == 9999
    pserver.listen(10)
    print("Socket Initialized")
    print("Server started successfully [{}]".format(bind_port))
   except Exception as e:
    print(e) 
    sys.exit(2)

   while True:
    try:
     conn,addr=pserver.accept() # accept new incoming connections and get client socket and address
     data=conn.recv(buffer_size)# accept new incoming connections and get client socket and address
     start_new_thread(client_thread,(conn,data,addr))# accept new incoming connections and get client socket and address
    except KeyboardInterrupt:# if keyboard interrupt is detected
      pserver.close()# close the server socket
      print("Shutting down")# close the server socket
      sys.exit(1)   # exit the program with an error status code

   pserver.close()       # close the server socket when the loop is done
