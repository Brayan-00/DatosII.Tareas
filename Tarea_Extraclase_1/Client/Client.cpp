// Client side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "Data.cpp"

#define PORT 8080


int main(int argc, char const *argv[]) {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    Data *new_value = new Data(const_cast<char *>("{0, 1},\n""{1, 2},\n"
                                                  "{2, 0},\n"
                                                  "{2, 1},\n"
                                                  "{3, 2},\n"
                                                  "{4, 5},\n"
                                                  "{5, 4}"), const_cast<char *>("{1,5}"));
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    bzero(buffer, sizeof(buffer));
    send(sock, new_value->get_graph(), strlen(new_value->get_graph()), 0);
    printf("Graph sent\n");
    valread = read(sock, buffer, 1024);
    printf("%s\n", buffer);
    bzero(buffer, sizeof(buffer));
    send(sock, new_value->get_bestRoute(), strlen(new_value->get_bestRoute()), 0);
    printf("Best route requested\n");
    valread = read(sock, buffer, 1024);
    printf("%s", buffer);
    bzero(buffer, sizeof(buffer));


    return 0;
}



