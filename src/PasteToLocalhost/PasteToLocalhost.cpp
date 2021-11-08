#include "PasteToLocalhost.h"
#include <fstream>
#include <locale>
#include <codecvt>
#include <cstdio>
#include <string>

BOOL WINAPI DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	return TRUE;
}

const int NO_OF_LINES = 5;

bool ProcessSentence(std::wstring& sentence, SentenceInfo sentenceInfo)
{
	if (sentenceInfo["current select"]) {
		std::string oldestLine_ = "../node/public/text/line" + std::to_string(NO_OF_LINES);
		const char* oldestLine = oldestLine_.c_str();
		remove(oldestLine);

		for (int i = NO_OF_LINES; i > 1; i--) {
			std::string oldName_ = "../node/public/text/line" + std::to_string(i - 1);
			const char* oldName = oldName_.c_str();
			std::string newName_ = "../node/public/text/line" + std::to_string(i);
			const char* newName = newName_.c_str();
			rename(oldName, newName);
		}
		const std::locale utf8_locale = std::locale(std::locale(), new std::codecvt_utf8<wchar_t>());
		std::wofstream newestLine(L"../node/public/text/line1");
		if (newestLine.is_open()) {
			newestLine.imbue(utf8_locale);
			newestLine << sentence;
			newestLine.close();
		}
	}
	return false;
}
