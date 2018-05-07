// CurrencyPairParser.cpp
// CurrencyPairParser Class Implementation
// Author: Antonio G. Bares Jr.

#include "CurrencyPairParser.h"

// Utilities
CurrencyPair CurrencyPairParser::parseLine(const std::string& line)
{
    std::string from;
    std::string to;
    std::string tempStr;
    double price;

    std::stringstream lineStream;
    lineStream << line;

    std::getline(lineStream, from, ',');
    std::getline(lineStream, to, ',');
    std::getline(lineStream, tempStr);

    price = std::stod(tempStr);

    return CurrencyPair(from, to, price);
}

std::list<CurrencyPair> CurrencyPairParser::parseCurrenciesString(const std::string& data)
{
    
}

std::list<CurrencyPair> CurrencyPairParser::parseFileAndGetListOfCurrencies(const std::string& fileName)
{
    std::list<CurrencyPair> newList;

    std::fstream inputFile;
    inputFile.open(fileName, std::fstream::in);
    
    if(!inputFile.is_open())
        std::cout << "File could not be opened!" << std::endl;

    else
    {
        while(!inputFile.eof())
        {
            std::string tempStr;
            std::getline(inputFile, tempStr);

            if (tempStr.length() > 0)
                newList.push_back(parseLine(tempStr));
        }

    }
    
    return newList;
}