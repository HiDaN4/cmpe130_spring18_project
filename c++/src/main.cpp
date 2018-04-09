#include <iostream>
#include "Graph.h"
#include "UndirectedMatrixGraph.h"
#include "UndirectedListGraph.h"
#include<vector>
using namespace std;

int main()
{

    Vertex<string> *v1 = new Vertex<string>("V1");
    Vertex<string> *v2 = new Vertex<string>("V2");
    Vertex<string> *v3 = new Vertex<string>("V3");
    Vertex<string> *v4 = new Vertex<string>("v4");


    Graph<string> * graph1 = new UndirectedMatrixGraph<string>(11);

    graph1->addVertex("V1");
    graph1->addVertex("V2");
    graph1->addVertex("V3");
    std::cout << graph1->toString();

//    UndirectedListGraph<string> adjList(15);
//    UndirectedMatrixGraph<string> g(12);
//    graph1 = &g;
//    graph1 = &adjList;

//
//    graph1->addVertex(v1);
//    graph1->addVertex(v2);
//    graph1->addVertex(v3);
//    graph1->addVertex(v4);
//    graph1->removeVertex(v2);
//
//    graph1->addEdge(v1, v2,2);
//    graph1->addEdge(v1,v4,4);
//    graph1->display();

    return 0;
}
