#include <windows.h>
#include <cstring>

wchar_t* getWC(const char* c)
{
    size_t length = strlen(c) + 1;
    wchar_t* wc = new wchar_t[length];
    mbstowcs_s(nullptr, wc, length, c, length);

    return wc;
}

int main(int argc, char* argv[])
{
    char eventName[100];
    strcpy_s(eventName, argv[1]);
    strcat_s(eventName, "Event");

    HANDLE hStopEventSpec = CreateEvent(nullptr,
        TRUE,
        FALSE,
        getWC(eventName));

    SetEvent(hStopEventSpec);

    delete[] getWC(eventName);
    CloseHandle(hStopEventSpec);

    return 0;
}







//#pragma warning(disable : 4996)
//#include <windows.h>
//#include <iostream>
//
//using namespace std;
//
//wchar_t* getWC(const char* c)
//{
//	wchar_t* wc = new wchar_t[strlen(c) + 1];
//	mbstowcs(wc, c, strlen(c) + 1);
//
//	return wc;
//}
//
//int main(int argc, char* argv[])
//{
//	wchar_t* fileName = getWC(argv[1]);
//	char* eventName = strcat(argv[1], "Event");
//	HANDLE event;
//	event = CreateEvent(NULL, TRUE, FALSE, eventName);
//	SetEvent(event);
//}
//
