#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>


int main() {
    char server_message[256] = "You have reached the server";

    int sock;
    sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(5555);
    saddr.sin_addr.s_addr = INADDR_ANY;

    bind(sock, (struct sockaddr*) &saddr, sizeof(saddr));
    listen(sock, 5);

    int csock;
    csock = accept(sock, NULL, NULL);
    send(csock, server_message, sizeof(server_message), 0);
    close(sock);

    return 0;
}
