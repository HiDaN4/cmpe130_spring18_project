// CurrencyPair.h
// CurrencyPair Class Specification
// Author: Antonio G. Bares Jr.

#include <string>

#ifndef CURRENCYPAIR_H
#define CURRENCYPAIR_H

class CurrencyPair {
private:
    std::string symbol;
    std::string from;
    std::string to;
    double price;

public:
    // Constructor
    CurrencyPair(const std::string&, const std::string&, const double);


    // Getters
    std::string getSymbol() const;
    std::string getFromSymbol() const;
    std::string getToSymbol() const;
    double getPrice() const;
};

#endif