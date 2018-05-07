#include <iostream>
#include<vector>


#include "Graph.h"
#include "UndirectedMatrixGraph.h"
#include "DirectedMatrixGraph.h"

#include "UndirectedListGraph.h"
#include "DirectedListGraph.h"
#include "CurrencyPairParser.h"

#include "GraphManager.h"

int main()
{
    DirectedMatrixGraph<std::string> * graph1 = new DirectedMatrixGraph<std::string>();

    graph1->addVertex("BTC");
    graph1->addVertex("XRP");
    graph1->addVertex("BYTE");
    graph1->addVertex("BTCN");

    graph1->addEdge("BTC", "XRP", 5);
    graph1->addEdge("BTC", "BTCN", 19);
    graph1->addEdge("XRP", "BYTE", 10);
    graph1->addEdge("BYTE", "BTC", 20);

    std::cout << "Printing the graph...\n";
    std::cout << graph1->toString();

    GraphManager manager("Best Exchange Co.", graph1, new CurrencyPairParser());

    manager.findBestExchangeRoute("BTC", "BYTE");

    return 0;
}
