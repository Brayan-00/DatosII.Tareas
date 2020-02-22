//
// Created by brayanrv on 21/2/20.
//

#include "Grafo.h"
#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int src, dest;
};

class Graph {
public:

    //Se crea la lista de adyacencia, es decir que se crea una lista que contiene todas las conexiones que posee cada nodo
    vector<vector<int>> listadj;


    //Constructor del Grafo
    Graph(vector<Edge> const &edges, int N) {

        //Se ajusta el tamaño de la lista de adyacencia para que sea de tamaño N
        listadj.resize(N);
        // Se añadirán los edge al grafo
        for (auto &edge: edges) {
            // insert at the end
            listadj[edge.src].push_back(edge.dest);
        }

    }

    // print adjacency list representation of graph
    void printGraph(Graph const &graph, int N) {
        for (int i = 0; i < N; i++) {
            // print current vertex number
            cout << i << " --> ";

            // print all neighboring vertices of vertex i
            for (int v : graph.listadj[i])
                cout << v << " ";
            cout << endl;
        }
    }


};


int main() {
    // vector of graph edges as per above diagram.
    // Please note that initialization vector in below format will
    // work fine in C++11, C++14, C++17 but will fail in C++98.
    vector<Edge> edges =
            {
                    {0, 1},
                    {1, 2},
                    {2, 0},
                    {2, 1},
                    {3, 2},
                    {4, 5},
                    {5, 4}
            };

    // Number of nodes in the graph
    int N = 6;

    // construct graph
    Graph graph(edges, N);

    // print adjacency list representation of graph
    graph.printGraph(graph, N);

    return 0;
}
