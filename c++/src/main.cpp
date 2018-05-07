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
    auto * graph = new DirectedMatrixGraph<std::string>();

//    graph->addVertex("BTC");
//    graph->addVertex("XRP");
//    graph->addVertex("BYTE");
//    graph->addVertex("BTCN");
//
//    graph->addEdge("BTC", "XRP", 5);
//    graph->addEdge("BTC", "BTCN", 19);
//    graph->addEdge("XRP", "BYTE", 10);
//    graph->addEdge("BYTE", "BTC", 20);



    GraphManager manager("Best Exchange Co.", graph, new CurrencyPairParser());
    manager.updateGraph("test.csv");


    std::cout << "Printing the graph...\n";
    std::cout << graph->toString();

    manager.findBestExchangeRoute("BTC", "ETH");

    return 0;
}
