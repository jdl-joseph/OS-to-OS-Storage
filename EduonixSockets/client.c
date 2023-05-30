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

    // specifying a socket address
    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(5555);
    saddr.sin_addr.s_addr = INADDR_ANY;

    // connecting to the server
    int conn_status = connect(sock, (struct sockaddr *) &saddr, sizeof(saddr));
    if(conn_status == -1) printf("There was a problem connecting to the server"); close(sock);

    // receiving data from the server
    char response[256];
    recv(sock, &response, sizeof(response), 0);

    printf("[SERVER] %s\n", response);
    close(sock);

    return 0;
}
