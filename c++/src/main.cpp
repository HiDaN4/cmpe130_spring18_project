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


    Graph<string> * graph1 = new UndirectedMatrixGraph<string>();
    Graph<string> * graph2 = new UndirectedListGraph<string>();

    graph1->addVertex("BTC");
    graph1->addVertex("XRP");
    graph1->addVertex("BTCN");
    graph1->addVertex("RR");
    std::cout << graph1->toString();

    graph2->addVertex("V1");
    graph2->addVertex("V2");
    graph2->addVertex("V3");
    graph2->addVertex("V4");

    graph2->addEdge("V1", "V3", 5);
    graph2->addEdge("V1", "V4", 15);
    graph2->addEdge("V3", "V2", 69);

    cout << graph2->toString();

    cout << "\nRemoving edge V1-V3\n";
    graph2->removeEdge("V1", "V3");

    cout << graph2->toString();


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
