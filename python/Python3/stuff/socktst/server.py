import socket
serverSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

serverSocket.bind((socket.gethostname(), 5555))

serverSocket.listen(4)

while True:
    (clientSocket, address) = serverSocket.accept()
    print(clientSocket)
    print(address)
    
