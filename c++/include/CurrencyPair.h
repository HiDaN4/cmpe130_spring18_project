// CurrencyPair.h
// CurrencyPair Class Specification
// Author: Antonio G. Bares Jr.

#ifndef KRYPTOS_CURRENCYPAIR_H
#define KRYPTOS_CURRENCYPAIR_H

#include <string>
#include <iostream>

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
    friend std::ostream& operator<<(std::ostream&, const CurrencyPair& obj);
};


#endif  // KRYPTOS_CURRENCYPAIR_H