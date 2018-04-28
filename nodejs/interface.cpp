#include <nan.h>

NAN_METHOD(test)
{
    auto message = Nan::New("Hello World!").ToLocalChecked();
    info.GetReturnValue().Set(message);
}

NAN_MODULE_INIT(Initialize)
{
    NAN_EXPORT(target, test);
}

NODE_MODULE(testAddon, Initialize);