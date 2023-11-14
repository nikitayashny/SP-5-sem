#include "INTERFACE.h"
#include "REGISTRY.h"
#include "Math.h"
#include "MathFactory.h"

HMODULE hmodule;	// дескриптор модуля dll
LONG Seq = 0;

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)	//  Это точка входа для DLL
{
    switch (ul_reason_for_call)	// причина вызова функции
    {
    case DLL_PROCESS_ATTACH:	// библиотека загружена в процесс
        hmodule = hModule;	// Значение дескриптора модуля DLL (hModule) присваивается переменной hmodule
        break;
    case DLL_THREAD_ATTACH:
		break;
    case DLL_THREAD_DETACH:
		break;
    case DLL_PROCESS_DETACH:
		break;
    }
    return TRUE;
}

STDAPI DllInstall(BOOL b, PCWSTR s) 
{
	return S_OK;	// успешная установка DLL
}

STDAPI DllRegisterServer()	// регистрация COM-сервера
{
	return RegisterServer(	// вызов стандартной функции модуля REGISTRY.H
		hmodule,
		CLSID_Math,
		FriendlyName,
		VerIndProg,
		ProgID
	);
}

STDAPI DllUnregisterServer()	// для удаления регистрации COM-сервера
{
	return UnregisterServer(	// вызов стандартной функции модуля REGISTRY.H
		CLSID_Math,
		VerIndProg,
		ProgID
	);
}

STDAPI DllCanUnloadNow()	// для проверки возможности выгрузки DLL
{
	if ((g_lLocks == 0) && (g_lObjs == 0))	// если нет активных ссылок на объекты COM-сервера и нет активных экземпляров объектов
		return S_OK;
	else
		return S_FALSE;
}

STDAPI DllGetClassObject(const CLSID& clsid, const IID& iid, void** ppv)	// для получения указателя на фабрику классов
{	 
	HRESULT rc = E_UNEXPECTED;
	MathFactory* pF;

	if (clsid != CLSID_Math) 
		rc = CLASS_E_CLASSNOTAVAILABLE;
	else if ((pF = new MathFactory()) == NULL) 
		rc = E_OUTOFMEMORY;
	else 
	{
		rc = pF->QueryInterface(iid, ppv);
		pF->Release();
	}
	return rc;
}