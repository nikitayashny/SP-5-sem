#pragma once
#include <windows.h>
#include <iostream>
#include <fstream>
#include <tchar.h>
#include <string>
#include "sddl.h"

//#include "C:\сп\SP_Lab06\OS_Lab14\OS14_HTCOM_LIB\pch.h"
//#include "C:\сп\SP_Lab06\OS_Lab14\OS14_HTCOM_LIB/OS14_HTCOM_LIB.h"

#include "C:\сп\SP_Lab07\lab6-ht-service-user-com-dll\OS15_HTCOM_LIB\pch.h"
#include "C:\сп\SP_Lab07\lab6-ht-service-user-com-dll\OS15_HTCOM_LIB/OS15_HTCOM_LIB.h"

#define SERVICENAME L"SP_Lab15_service"
//#define HTPATH L"C:\\сп\\SP_Lab07\\lab6-ht-service-user-com-dll\\x64\\Debug\\HTspace.ht"
#define HTPATH L"HTspace.ht"

#define USERNAME L"HTUser01"
#define PASSWORD L"3115"

#define TRACEPATH L"C:\\сп\\SP_Lab07\\lab6-ht-service-user-com-dll\\x64\\Debug\\service.trace"

VOID WINAPI ServiceMain(DWORD dwArgc, LPTSTR* lpszArgv);
VOID WINAPI ServiceHandler(DWORD fdwControl);

SECURITY_ATTRIBUTES getSecurityAttributes();
HANDLE createStopEvent(const wchar_t* stopEventName);
void startService();
void trace(const char* msg, int r = std::ofstream::app);








//#pragma once
//#include <windows.h>
//#include <iostream>
//#include <fstream>
//#include <tchar.h>
//#include <string>
//#include "sddl.h"
//
//#include "C:\\сп\\SP_Lab07\\lab6-ht-service-user-com-dll\\OS15_HTCOM_LIB\\pch.h"
//#include "C:\сп\SP_Lab07\lab6-ht-service-user-com-dll\\OS15_HTCOM_LIB\\OS15_HTCOM_LIB.h"
//
//#define SERVICENAME L"SP_Lab15_service"
////#define HTPATH L"C:\\сп\\SP_Lab07\\lab6-ht-service-user-com-dll\\x64\\Debug\\HTspace.ht"
//#define HTPATH L"HTspace.ht"
//
//#define USERNAME L"HTUser01"
//#define PASSWORD L"3115"
//
//#define TRACEPATH L"C:\\сп\\SP_Lab07\\lab6-ht-service-user-com-dll\\x64\\Debug\\service.trace"
//
//VOID WINAPI ServiceMain(DWORD dwArgc, LPTSTR* lpszArgv);
//VOID WINAPI ServiceHandler(DWORD fdwControl);
//
//SECURITY_ATTRIBUTES getSecurityAttributes();
//HANDLE createStopEvent(const wchar_t* stopEventName);
//void startService();
//void trace(const char* msg, int r = std::ofstream::app);
