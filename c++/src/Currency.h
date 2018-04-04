// Currency.h
// Currency Class Specification
// Author: Antonio G. Bares Jr.

#include <string>

#ifndef CURRENCY_H
#define CURRENCY_H

class Currency {
private:
    std::string name;
    std::string symbol;

public:
    // Constructor
    Currency(const std::string&);

    // Getters
    std::string getName() const;
    std::string getSymbol() const;

    // Operator Overload
    bool operator== (const Currency&)
};

#endif