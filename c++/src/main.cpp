// std
#include <iostream>
#include<vector>

// custom classes
#include "Graph.h"
#include "UndirectedMatrixGraph.h"
#include "DirectedMatrixGraph.h"
#include "CurrencyPairParser.h"
#include "GraphManager.h"


const std::string kInputFilename = "new.csv";


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

    // construct the manager that we use throughout the program
    GraphManager manager("Best Exchange Co.", graph, new CurrencyPairParser());

    // make a graph from file
    manager.updateGraph(kInputFilename);

    std::cout << "Printing the graph...\n";
    std::cout << graph->toString();

    manager.findBestExchangeRoute("ZEC", "TIME");

    return 0;
}
