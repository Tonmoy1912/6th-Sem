import socket

server_socket = socket.socket()
print("Socket Created")

server_socket.bind(("localhost", 8000))
server_socket.listen(10)

print("Waiting for connections....")

db=list()#(add,key,val)

while True:
    client_socket,client_address=server_socket.accept()
    print(f"connected to client {client_address}")
    data=client_socket.recv(1024).decode()
    query_list=data.split(".")
    query_list.pop(0)
    n=len(query_list)
    client_address=client_address[1]
    i=0
    ans=""
    while i<n:
        if query_list[i]=="put":
            # j=0
            i+=1
            key=query_list[i]
            i+=1
            val=query_list[i]
            # i+=1
            db_len=len(db)
            j=0
            while j<db_len:
                if(db[j][0]==client_address and db[j][1]==key):
                    break
                j+=1
            if j<db_len:
                db[j][2]=val
            else:
                db.append([client_address,key,val])
            # client_socket.send("Key added successfully".encode())

        elif query_list[i]=="get":
            i+=1
            key=query_list[i]
            # i+=1
            db_len=len(db)
            j=0
            while j<db_len:
                if(db[j][0]==client_address and db[j][1]==key):
                    break
                j+=1
            if j<db_len:
                # db[j][2]=val
                # client_socket.send(db[j][2].encode())
                ans+=f"\n{db[j][2]}"
            else:
                # db.append([client_address,key,val])
                # client_socket.send("<blank>".encode())
                ans+="\n<blank>"
        i+=1

    #outside loop
    client_socket.send(ans.encode())



client_socket.close()

