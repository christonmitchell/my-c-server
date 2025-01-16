#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>  // Required for htons and INADDR_ANY

#define PORT 8080  // Define port number

int main() {
    int server_fd;
    struct sockaddr_in server_addr;

    // Create a server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    /* AF_INET = IPV4
       SOCK_STREAM = TCP
       0 = Default protocol (usually TCP for SOCK_STREAM) */

    // Configure socket
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;  // Accepts connections from any network interfaces
    server_addr.sin_port = htons(PORT);        // Port number, converted to network byte order

    // Bind socket to port 8080
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 10) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // Maximum number of pending connections set to 10 to make it more manageable
    printf("Server is listening on port %d\n", PORT);
    return 0;
}
