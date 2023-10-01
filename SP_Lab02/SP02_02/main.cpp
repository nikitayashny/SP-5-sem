#include <objbase.h>
#include <iostream>
#include "../SP02_COM/Interface.h"

// макросы для вывода сообщений об ошибках и результатов
#define IERR(s)    std::cout<<"error "<<s<<std::endl
#define IRES(s,r)  std::cout<<s<<r<<std::endl

// указатели на интерфейсы
IAdder* pIAdder = nullptr;
IMultiplier* pMultiplier = nullptr;


int main()
{
	IUnknown* pIUnknown = NULL;
	CoInitialize(NULL);	// инициализация COM-библиотеки              
	HRESULT hr0 = CoCreateInstance(CLSID_Math, NULL, CLSCTX_INPROC_SERVER, IID_IUnknown, (void**)&pIUnknown);	// создание экземпляра COM-объекта

	if (SUCCEEDED(hr0))
	{
		std::cout << "CoCreateInstance succeeded" << std::endl;
		if (SUCCEEDED(pIUnknown->QueryInterface(IID_IAdder, (void**)&pIAdder)))	// получение указателей на интерфейсы IAdder и IMultiplier
		{
			{
				double z = 0.0;
				if (!SUCCEEDED(pIAdder->Add(2.0, 3.0, z)))  IERR("IAdder::Add");
				else IRES("IAdder::Add = ", z);
			}
			{
				double z = 0.0;
				if (!SUCCEEDED(pIAdder->Sub(2.0, 3.0, z)))  IERR("IAdder::Sub");
				else IRES("IAdder::Sub = ", z);
			}
			if (SUCCEEDED(pIAdder->QueryInterface(IID_IMultiplier, (void**)&pMultiplier)))
			{
				{
					double z = 0.0;
					if (!SUCCEEDED(pMultiplier->Mul(2.0, 3.0, z))) IERR("IMultiplier::Mul");
					else IRES("Multiplier::Mul = ", z);
				}
				{
					double z = 0.0;
					if (!SUCCEEDED(pMultiplier->Div(2.0, 3.0, z))) IERR("IMultiplier::Div");
					else IRES("IMultiplier::Div = ", z);
				}
				if (SUCCEEDED(pMultiplier->QueryInterface(IID_IAdder, (void**)&pIAdder)))
				{
					double z = 0.0;
					if (!SUCCEEDED(pIAdder->Add(2.0, 3.0, z))) IERR("IAdder::Add");
					else IRES("IAdder::Add = ", z);
					pIAdder->Release();
				}
				else  IERR("IMultiplier->IAdder");
				pMultiplier->Release();
			}
			else IERR("IAdder->IMultiplier");
			pIAdder->Release();
		}
		else  IERR("IAdder");
	}
	else  
		std::cerr << "CoCreateInstance error: " << hr0 <<  std::endl;
	pIUnknown->Release();
	CoFreeUnusedLibraries();                   // завершение работы с библиотекой и освобождение ресурсов библиотеки 

	return 0;
}