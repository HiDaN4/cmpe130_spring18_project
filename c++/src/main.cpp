#include <iostream>
#include "Graph.h"
#include "UndirectedMatrixGraph.h"
#include "DirectedMatrixGraph.h"

#include "UndirectedListGraph.h"
#include "DirectedListGraph.h"
#include<vector>
using namespace std;

int main()
{
    //Graph<string> * graph1 = new UndirectedListGraph<string>();
    Graph<string> * graph2 = new DirectedListGraph<string>();

    UndirectedMatrixGraph<string> * graph1 = new UndirectedMatrixGraph<string>();

    graph1->addVertex("BTC");
    graph1->addVertex("XRP");
    graph1->addVertex("BYTE");
    graph1->addVertex("BTCN");

    graph1->addEdge("BTC", "XRP", 5);
    graph1->addEdge("BTC", "BTCN", 15);
    graph1->addEdge("BTC", "BYTE", 10);
    graph1->addEdge("BYTE", "XRP", 20);

    cout << graph1->toString();
    auto res = graph1->getNeighbors("BTCNs");


    for (auto it = res.begin(); it != res.end(); ++it) {
        cout << *it << "\n";
    }

//    cout << graph1->toString();


//    graph2->addVertex("BTC");
//    graph2->addVertex("XRP");
//    graph2->addVertex("BYTE");
//    graph2->addVertex("BTCN");
//
//    graph2->addEdge("BTC", "XRP", 5);
//    graph2->addEdge("BTC", "BTCN", 15);
//    graph2->addEdge("BTC", "BYTE", 10);
//    graph2->addEdge("BYTE", "XRP", 20);
//    cout << graph2->toString();
//
//    graph2->removeEdge("BTC", "XRP");
//    cout << "\n***\n" << graph2->toString() ;
//
//    graph2->removeEdge("XRP", "BTC");
//    cout << "\n***\n" << graph2->toString() ;

    return 0;
}
