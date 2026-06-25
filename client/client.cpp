#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    const char* msg = "Hello from C++ client";
    sendto(sockfd, msg, strlen(msg), 0, (struct sockaddr*)&server_addr, sizeof(server_addr));

    char buffer[1024];
    socklen_t len = sizeof(server_addr);
    int n = recvfrom(sockfd, buffer, sizeof(buffer) - 1, 0, (struct sockaddr*)&server_addr, &len);
    buffer[n] = '\0';
    std::cout << "Received: " << buffer << std::endl;
    close(sockfd);
    return 0;
}