// Currency.h
// Currency Class Specification
// Author: Antonio G. Bares Jr.

#ifndef CURRENCY_H
#define CURRENCY_H

#include <string>
#include <ostream>

class Currency {
private:
    std::string name;
    std::string symbol;

public:
    // Constructor
    Currency(const std::string&, const std::string&);

    // Getters
    std::string getName() const;
    std::string getSymbol() const;

    // Operator Overload
    bool operator== (const Currency&);
    friend std::ostream& operator<< (std::ostream&, const Currency&);
};

#endif