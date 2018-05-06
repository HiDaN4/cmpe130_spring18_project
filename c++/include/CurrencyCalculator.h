//
// Created by Dmitry Sokolov on 4/4/18.
//

#ifndef KRYPTOS_CURRENCYCALCULATOR_H
#define KRYPTOS_CURRENCYCALCULATOR_H

#include <list>

class CurrencyPair;

class CurrencyCalculator {
private:
    static CurrencyCalculator* s_instance;

    CurrencyCalculator() = default; // default constructor
    CurrencyCalculator(const CurrencyCalculator&) = default; // copy constructor
    CurrencyCalculator&operator=(const CurrencyCalculator&) = default; // operator assignment
public:

    // singleton shared instance
    static CurrencyCalculator* sharedInstance(); // usage: CurrencyCalculator::sharedInstance()

    double calculateTotalResultForListOfPairs(const std::list<CurrencyPair>& route, double numberOfCoins);

};


#endif //KRYPTOS_CURRENCYCALCULATOR_H
