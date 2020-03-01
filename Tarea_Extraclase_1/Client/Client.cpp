
#include <cstdio>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

#define PORT 8080

string data_temp;
string data[2048];


void turntostring() {
    ifstream file("graph_data.txt");
    if (file.is_open()) {
        while (file.good()) {
            getline(file, data_temp);
            file.close();
            data->append(data_temp, data_temp.length());
        }
    }

}

int main(int argc, char const *argv[]) {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
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
    //turntostring();
    //send(sock, buffer, data.length(), 0);
    //printf("Data sent\n");
    valread = read(sock, data, 1024);
    cout << &data << endl;
    return 0;
}





