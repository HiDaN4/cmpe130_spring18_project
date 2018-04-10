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
    graph1->addVertex("BYTE");
    graph1->addVertex("BTCN");
    graph1->addEdge("BTC", "XRP", 5);
    graph1->addEdge("BTC", "BTCN", 15);
    graph1->addEdge("BTC", "BYTE", 10);
    graph1->addEdge("BYTE", "XRP", 20);


    std::cout << graph1->toString();
    graph1->removeEdge("BTC", "BYTE");
    graph1->removeVertex("XRP");
    std::cout << graph1->toString();
    graph1->removeEdge("BTC", "XRP");
    std::cout << graph1->toString();


//    graph2->addVertex("V1");
//    graph2->addVertex("V2");
//    graph2->addVertex("V3");
//    graph2->addVertex("V4");
//
//    graph2->addEdge("V1", "V3", 5);
//    graph2->addEdge("V1", "V4", 15);
//    graph2->addEdge("V3", "V2", 69);
//
//    cout << graph2->toString();
//
//    cout << "\nRemoving edge V1-V3\n";
//    graph2->removeEdge("V1", "V3");
//    graph2->removeVertex("V1");
//    graph2->removeVertex("V2");
//    graph2->addVertex("V2");graph2->addVertex("V2");
//    cout << graph2->toString();

    return 0;
}
