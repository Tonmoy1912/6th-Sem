import socket
import sys


# received_message = client_socket.recv(1024).decode()

# print(received_message)

# client_socket.send("Hello world from client".encode())

# client_socket.close()

print("Command line args")
print(sys.argv)
in_put=sys.argv


client_socket = socket.socket()
client_socket.connect((f"{in_put[1]}", int(in_put[2])))

query=""
n=len(in_put)
for i in range(3,n):
    query+="."+in_put[i]

print(query)
# query=query.split(".")
# query.pop(0)
# print(query)

client_socket.send(query.encode())
response=client_socket.recv(1024).decode()
print(response)

client_socket.close()