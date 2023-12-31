#pragma warning(disable : 4996)

#include <iostream>
#include <windows.h>
#include <conio.h>

#include "../OS14_HTCOM_LIB/pch.h"
#include "../OS14_HTCOM_LIB/OS14_HTCOM_LIB.h"

#ifdef _WIN64
#pragma comment(lib, "../x64/Debug/OS14_HTCOM_LIB.lib")
#else
#pragma comment(lib, "../Debug/OS14_HTCOM_LIB.lib")
#endif

using namespace std;

wchar_t* getWC(const char* c)
{
	wchar_t* wc = new wchar_t[strlen(c) + 1];
	mbstowcs(wc, c, strlen(c) + 1);

	return wc;
}

int main(int argc, char* argv[])
{

	setlocale(LC_ALL, "Russian");

	if (!SetCurrentDirectory(L"C:\\сп\\SP_Lab06\\OS_Lab14\\x64\\Debug"))
	{
		cout << "Ошибка при изменении текущего рабочего каталога" << endl;
		return 1;
	}

	try
	{
		OS14_HTCOM_HANDEL h = OS14_HTCOM::Init();
		ht::HtHandle* ht = nullptr;

		ht = OS14_HTCOM::HT::open(h, L"HTspace.ht", L"HTUser01", L"3115");

		HANDLE hStopEvent = CreateEvent(NULL,
			TRUE,
			FALSE,
			L"HTspace.htEvent");
		if (ht)
		{
			cout << "HT-Storage Start" << endl;
			wcout << "filename: " << ht->fileName << endl;
			cout << "secSnapshotInterval: " << ht->secSnapshotInterval << endl;
			cout << "capacity: " << ht->capacity << endl;
			cout << "maxKeyLength: " << ht->maxKeyLength << endl;
			cout << "maxPayloadLength: " << ht->maxPayloadLength << endl;

			while (!kbhit() && WaitForSingleObject(hStopEvent, 0) == WAIT_TIMEOUT)
				SleepEx(0, TRUE);

			OS14_HTCOM::HT::snap(h, ht);
			OS14_HTCOM::HT::close(h, ht);
		}
		else
			cout << "-- open: error" << endl;

		OS14_HTCOM::Dispose(h);
	}
	catch (const char* e) { cout << e << endl; }
	catch (int e) { cout << "HRESULT: " << e << endl; }

	system("pause");
}










//#pragma warning(disable : 4996)
//
//#include <iostream>
//#include <windows.h>
//#include <conio.h>
//
//#include "../OS14_HTCOM_LIB/pch.h"
//#include "../OS14_HTCOM_LIB/OS14_HTCOM_LIB.h"
//
//#ifdef _WIN64
//#pragma comment(lib, "../x64/Debug/OS14_HTCOM_LIB.lib")
//#else
//#pragma comment(lib, "../Debug/OS14_HTCOM_LIB.lib")
//#endif
//
//using namespace std;
//
//wchar_t* getWC(const char* c);
//
//int main(int argc, char* argv[])
//{
//	HANDLE hStopEvent = CreateEvent(NULL,
//		TRUE, //FALSE - автоматический сброс; TRUE - ручной
//		FALSE,
//		L"Stop");
//
//	setlocale(LC_ALL, "Russian");
//
//	try
//	{
//		cout << "Инициализация компонента:" << endl;
//		OS14_HTCOM_HANDEL h = OS14_HTCOM::Init();
//
//		ht::HtHandle* ht = nullptr;
//		wchar_t* fileName = getWC(argv[1]);
//
//		if (argc == 4)
//		{
//			wchar_t* username = getWC(argv[2]);
//			wchar_t* password = getWC(argv[3]);
//
//			ht = OS14_HTCOM::HT::open(h, fileName, username, password);
//		}
//		else
//		{
//			ht = OS14_HTCOM::HT::open(h, fileName);
//		}
//
//		if (ht)
//		{
//			cout << "HT-Storage Start" << endl;
//			wcout << "filename: " << ht->fileName << endl;
//			cout << "groupName" << ht->htUsersGroup << endl;
//			cout << "secSnapshotInterval: " << ht->secSnapshotInterval << endl;
//			cout << "capacity: " << ht->capacity << endl;
//			cout << "maxKeyLength: " << ht->maxKeyLength << endl;
//			cout << "maxPayloadLength: " << ht->maxPayloadLength << endl;
//
//			while (!kbhit() && WaitForSingleObject(hStopEvent, 0) == WAIT_TIMEOUT)
//				SleepEx(0, TRUE);
//
//			OS14_HTCOM::HT::snap(h, ht);
//			OS14_HTCOM::HT::close(h, ht);
//		}
//		else
//			cout << "-- open: error" << endl;
//
//		cout << endl << "Удалить компонент и выгрузить dll, если можно:" << endl;
//		OS14_HTCOM::Dispose(h);
//	}
//	catch (const char* e) { cout << e << endl; }
//	catch (int e) { cout << "HRESULT: " << e << endl; }
//
//	system("pause");
//}
//
//wchar_t* getWC(const char* c)
//{
//	wchar_t* wc = new wchar_t[strlen(c) + 1];
//	mbstowcs(wc, c, strlen(c) + 1);
//
//	return wc;
//}
