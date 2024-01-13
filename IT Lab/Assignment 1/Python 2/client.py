import socket
import sys

print("Command line args")
print(sys.argv)
in_put=sys.argv

password="1234"


client_socket = socket.socket()
client_socket.connect((f"{in_put[1]}", int(in_put[2])))
print("Connected to the server")

n=len(in_put)
i=3
isManager=False
while i<n:
    if(in_put[i]=="put"):
        query="put"+"."+in_put[i+1]+"."+in_put[i+2]
        if(isManager):
            query=query+".manager"
        client_socket.send(query.encode())
        # print("Send put request")
        client_socket.recv(1024).decode()
        i=i+3
    elif in_put[i]=='get':
        query="get"+"."+in_put[i+1]
        if(isManager):
            query=query+".manager"
        client_socket.send(query.encode())
        # print("Send get request")
        message=client_socket.recv(1024).decode()
        print(message)
        i=i+2
    elif in_put[i]=='promote':
        recvPass=input("Enter the password:\n")
        if(recvPass==password):
            isManager=True
            print("Promoted to manager")
        else:
            print("Wrong password")
        i=i+1


client_socket.close()