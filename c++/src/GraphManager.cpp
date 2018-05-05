//
// Created by Dmitry Sokolov on 4/4/18.
//

#include <utility>
#include <queue>
#include <limits>
#include <unordered_map>

#include "../include/GraphManager.h"
#include "../include/CurrencyPairParser.h"

GraphManager::GraphManager(const std::string nameOfExchange, Graph<std::string> *graph):
        nameOfExchange(std::move(nameOfExchange)), lastUpdateTimestamp(0), graph(graph)
{
}

std::string GraphManager::getNameOfExchange() const {
    return nameOfExchange;
}

unsigned int GraphManager::getLastUpdateTimestamp() const {
    return lastUpdateTimestamp;
}

void GraphManager::updateGraph(const std::string fileName) {
    // stub
    // TODO: implement
}

std::list<CurrencyPair>
GraphManager::findBestExchangeRoute(const std::string fromCurrency, const std::string toCurrency) const {
    // stub
    // TODO: implement
//    auto value_type = graph->getType();
    typedef std::pair<double, std::string> graphPair;

    std::priority_queue<graphPair, std::vector<graphPair>, std::greater<> > priorityQueue;

    std::vector<graphPair> dist(graph->getNumberOfVertices(), std::make_pair(std::numeric_limits<double >::max(), ""));

    std::unordered_map< std::string, std::list<CurrencyPair> > hashTable(graph->getNumberOfVertices());

    priorityQueue.push(std::make_pair(0.0, fromCurrency));

    hashTable[fromCurrency] = std::list<CurrencyPair>();
    hashTable[fromCurrency].push_back(CurrencyPair(fromCurrency, fromCurrency, 0.0));

    auto mlist = hashTable[fromCurrency];
    for (auto it = mlist.begin(); it != mlist.end(); ++it) {
        std:cout << *it << "\n";
    }


    return std::list<CurrencyPair>();
}
