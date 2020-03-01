
#include <unistd.h>
#include <cstdio>
#include <sys/socket.h>
#include <cstdlib>
#include <netinet/in.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include "../../Library/rapidjson/document.h"
#include "../../Library/rapidjson/writer.h"
#include "../../Library/rapidjson/stringbuffer.h"
#include "Json.h"

using namespace std;
using namespace rapidjson;


#define PORT 8080

string data_temp;
string data[2048];


void turntostring(){
    ifstream file("graph_data.txt");
    if (file.is_open()){
        while(file.good()){
            getline(file, data_temp);
            file.close();
            data->append(data_temp, data_temp.length());
            cout << "This is the data: " << data << endl;
        }
    }
}



int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    const char *json = "{\"project\":\"rapidjson\",\"stars\":10}";
    Document d;
    d.Parse(json);


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


    turntostring();
    send(new_socket, d, 2048, 0);
    printf("Data sent\n");

    valread = read(new_socket, data, 2048);
    cout << &data << endl;

    return 0;

}



