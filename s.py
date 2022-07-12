import socket
server = socket.socket()
server.bind(("127.0.0.1",1234))
server.listen(5)

while True:
    client, address = server.accept()
    print(f"Server listening on address: {address}")

    string  = client.recv(1024)
    string  = string.decode("utf-8")
    string  = string.upper();
    client.send(bytes(string,"utf-8"))
    client.close()