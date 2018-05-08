// GraphManagerModule.cpp
// GraphManagerModule
// Author: Antonio G. Bares Jr

#include <nan.h>
#include "GraphManagerInterface.h"

NAN_MODULE_INIT(InitModule) {
  GraphManagerInterface::Init(target);
}

NODE_MODULE(module, InitModule);