//
// Created by Dmitry Sokolov on 4/4/18.
//

#ifndef KRYPTOS_GRAPHMANAGER_H
#define KRYPTOS_GRAPHMANAGER_H

#include <string>
#include <list>
#include <iostream>

#include "../include/Graph.h"
#include "../include/CurrencyPair.h"

class CurrencyPairParser;

class GraphManager {
private:
    const std::string nameOfExchange;
    std::unique_ptr<Graph<std::string>> graph;
    std::unique_ptr<CurrencyPairParser> parser;

public:
    // Constructor
    GraphManager(std::string nameOfExchange, Graph<std::string>* graph, CurrencyPairParser* pairParser);

    // Getters
    std::string getNameOfExchange() const;


    /*! updateGraph - populate graph with data from given data
     *
     * @param fileName - file with data in format "from,to,price"
     */
    void updateGraph(std::string fileName);



    /*! findBestExchangeRoute - return a list with optimal currency pairs to exchange 'fromCurrency' to 'toCurrency'
     *
     * @param fromCurrency - symbol name of currency to exchange from
     * @param toCurrency - symbol name of currency to exchange to
     * @return - the list of optimal currency pairs that will result in least amount of fees. If no pairs found, return empty list
     */
    std::list<CurrencyPair> findBestExchangeRoute(std::string fromCurrency, std::string toCurrency) const;



    /*! getCostForExchange - return the cost of exchanging 2 currencies
     *
     * @param fromCurrency - source currency
     * @param toCurrency - destination currency
     * @return - double cost of exchanging 2 given currencies. If there is no cost in the graph for these currencies,
     *          return 0.
     */
    double getCostForExchange(std::string fromCurrency, std::string toCurrency) const;

};


#endif //KRYPTOS_GRAPHMANAGER_H
