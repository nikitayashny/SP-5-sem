#pragma once
#include "../SP02_COM/Interface.h"
#define SP02HANDLE void*	// void* используется в качестве дескриптора COM-объекта
// типы указателей на интерфейсы IAdder, IMultiplier и IUnknown
#define PIADDER IAdder*
#define PIMULTIPLIER IMultiplier*
#define PIUNKNOWN IUnknown*

// для вывода сообщений об ошибках или результатов операций
#define IERR(s)    std::cerr<<"ERROR:  "<<s<<std::endl
#define IRES(s,r)  std::cerr<<s<<r<<std::endl

namespace SP02 
{
	SP02HANDLE Init();	// инициализция ресурсов COM
	namespace Adder 
	{
		double Add(SP02HANDLE, double, double);
		double Sub(SP02HANDLE, double, double);
	}

	namespace Multiplier
	{
		double Mul(SP02HANDLE, double, double);
		double Div(SP02HANDLE, double, double);
	}
	void Dispose(SP02HANDLE);	// освобождение ресурсов COM
}