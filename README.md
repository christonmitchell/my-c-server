# TCP Server in C

A simple TCP server implementation in C that listens for incoming connections on port 8080.

## 📌 Overview
This program demonstrates the basic setup of a TCP server in C using socket programming. It:
✅ Creates a TCP/IPv4 socket  
✅ Binds the socket to port 8080  
✅ Listens for incoming connections (but does not yet accept them)  

## 🚀 Features
- **IPv4 support** (`AF_INET`)
- **TCP protocol** (`SOCK_STREAM`)
- **Port 8080** (configurable via `#define PORT`)
- Handles socket creation, binding, and listening
- Error handling for socket, bind, and listen failures

## ⚙️ How It Works
1. **Creates a socket**
   - Uses `socket(AF_INET, SOCK_STREAM, 0)`
   - Exits if socket creation fails

2. **Configures the server address**
   - Binds to all available network interfaces (`INADDR_ANY`)
   - Converts port to network byte order (`htons(PORT)`)

3. **Binds the socket to the port**
   - Uses `bind()` to attach the socket to the specified port
   - Exits if binding fails

4. **Listens for incoming connections**
   - Uses `listen()` with a backlog of 10 pending connections
   - Exits if listening fails

5. **Prints a success message**
   - Outputs: `"Server is listening on port 8080"`

## 🔧 Future Improvements
- Accepting client connections (`accept()`)
- Handling client requests (`read()`, `write()`)
- Multi-threading for handling multiple clients
- Graceful shutdown (`close()`, `shutdown()`)

## 📝 Usage
### Compile & Run
```sh
gcc server.c -o server && ./server
