import socket
ip = "127.0.0.1"
port = 1234

server = socket.socket()
server.bind((ip,port))
server.listen(5)

while True:
    client, address = server.accept()
    print(f"Connection Established - {address[0]}:{address[1]}")

    string = client.recv(1024)
    string = string.decode("utf-8")
    string = string.upper()
    client.send(bytes(string,"utf-8"))

    client.close()