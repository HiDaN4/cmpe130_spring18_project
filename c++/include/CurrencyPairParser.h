// CurrencyPairParser.h
// CurrencyPairParser Class Specification
// Author: Antonio G. Bares Jr.

#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>

#include "CurrencyPair.h"

#ifndef CURRENCYPAIRPARSER_H
#define CURRENCYPAIRPARSER_H

class CurrencyPairParser {
private:
    // Utilities
    CurrencyPair parseLine(const std::string&);

public:
    // Default Constructor (nothing to initialize)
    CurrencyPairParser() = default;

    // Default Destructor (nothing to deallocate)
    ~CurrencyPairParser() = default;

    std::list<CurrencyPair> parseFileAndGetListOfCurrencies(const std::string&);

};

#endif