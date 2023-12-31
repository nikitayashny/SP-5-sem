#ifdef _WIN64
#pragma comment(lib, "../x64/debug/OS11_HTAPI.lib")
#else
#pragma comment(lib, "../debug/OS11_HTAPI.lib")
#endif

#include "../OS11_HTAPI/pch.h"
#include "../OS11_HTAPI/HT.h"

using namespace std;

wchar_t* getWC(const char* c);

int main(int argc, char* argv[])
{
	ht::HtHandle* ht = nullptr;
	ht = ht::create(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), getWC(argv[5]));
	if (ht)
	{
		cout << "HT-Storage Created" << endl;
		wcout << "filename: " << ht->fileName << endl;
		cout << "secSnapshotInterval: " << ht->secSnapshotInterval << endl;
		cout << "capacity: " << ht->capacity << endl;
		cout << "maxKeyLength: " << ht->maxKeyLength << endl;
		cout << "maxPayloadLength: " << ht->maxPayloadLength << endl;

		ht::close(ht);
	}
	else
		cout << "-- create: error" << endl;
}

wchar_t* getWC(const char* c)
{
	wchar_t* wc = new wchar_t[strlen(c) + 1];
	mbstowcs(wc, c, strlen(c) + 1);

	return wc;
}








//#include "../OS11_HTAPI/pch.h"
//#include "../OS11_HTAPI/HT.h"
//#include <string>
//#include <sstream>
//
//using namespace std;
//
//wchar_t* getWC(const char* c);
//
//int main(int argc, char* argv[])
//{
//	try 
//	{
//#ifdef _WIN64
//		HMODULE hmdll = LoadLibrary(L"../x64/Debug/OS11_HTAPI.dll");
//#else
//		HMODULE hmdll = LoadLibrary(L"../Debug/OS11_HTAPI.dll");
//#endif
//		if (!hmdll)
//			throw "-- LoadLibrary failed";
//
//		auto create = (ht::HtHandle * (*)(int, int, int, int, const wchar_t*)) GetProcAddress(hmdll, "create");
//		auto close = (BOOL(*)(const ht::HtHandle*)) GetProcAddress(hmdll, "close");
//
//		ht::HtHandle* ht = nullptr;
//		ht = create(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), getWC(argv[5]));
//		if (ht)
//		{
//			cout << "HT-Storage Created" << endl;
//			wcout << "filename: " << ht->fileName << endl;
//			cout << "secSnapshotInterval: " << ht->secSnapshotInterval << endl;
//			cout << "capacity: " << ht->capacity << endl;
//			cout << "maxKeyLength: " << ht->maxKeyLength << endl;
//			cout << "maxPayloadLength: " << ht->maxPayloadLength << endl;
//
//			close(ht);
//			FreeLibrary(hmdll);
//		}
//		else
//			cout << "-- create: error" << endl;
//	}
//	catch (const char* msg)
//	{
//		cout << msg << endl;
//	}
//}
//
//wchar_t* getWC(const char* c)
//{
//	wchar_t* wc = new wchar_t[strlen(c) + 1];
//	mbstowcs(wc, c, strlen(c) + 1);
//
//	return wc;
//}
