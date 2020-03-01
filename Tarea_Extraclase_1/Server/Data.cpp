//
// Created by brayanrv on 1/3/20.
//
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


class Data{
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
    Data(char* graph, char* bestRoute){
        new_value.graph = graph;
        new_value.bestRoute = bestRoute;
        ofstream file;
        file.open("serverData.txt");
        if(file.is_open()){
            file << graph;
            file.close();
        }else{
            cout<<"ERROR: No se pudo abrir txt del servidor"<<endl;
        }

    }
    Data(){

    }
    char* get_graph(){
        return new_value.graph;
    }
    char* get_bestRoute(){
        return new_value.graph;
    }
    void set_graph(char* graph){
        fstream file;
        file.open("serverData.txt", ios::out | ios::trunc);
        if (file.is_open()) {
            file << graph;
            file.close();
        }else{
            cout<<"ERROR: No se pudo abrir txt del server"<<endl;
        }
        new_value.graph = graph;
    }
    void set_bestRoute(char* bestRoute){
        new_value.bestRoute = bestRoute;
    }
};