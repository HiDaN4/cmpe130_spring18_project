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
        nameOfExchange(nameOfExchange), graph(graph), parser(pairParser) { }


/*! getNameOfExchange
 *
 * @return - string name of the exchange that is associated with this graph manager
 */
std::string GraphManager::getNameOfExchange() const {
    return nameOfExchange;
}



/*! updateGraph - populate graph with data from given data
 *
 * @param fileName - file with data in format "from,to,price"
 */
void GraphManager::updateGraph(const std::string fileName) {

    // call the parser to obtain the list of currencyPairs
    std::list<CurrencyPair> pairs = parser->parseFileAndGetListOfCurrencies(fileName);

    // check for result size
    if (pairs.empty()) {
        std::cout << "No currency pairs were found in the file '" << fileName << "'\n";
        return;
    }

    // if for the first time graph is empty, we will need to add vertices while parsing pairs
    bool shouldAddVertices = graph->isEmpty();

    // temp values to store parsed symbols
    std::string fromSymbol;
    std::string toSymbol;
    double price;

    for (auto& pair: pairs) {
        // get the values from the pair
        fromSymbol = pair.getFromSymbol();
        toSymbol = pair.getToSymbol();
        price = pair.getPrice();

        // update the graph
        if (shouldAddVertices) {
            graph->addVertex(fromSymbol);
            graph->addVertex(toSymbol);
        }

        if (fromSymbol == "USD" && toSymbol == "ZEC") {
            std::cout << "";
        }

        graph->addEdge(fromSymbol, toSymbol, price);
        graph->addEdge(toSymbol, fromSymbol, 1.0/price);
    }
}



/*! findBestExchangeRoute - return a list with optimal currency pairs to exchange 'fromCurrency' to 'toCurrency'
 *
 * @param fromCurrency - symbol name of currency to exchange from
 * @param toCurrency - symbol name of currency to exchange to
 * @return - the list of optimal currency pairs that will result in least amount of fees. If no pairs found, return empty list
 */
std::list<CurrencyPair> GraphManager::findBestExchangeRoute(const std::string fromCurrency, const std::string toCurrency) const {
    std::list<CurrencyPair> pairs = graph->getShortestPairsBetween(fromCurrency, toCurrency);

//    pairs = graph->computeShortestDistanceBetweenVertices(fromCurrency, toCurrency);

    if (!pairs.empty()) {
        std::cout << "\nPairs:\n";
        for (auto& pair : pairs)
            std::cout << pair;
        std::cout << "\n";
    } else {
        std::cout << "No pairs found!\n";
    }

    return pairs;
}

