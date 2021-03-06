// CurrencyPair.cpp
// CurrencyPair Class Implementation
// Author: Antonio G. Bares Jr.

#include "CurrencyPair.h"

// Constructor
CurrencyPair::CurrencyPair(const std::string& from, const std::string& to, const double price) : from(from), to(to), price(price), symbol(from + to)
{
}

// Getters
std::string CurrencyPair::getSymbol() const
{
    return symbol;
}

std::string CurrencyPair::getFromSymbol() const
{
    return from;
}

std::string CurrencyPair::getToSymbol() const
{
    return to;
}

double CurrencyPair::getPrice() const
{
    return price;
}


std::ostream& operator<<(std::ostream& ostream, const CurrencyPair& obj) {
    ostream << obj.getFromSymbol() << " - " << obj.getToSymbol() << " [" << obj.getPrice() << "]\n";
    return ostream;
}