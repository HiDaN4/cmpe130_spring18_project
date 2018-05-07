//
// Created by Dmitry Sokolov on 4/4/18.
//

#include <utility>
#include <queue>
#include <limits>
#include <unordered_map>
#include <stack>

#include "../include/GraphManager.h"
#include "../include/CurrencyPairParser.h"
#include "UndirectedMatrixGraph.h"

GraphManager::GraphManager(const std::string nameOfExchange, Graph<std::string> *graph, CurrencyPairParser* pairParser):
        nameOfExchange(nameOfExchange), lastUpdateTimestamp(0), graph(graph), parser(pairParser)
{
}

std::string GraphManager::getNameOfExchange() const {
    return nameOfExchange;
}

unsigned int GraphManager::getLastUpdateTimestamp() const {
    return lastUpdateTimestamp;
}


void GraphManager::updateGraph(const std::string fileName) {

    // call the parser to obtain the list of currencyPairs
    std::list<CurrencyPair> pairs = parser->parseFileAndGetListOfCurrencies(fileName);

    // check for result size
    if (pairs.empty()) {
        std::cout << "No currency pairs were found in the file '" << fileName << "'\n";
        return;
    }

    // reset the contents of the graph
    graph->reset();

    // temp values to store parsed symbols
    std::string fromSymbol;
    std::string toSymbol;

    for (auto& pair: pairs) {
        // get the values from the pair
        fromSymbol = pair.getFromSymbol();
        toSymbol = pair.getToSymbol();

        // update the graph
        graph->addVertex(fromSymbol);
        graph->addVertex(toSymbol);
        graph->addEdge(fromSymbol, toSymbol, pair.getPrice());
    }

}


void logStack(std::stack<std::string>& stack) {
    if (stack.empty()) return;

    std::cout << "Printing Stack:\n";
    while (!stack.empty()) {
        std::cout << stack.top() << " ";
        stack.pop();
    }
    std::cout << "\n";
}



std::list<CurrencyPair> GraphManager::findBestExchangeRoute(const std::string fromCurrency, const std::string toCurrency) const {

    std::list<CurrencyPair, std::allocator<CurrencyPair>> listOfPairs = std::list<CurrencyPair>();

    if (auto * matrixGraph = dynamic_cast<UndirectedMatrixGraph<std::string>*>(graph.get())) {
//        auto rows = matrixGraph->getMatrixIteratorBegin();
//        auto verticesList = matrixGraph->getVertexList();
//        int V = matrixGraph->getNumberOfVertices();
        auto dists = matrixGraph->computeShortestDistanceBetweenVertices(fromCurrency, toCurrency);

        if (!dists.empty()) {
            std::cout << "\nPairs:\n";
            for (auto& pair : dists)
                std::cout << pair;
            std::cout << "\n";
        } else {
            std::cout << "No path found!\n";
        }

    }


    return listOfPairs;
}

