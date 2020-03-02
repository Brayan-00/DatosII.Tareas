
#include <unistd.h>
#include <cstdio>
#include <sys/socket.h>
#include <cstdlib>
#include <netinet/in.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include "Data.cpp"


using namespace std;


#define PORT 8080


int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    bool finish = false;
    int process = 0;
    Data *data = new Data();

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *) &address, (socklen_t *) &addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }


    char *inicio = "Solicitando información del grafo...\n";
    char *algoritmo = "Solicitando información sobre la ruta más corta...\n";
    while (!finish) {
        bzero(buffer, sizeof(buffer));
        if (process == 0) {
            send(new_socket, inicio, strlen(inicio), 0);
            valread = read(new_socket, buffer, 1024);
            data->set_graph(buffer);
            data->writeTxt();
            cout << '\n' << "El grafo es: \n" << data->get_graph() << endl;
            process++;


        } else if (process == 1) {
            send(new_socket, algoritmo, strlen(algoritmo), 0);
            valread = read(new_socket, buffer, 1024);
            data->set_bestRoute(buffer);
            data->writeTxt();
            cout << '\n' << "La solicitud es : \n" << data->get_bestRoute() << endl;
            process = 0;
            finish = true;
        }

    }
    data->printTxt();
    return 0;
}