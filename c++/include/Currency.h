// Currency.h
// Currency Class Specification
// Author: Antonio G. Bares Jr.

#ifndef KRYPTOS_CURRENCY_H
#define KRYPTOS_CURRENCY_H

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

#endif  // KRYPTOS_CURRENCY_H