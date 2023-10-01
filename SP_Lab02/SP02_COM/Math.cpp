#include "Math.h"
long g_lObjs = 0;
long g_lLocks = 0;

Math::Math()
{
	 m_lRef = 1;	// начальное количество ссылок на объект
	 InterlockedIncrement(&g_lObjs);	// увеличение значения глобальной переменной g_lObjs, указывающей на количество активных объектов
};

Math::~Math() 
{
	InterlockedDecrement(&g_lObjs);	// уменьшение значения глобальной переменной g_lObjs, указывающей на количество активных объектов
}

HRESULT STDMETHODCALLTYPE Math::QueryInterface(REFIID riid, void** ppv)	// для получения указателя на запрошенный интерфейс
{
	if (riid == IID_IUnknown || riid == IID_IAdder)
		*ppv = (IAdder*)this;
	else if (riid == IID_IMultiplier)
		*ppv = (IMultiplier*)this;
	else
		return E_NOINTERFACE;

	if (*ppv) {
		AddRef();	
		return (S_OK);
	}
	else
		return (E_NOINTERFACE);
};

STDMETHODIMP_(ULONG) Math::AddRef()	// увеличение счётчика
{
	InterlockedIncrement(&m_lRef);
	return m_lRef;
};

STDMETHODIMP_(ULONG) Math::Release()	// уменьшение счётчика
{
	InterlockedDecrement(&m_lRef);
	if (m_lRef == 0)
	{
		delete this;
		return 0;
	}
	else
		return m_lRef;
};

STDMETHODIMP Math::Add(const double x, const double y, double& z) {
	z = x + y;
	return S_OK;
}

STDMETHODIMP Math::Sub(const double x, const double y, double& z) {
	z = x - y;
	return S_OK;
}

STDMETHODIMP Math::Mul(const double x, const double y, double& z) {
	z = x * y;
	return S_OK;
}

STDMETHODIMP Math::Div(const double x, const double y, double& z) {
	z = x / y;
	return S_OK;
}
