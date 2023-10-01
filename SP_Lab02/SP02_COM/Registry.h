#pragma once
#include "Windows.h"
#include <objbase.h>
#include <assert.h>

HRESULT RegisterServer(	// ��� ����������� COM-������� � ������� Windows
	HMODULE hModule,	// ���������� ������ DLL, ����������� COM-������
	const CLSID& clsid,				// ������������� ������ COM-�������
	const WCHAR* szFriendlyName,	// �������� ��� �������� ��� COM-�������
	const WCHAR* szVerIndProgID,	// ����������� ������������� ������ COM-�������
	const WCHAR* szProgID);			// ����������� ������������� COM-�������

HRESULT UnregisterServer(	// ��� �������� ������� � COM-������� �� ������� Windows
	const CLSID& clsid,	// ������������� ������ COM-�������
	const WCHAR* szVerIndProgID,	// ����������� ������������� ������ COM-�������
	const WCHAR* szProgID);	// ����������� ������������� COM-�������