#pragma warning(disable : 4996)

#include <iostream>
#include <windows.h>
#include <string>
#include <sstream>
#include "sddl.h"

#include "../OS15_HTCOM_LIB/pch.h"
#include "../OS15_HTCOM_LIB/OS15_HTCOM_LIB.h"

#ifdef _WIN64
#pragma comment(lib, "../x64/Debug/OS15_HTCOM_LIB.lib")
#else
#pragma comment(lib, "../Debug/OS15_HTCOM_LIB.lib")
#endif

using namespace std;

string intToString(int number);

int main(int argc, char* argv[])
{

	setlocale(LC_ALL, "Russian");

	try
	{
		cout << "Инициализация компонента:" << endl;
		OS15_HTCOM_HANDEL h = OS15_HTCOM::Init();

		ht::HtHandle* ht = OS15_HTCOM::HT::open(h, L"HTspace.ht", L"HTUser01", L"3115", true);
		if (ht)
			cout << "-- open: success" << endl;
		else
			throw "-- open: error";
		HANDLE hStopEvent = CreateEvent(NULL,
			TRUE,
			FALSE,
			L"Global\\Stop");
		while (WaitForSingleObject(hStopEvent, 0) == WAIT_TIMEOUT) {
			int numberKey = rand() % 50;
			string key = intToString(numberKey);
			cout << key << endl;

			ht::Element* element = OS15_HTCOM::Element::createGetElement(h, key.c_str(), key.length() + 1);
			if (OS15_HTCOM::HT::removeOne(h, ht, element))
				cout << "-- remove: success" << endl;
			else
				cout << "-- remove: error" << endl;

			delete element;

			Sleep(1000);
		}

		OS15_HTCOM::HT::close(h, ht);

		cout << endl << "Удалить компонент и выгрузить dll, если можно:" << endl;
		OS15_HTCOM::Dispose(h);
	}
	catch (const char* e) { cout << e << endl; }
	catch (int e) { cout << "HRESULT: " << e << endl; }

}

string intToString(int number)
{
	stringstream convert;
	convert << number;

	return convert.str();
}