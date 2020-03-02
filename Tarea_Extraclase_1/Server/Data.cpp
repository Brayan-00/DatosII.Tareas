//
// Created by brayanrv on 1/3/20.
//
#include <string>
#include <iostream>
#include <fstream>
#include "Dijsktra.cpp"
using namespace std;


class Data{
    int MAXSIZE;

    struct data{
        char* graph;
        char* bestRoute;
    } new_value;
public:
    /**
     * Se inicializa el struct que almacena los datos que serán enviados mediante el socket hacia el server
     * graph es un string que almacena todos los nodos que serán utilizados para crear el grafo
     * Tiene formato {a,b},\n {c,d}...
     * @param graph
     * bestRoute es un string que contiene los nodos a los cuales se les quiere aplicar el algoritmo para encontrar la ruta más corta
     * Tiene formato {x,y}
     * @param bestRoute
     **/
    Data(char* graph, char* bestRoute, int MAXSIZE){
        new_value.graph = graph;
        new_value.bestRoute = bestRoute;
        MAXSIZE = MAXSIZE;
    }

    Data() {

    }

    char *get_graph() {
        return new_value.graph;
    }

    char *get_bestRoute() {
        return new_value.graph;
    }

    void set_graph(char *graph) {
        new_value.graph = graph;
    }

    void set_bestRoute(char *bestRoute) {
        new_value.bestRoute = bestRoute;
    }

    int getMaxsize() const {
        return MAXSIZE;
    }

    void setMaxsize(int maxsize) {
        MAXSIZE = maxsize;
    }

    void writeTxt() {
        ofstream file;
        file.open("serverData.txt", ios::out | ios::trunc);
        if (file.is_open()) {
            file << string(this->get_graph());
            file.close();
        } else {
            cout << "ERROR: No se pudo abrir txt del server" << endl;
        }
    }

    void printTxt() {
        ifstream file;
        file.open("serverData.txt", ios::in);
        char output[100];
        while (!file.eof()) {
            file.getline(output, 100);
            cout << output << endl;
        }
        file.close();
    }



};
int askDijsktra(Data *data , Graph graph){
    char* bestRoute = data->get_bestRoute();
    return graph.shortestPath((int)bestRoute[1]-48,(int)bestRoute[3]-48);
}



void buildGraph(Graph g,int SIZE) {
    ifstream file;
    file.open("serverData.txt");
    int u, v, w;
    char line[5];
    while(file.good()){
        file >> line;
        u = (int)line[1]-48;
        v = (int)line[3]-48;
        w = (rand() %  SIZE == (u || v)) ? 0 : rand() % 20;
        g.addEdge(u,v,w);

    }



}


