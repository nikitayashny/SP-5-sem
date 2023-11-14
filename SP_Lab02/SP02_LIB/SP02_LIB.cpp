#include "SP02_LIB.h"
#include <stdexcept>
#include <iostream>



SP02HANDLE SP02::Init() // инициализирует систему COM и создает экземпляр COM-объекта
{
    PIUNKNOWN pIUnknown = nullptr;
    try {
        if(!SUCCEEDED(CoInitialize(nullptr)))   // инициализация библиотеки
            throw std::runtime_error("Error initialize OLE32");

        if(!SUCCEEDED(CoCreateInstance(CLSID_Math, NULL, CLSCTX_INPROC_SERVER, IID_IUnknown, (void**)&pIUnknown)))  // создание экземпляра COM-объекта
            throw std::runtime_error("Error create instance CLSID_Math");

        return pIUnknown;
    }
    catch (std::runtime_error error) {
        IRES("Init: ", error.what());
        return nullptr;
    }
}

double SP02::Adder::Add(SP02HANDLE h, double x, double y)   // SP02HANDLE является указателем на IUnknown
{
    try {
        if (!SUCCEEDED(((PIUNKNOWN)h)->QueryInterface(IID_IAdder, (void**)&h))) // получаем указатель на IAdder
            throw std::runtime_error("Error get interface IID_IAdder");

        double result = 0.0;
        if (!SUCCEEDED(((PIADDER)h)->Add(x, y, result)))
            throw std::runtime_error("Error IAdder::Add");
        return result;
    }
    catch (std::runtime_error error) {
        IRES("Add: ", error.what());
    }
   
}

double SP02::Adder::Sub(SP02HANDLE h, double x, double y)   
{
    try {
        if (!SUCCEEDED(((PIUNKNOWN)h)->QueryInterface(IID_IAdder, (void**)&h)))
            throw std::runtime_error("Error get interface IID_IAdder");

        double result = 0.0;
        if (!SUCCEEDED(((PIADDER)h)->Sub(x, y, result)))
            throw std::runtime_error("Error IAdder::Sub");
        return result;
    }
    catch (std::runtime_error error) {
        IRES("Sub: ", error.what());
    }
}

double SP02::Multiplier::Mul(SP02HANDLE h, double x, double y)
{
    try {
        if (!SUCCEEDED(((PIUNKNOWN)h)->QueryInterface(IID_IMultiplier, (void**)&h)))
            throw std::runtime_error("Error get interface IID_IMultiplier");

        double result = 0.0;
        if (!SUCCEEDED(((PIMULTIPLIER)h)->Mul(x, y, result)))
            throw std::runtime_error("Error Multiplier::Mul");
        return result;
    }
    catch (std::runtime_error error) {
        IRES("Mul: ", error.what());
    }
}
 
double SP02::Multiplier::Div(SP02HANDLE h, double x, double y)
{
    try {
        if (!SUCCEEDED(((PIUNKNOWN)h)->QueryInterface(IID_IMultiplier, (void**)&h)))
            throw std::runtime_error("Error get interface IID_IMultiplier");
        
        if(y == 0)
            throw std::runtime_error("Param of second equals to zero (x/0)");

        double result = 0.0;
        if (!SUCCEEDED(((PIMULTIPLIER)h)->Div(x, y, result)))
            throw std::runtime_error("Error Multiplier::Div");
        return result;
    }
    catch (std::runtime_error error) {
        IRES("Div: ", error.what());
    }
}

void SP02::Dispose(SP02HANDLE h) {
    ((PIUNKNOWN)h)->Release();  // свобождения интерфейса
    CoFreeUnusedLibraries();    // освобождения ресурсов библиотеки
}