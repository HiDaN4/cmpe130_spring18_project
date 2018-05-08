// Currency.h
// Currency Class Implementation
// Author: Antonio G. Bares Jr.

#include "Currency.h"

// Constructor
Currency::Currency(const std::string& name, const std::string& symbol) : name(name), symbol(symbol)
{
}

// Getters
std::string Currency::getName() const
{
    return name;
}

std::string Currency::getSymbol() const
{
    return symbol;
}

// Operator Overload
bool Currency::operator==(const Currency& lhs)
{
    return this->symbol == lhs.symbol;
} 

std::ostream& operator<< (std::ostream& stream, const Currency& currency)
{
    stream << "Name: " << currency.getName() << " Symbol: " << currency.getSymbol();
    return stream;
}