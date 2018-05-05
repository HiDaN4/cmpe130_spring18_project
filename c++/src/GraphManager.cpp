//
// Created by Dmitry Sokolov on 4/4/18.
//

#include <utility>
#include <queue>
#include <limits>
#include <unordered_map>

#include "../include/GraphManager.h"
#include "../include/CurrencyPairParser.h"

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

std::list<CurrencyPair> GraphManager::findBestExchangeRoute(const std::string fromCurrency, const std::string toCurrency) const {
    // stub
    // TODO: implement
    //    auto value_type = graph->getType();
    typedef std::pair<double, std::string> graphPair;
    typedef std::vector<CurrencyPair> currencyPairVector;

    int vertices = graph->getNumberOfVertices();
    double dist[vertices][vertices];

    for (int i = 0; i < vertices; ++i) {

    }

    std::priority_queue<graphPair, std::vector<graphPair>, std::greater<> > priorityQueue;

//    std::vector<graphPair> dist(graph->getNumberOfVertices(), std::make_pair(std::numeric_limits<double >::max(), ""));

    std::unordered_map< std::string, std::list<CurrencyPair> > hashTable(graph->getNumberOfVertices());

    priorityQueue.push(std::make_pair(0.0, fromCurrency));

    hashTable[fromCurrency] = std::list<CurrencyPair>();
    hashTable[fromCurrency].push_back(CurrencyPair(fromCurrency, fromCurrency, 0.0));

    auto mlist = hashTable[fromCurrency];
    for (auto &it : mlist) {
        std:cout << it << "\n";
    }


    return std::list<CurrencyPair>();
}
