// GraphManagerInterface.h
// GraphManagerInterface Class Specification
// Author: Antonio G. Bares Jr

#include <nan.h>
#include <memory>
#include <string>
#include "../c++/include/GraphManager.h"
#include "../c++/include/CurrencyPairParser.h"
#include "../c++/include/DirectedListGraph.h"

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
    ~GraphManagerInterface();

    // Getters
    static NAN_METHOD(getNameOfExchange);
    static NAN_METHOD(getLastUpdateTimestamp);

    // Methods
    static NAN_METHOD(updateGraph);
    static NAN_METHOD(findBestExchangeRoute);
};
