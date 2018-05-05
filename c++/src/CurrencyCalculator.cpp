//
// Created by Dmitry Sokolov on 4/4/18.
//

#include "../include/CurrencyCalculator.h"


// singleton
CurrencyCalculator* CurrencyCalculator::s_instance = nullptr;


CurrencyCalculator* CurrencyCalculator::sharedInstance() {
    // lazy initialization
    if (!s_instance)
        s_instance = new CurrencyCalculator();

    // pointer to our static reference
    return s_instance;
}

double CurrencyCalculator::calculateTotalResultForListOfPairs(const std::list<CurrencyPair> &route, double numberOfCoins) {
    // STUB
    return 0;
}

