#pragma once
#include <objbase.h>

class MathFactory : public IClassFactory	// дл€ создание экземпл€ров класса Math
{
protected:
	ULONG m_lRef;	// счЄтчик ссылок на объект
public:
	MathFactory();
	~MathFactory();

	STDMETHOD(QueryInterface(REFIID riid, void** ppv));	// дл€ получени€ указател€ на запрошенный интерфейс
	STDMETHOD_(ULONG, AddRef(void));	// увеличение счЄтчика ссылок на объект
	STDMETHOD_(ULONG, Release(void));	// уменьшение счЄтчика ссылок на объект

	STDMETHOD(CreateInstance(IUnknown* pUO, const IID& id, void** ppv));	// создание экземпл€ра класса Math
	STDMETHOD(LockServer(BOOL b));	// игнорирует значение параметра b
};