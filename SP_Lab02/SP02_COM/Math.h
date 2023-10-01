#pragma once

#include<objbase.h>
#include<iostream>
#include "INTERFACE.h"

// внешние переменные для отслеживания количество активных объектов и блокировок в COM
extern long g_lObjs;
extern long g_lLocks;

class Math : public IAdder, public IMultiplier	
{
private:
	volatile ULONG m_lRef;
public:
	Math();
	~Math();

	STDMETHOD(QueryInterface(REFIID riid, void** ppv));	// для получения указателя на запрошенный интерфейс
	STDMETHOD_(ULONG, AddRef(void));	// увеличение счётчика ссылок на объект
	STDMETHOD_(ULONG, Release(void));	// уменьшение счётчика ссылок на объект

	STDMETHOD(Add(const double x, const double y, double& z));
	STDMETHOD(Sub(const double x, const double y, double& z));
	STDMETHOD(Mul(const double x, const double y, double& z));
	STDMETHOD(Div(const double x, const double y, double& z));

};