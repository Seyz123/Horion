#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>

#ifdef _DEBUG
#include <ios>
#include <iosfwd>
#include <iostream>
#include <streambuf>
#endif

#include <windows.storage.h>
#include <wrl.h>

#include <ctime>
#include <iomanip>
#include <mutex>
#include <sstream>
#include <string>
#include <vector>

#include "Utils.h"

#pragma comment(lib, "runtimeobject")

using namespace ABI::Windows::Storage;
using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;

#ifndef logF
#define logF Logger::WriteLogFileF
#endif

struct TextForPrint {
	char time[20];
	char text[100];
};

class Logger {
private:
	static std::wstring GetRoamingFolderPath();

public:
	static void WriteLogFileF(const char* fmt, ...);
	static void WriteBigLogFileF(size_t maxSize, const char* fmt, ...);
	static std::vector<TextForPrint>* GetTextToPrint();
	static CRITICAL_SECTION* GetTextToPrintSection();
	//static std::vector<TextForPrint*> stringPrintVector;
	static void Disable();
};

extern char logPath[200];
extern bool initializedLogger;
extern CRITICAL_SECTION loggerLock;
extern CRITICAL_SECTION vecLock;
extern std::vector<TextForPrint> stringPrintVector;
