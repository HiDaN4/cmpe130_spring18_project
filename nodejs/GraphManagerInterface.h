// GraphManagerInterface.h
// GraphManagerInterface Class Specification
// Author: Antonio G. Bares Jr

#ifndef KRYPTOS_GRAPHMANAGERINTERFACE_H
#define KRYPTOS_GRAPHMANAGERINTERFACE_H

#include <nan.h>
#include <memory>
#include <string>
#include <list>
#include "../c++/include/GraphManager.h"
#include "../c++/include/CurrencyPair.h"
#include "../c++/include/CurrencyPairParser.h"
#include "../c++/include/DirectedMatrixGraph.h"

class GraphManagerInterface : public Nan::ObjectWrap
{
private:
    std::unique_ptr<GraphManager> graphManager;

public:
    // Module Init
    static NAN_MODULE_INIT(Init);

    // Constructor Handle
    static Nan::Persistent<v8::FunctionTemplate> constructor;

    // Constructor
    static NAN_METHOD(New);
    GraphManagerInterface(std::string&);

    // Destructor
    ~GraphManagerInterface() = default;

    // Getters
    static NAN_METHOD(getNameOfExchange);
    // static NAN_METHOD(getLastUpdateTimestamp);
    static NAN_METHOD(getCostForExchange);

    // Methods
    static NAN_METHOD(updateGraph);
    static NAN_METHOD(findBestExchangeRoute);
};

#endif  // KRYPTOS_GRAPHMANAGERINTERFACE_H