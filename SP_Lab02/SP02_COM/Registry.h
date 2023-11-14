#pragma once
#include "Windows.h"
#include <objbase.h>
#include <assert.h>

HRESULT RegisterServer(	// для регистрации COM-сервера в реестре Windows
	HMODULE hModule,	// Дескриптор модуля DLL, содержащего COM-сервер
	const CLSID& clsid,				// Идентификатор класса COM-сервера
	const WCHAR* szFriendlyName,	// читаемое для человека имя COM-сервера
	const WCHAR* szVerIndProgID,	// Программный идентификатор версии COM-сервера
	const WCHAR* szProgID);			// Программный идентификатор COM-сервера

HRESULT UnregisterServer(	// для удаления записей о COM-сервере из реестра Windows
	const CLSID& clsid,	// Идентификатор класса COM-сервера
	const WCHAR* szVerIndProgID,	// Программный идентификатор версии COM-сервера
	const WCHAR* szProgID);	// Программный идентификатор COM-сервера