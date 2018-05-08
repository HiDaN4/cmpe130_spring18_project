// GraphManagerInterface.cpp
// GraphManagerInterface Class Implementation
// Author: Antonio G. Bares Jr

#include "GraphManagerInterface.h"

// Module Init
NAN_MODULE_INIT(GraphManagerInterface::Init)
{
    v8::Local<v8::FunctionTemplate> ctor = Nan::New<v8::FunctionTemplate>(GraphManagerInterface::New);
    constructor.Reset(ctor);
    ctor->InstanceTemplate()->SetInternalFieldCount(1);
    ctor->SetClassName(Nan::New("GraphManagerInterface").ToLocalChecked());

    // Link Getters & Methods
    Nan::SetPrototypeMethod(ctor, "getNameOfExchange", getNameOfExchange);
    Nan::SetPrototypeMethod(ctor, "getLastUpdateTimestamp", getLastUpdateTimestamp);
    Nan::SetPrototypeMethod(ctor, "updateGraph", updateGraph);
    Nan::SetPrototypeMethod(ctor, "findBestExchangeRoute", findBestExchangeRoute);

    target->Set(Nan::New("GraphManagerInterface").ToLocalChecked(), ctor->GetFunction());
}

// Constructor Handle
Nan::Persistent<v8::FunctionTemplate> GraphManagerInterface::constructor;

// Constructor
NAN_METHOD(GraphManagerInterface::New)
{
    // Throw if the constructor is called without 'new' keyword
    if(!info.IsConstructCall())
    {
        return Nan::ThrowError(Nan::New("Constructor called without 'new' keyword").ToLocalChecked());
    }

    if(info.Length() != 1)
    {
        return Nan::ThrowError(Nan::New("Constructor expects an argument 'nameOfExchange'").ToLocalChecked());
    }

    if(!info[0]->IsString())
    {
        return Nan::ThrowError(Nan::New("Constructor expects 'nameOfExchange' to be a string").ToLocalChecked());
    }

    // Convert argument to std::string type
    v8::String::Utf8Value utf8Str(info[0]->ToString());
    std::string str = std::string(*utf8Str);

    // Create new instance and wrap it to the JS instance
    GraphManagerInterface* graphManagerInterface = new GraphManagerInterface(str);
    graphManagerInterface->Wrap(info.Holder());

    info.GetReturnValue().Set(info.Holder());
}

GraphManagerInterface::GraphManagerInterface(std::string& nameOfExchange)
{
    graphManager = std::make_unique<GraphManager>(nameOfExchange, new DirectedListGraph<std::string>(), new CurrencyPairParser());
}

// Getters
NAN_METHOD(GraphManagerInterface::getNameOfExchange)
{
    // Unwrap the object
    GraphManagerInterface* self = Nan::ObjectWrap::Unwrap<GraphManagerInterface>(info.This());

    if (info.Length() > 0)
        return Nan::ThrowError(Nan::New("'getNameOfExchange' expects no arguments'").ToLocalChecked());

    // Convert std::string to v8::String type
    std::string name = self->graphManager->getNameOfExchange();
    v8::Local<v8::String> v8Name = v8::String::NewFromUtf8(v8::Isolate::GetCurrent(), name.c_str());

    info.GetReturnValue().Set(v8Name);
}

NAN_METHOD(GraphManagerInterface::getLastUpdateTimestamp)
{
    // Unwrap the object
    GraphManagerInterface* self = Nan::ObjectWrap::Unwrap<GraphManagerInterface>(info.This());

    if (info.Length() > 0)
        return Nan::ThrowError(Nan::New("'getLastUpdateTimestamp' expects no arguments'").ToLocalChecked());

    info.GetReturnValue().Set(self->graphManager->getLastUpdateTimestamp());
}

NAN_METHOD(GraphManagerInterface::updateGraph)
{
    // Unwrap the object
    GraphManagerInterface* self = Nan::ObjectWrap::Unwrap<GraphManagerInterface>(info.This());

    if (info.Length() != 1)
        return Nan::ThrowError(Nan::New("'updateGraph' expects 1 argument'").ToLocalChecked());

    if (!info[0]->IsString())
        return Nan::ThrowError(Nan::New("'updateGraph' expects a string argument").ToLocalChecked());

    // Convert argument to std::string type
    v8::String::Utf8Value utf8Str(info[0]->ToString());
    std::string str = std::string(*utf8Str);

    self->graphManager->updateGraph(str);
}

NAN_METHOD(GraphManagerInterface::findBestExchangeRoute)
{
    // Unwrap the object
    GraphManagerInterface* self = Nan::ObjectWrap::Unwrap<GraphManagerInterface>(info.This());

    if (info.Length() != 2)
        return Nan::ThrowError(Nan::New("'findBestExchangeRoute' expects 2 arguments'").ToLocalChecked());

    if(!info[0]->IsString() || !info[1]->IsString())
        return Nan::ThrowError(Nan::New("'findBestExchangeRoute' expects string parameters").ToLocalChecked());

    info.GetReturnValue().Set(Nan::New("Not implemented yet").ToLocalChecked());
}