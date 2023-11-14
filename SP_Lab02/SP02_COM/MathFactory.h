#pragma once
#include <objbase.h>

class MathFactory : public IClassFactory	// ��� �������� ����������� ������ Math
{
protected:
	ULONG m_lRef;	// ������� ������ �� ������
public:
	MathFactory();
	~MathFactory();

	STDMETHOD(QueryInterface(REFIID riid, void** ppv));	// ��� ��������� ��������� �� ����������� ���������
	STDMETHOD_(ULONG, AddRef(void));	// ���������� �������� ������ �� ������
	STDMETHOD_(ULONG, Release(void));	// ���������� �������� ������ �� ������

	STDMETHOD(CreateInstance(IUnknown* pUO, const IID& id, void** ppv));	// �������� ���������� ������ Math
	STDMETHOD(LockServer(BOOL b));	// ���������� �������� ��������� b
};