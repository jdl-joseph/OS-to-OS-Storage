#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>


int main() {
    // creating socket
    int sock;
    sock = socket(AF_INET, SOCK_STREAM, 0);

    // specifying an address
    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(5555);
    saddr.sin_addr.s_addr = INADDR_ANY; // specifies localhost, 0.0.0.0

    int conn = connect(sock, (struct sockaddr*) &saddr, sizeof(saddr));
    if (conn == -1) printf("Something went wrong.");

    char response[256];
    recv(sock, response, sizeof(response), 0);
    
    printf("The server sent a message: %s", response);
    close(sock);

    return 0;
}
