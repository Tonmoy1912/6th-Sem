import socket
import threading

server_socket=socket.socket()

server_socket.bind(("localhost", 8000))
server_socket.listen(10)

sem=threading.Semaphore(1)

db=dict()#key=token value=collection of key-value pair

def handleClient(client_socket,token):
    print(f"Thread start for {token}")
    if(token not in db):
        sem.acquire()
        db[token]=dict()
        sem.release()


    while True:
        query=client_socket.recv(1024).decode()
        # print(f"query received {query}")
        if not query:
            #connection closed
            client_socket.close()
            break
        query=query.split(".")

        if(query[0]=="put"):
            key=query[1]
            val=query[2]
            # if (key not in db[token]):
            sem.acquire()
            db[token][key]=val
            sem.release()
            client_socket.send("ack".encode())

        elif (query[0]=="get"):
            key=query[1]
            if(len(query)==2):
                #guest
                if key in db[token]:
                    client_socket.send(db[token][key].encode())
                else:
                    client_socket.send("<blank>".encode())
            else:
                #manage
                data=list()
                for it in db:
                    if(key in db[it]):
                        data.append((it,db[it][key]))
                if len(data)!=0:
                    client_socket.send(str(data).encode())
                else:
                    client_socket.send("<blank>".encode())




while True:
    print("\n\nWaiting for connections....\n\n")
    client_socket,client_address=server_socket.accept()
    print(f"connected to client {client_address}")
    #unique toke for each connection
    token=client_address[0]+":"+str(client_address[1])
    # print(f"token {token}")
    threading.Thread(target=handleClient,args=(client_socket,token)).start()
    