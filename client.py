import socket
ip = "127.0.0.1"
port = 1234

server = socket.socket()
server.connect((ip, port))

string = input("Enter string: ")
server.send(bytes(string,"utf-8"))
buffer = server.recv(1024)
buffer = buffer.decode("utf-8")
print(f"server: {buffer}")