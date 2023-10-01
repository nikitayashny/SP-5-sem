#pragma once
#include "../SP02_COM/Interface.h"
#define SP02HANDLE void*	// void* ������������ � �������� ����������� COM-�������
// ���� ���������� �� ���������� IAdder, IMultiplier � IUnknown
#define PIADDER IAdder*
#define PIMULTIPLIER IMultiplier*
#define PIUNKNOWN IUnknown*

// ��� ������ ��������� �� ������� ��� ����������� ��������
#define IERR(s)    std::cerr<<"ERROR:  "<<s<<std::endl
#define IRES(s,r)  std::cerr<<s<<r<<std::endl

namespace SP02 
{
	SP02HANDLE Init();	// ������������ �������� COM
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
	void Dispose(SP02HANDLE);	// ������������ �������� COM
}