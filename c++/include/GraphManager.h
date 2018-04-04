//
// Created by Dmitry Sokolov on 4/4/18.
//

#ifndef KRYPTOS_GRAPHMANAGER_H
#define KRYPTOS_GRAPHMANAGER_H

#include <string>
#include <list>

class Graph;
class CurrencyPair;
class CurrencyPairParser;

class GraphManager {
private:
    const std::string nameOfExchange;
    unsigned int lastUpdateTimestamp;
    std::unique_ptr<Graph> graph;
    std::unique_ptr<CurrencyPairParser> parser;

public:
    // Constructor
    GraphManager(std::string nameOfExchange, Graph* graph, CurrencyPairParser* parser);

    // Getters
    std::string getNameOfExchange() const;
    unsigned int getLastUpdateTimestamp() const;

    // Methods
    void updateGraph(std::string fileName);
    std::list<CurrencyPair> findBestExchangeRoute(std::string fromCurrency, std::string toCurrency) const;

};


#endif //KRYPTOS_GRAPHMANAGER_H
