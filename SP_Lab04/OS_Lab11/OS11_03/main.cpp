#ifdef _WIN64
#pragma comment(lib, "../x64/debug/OS11_HTAPI.lib")
#else
#pragma comment(lib, "../debug/OS11_HTAPI.lib")
#endif

#include <string>
#include <sstream>
#include "../OS11_HTAPI/pch.h"
#include "../OS11_HTAPI/HT.h"

using namespace std;

string intToString(int number);

int main(int argc, char* argv[])
{
	try
	{
		ht::HtHandle* ht = ht::open(L"HTspace.ht", true);
		if (ht)
			cout << "-- open: success" << endl;
		else
			throw "-- open: error";

		while (true) {
			int numberKey = rand() % 50;
			string key = intToString(numberKey);
			cout << key << endl;

			ht::Element* element = new ht::Element(key.c_str(), key.length() + 1);
			if (ht::removeOne(ht, element))
				cout << "-- remove: success" << endl;
			else
				cout << "-- remove: error" << endl;

			delete element;

			Sleep(1000);
		}
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
}

string intToString(int number)
{
	stringstream convert;
	convert << number;

	return convert.str();
}





//#include <string>
//#include <sstream>
//#include "../OS11_HTAPI/pch.h"
//#include "../OS11_HTAPI/HT.h"
//
//using namespace std;
//
//string intToString(int number);
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
//		cout << "-- LoadLibrary success" << endl;
//
//		auto open = (ht::HtHandle * (*)(const wchar_t*, bool)) GetProcAddress(hmdll, "open");
//		auto removeOne = (BOOL(*)(ht::HtHandle*, const ht::Element*)) GetProcAddress(hmdll, "removeOne");
//
//		ht::HtHandle* ht = open(L"HTspace.ht", true);
//		if (ht)
//			cout << "-- open: success" << endl;
//		else
//			throw "-- open: error";
//
//		while (true) {
//			int numberKey = rand() % 50;
//			string key = intToString(numberKey);
//			cout << key << endl;
//
//			ht::Element* element = new ht::Element(key.c_str(), key.length() + 1);
//			if (removeOne(ht, element))
//				cout << "-- remove: success" << endl;
//			else
//				cout << "-- remove: error" << endl;
//
//			delete element;
//
//			Sleep(1000);
//		}
//		FreeLibrary(hmdll);
//	}
//	catch (const char* msg) 
//	{
//		cout << msg << endl;
//	}
//}
//
//string intToString(int number)
//{
//	stringstream convert;
//	convert << number;
//
//	return convert.str();
//}
