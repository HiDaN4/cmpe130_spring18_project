//
// Created by Dmitry Sokolov on 4/4/18.
//

#include <utility>

#include "../include/GraphManager.h"
#include "../include/CurrencyPairParser.h"

GraphManager::GraphManager(const std::string nameOfExchange, Graph *graph, CurrencyPairParser *parser):
        nameOfExchange(std::move(nameOfExchange)), lastUpdateTimestamp(0), graph(graph), parser(parser)
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
    return std::list<CurrencyPair>();
}
