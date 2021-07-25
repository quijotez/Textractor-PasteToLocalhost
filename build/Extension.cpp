#include "Extension.h"
#include <fstream>
#include <locale>
#include <codecvt>

BOOL WINAPI DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		MessageBoxW(NULL, L"Extension Loaded", L"Example", MB_OK);
		break;
	case DLL_PROCESS_DETACH:
		MessageBoxW(NULL, L"Extension Removed", L"Example", MB_OK);
		break;
	}
	return TRUE;
}

bool ProcessSentence(std::wstring& sentence, SentenceInfo sentenceInfo)
{
	if (sentenceInfo["current select"]) {
		const std::locale utf8_locale = std::locale(std::locale(), new std::codecvt_utf8<wchar_t>());
		std::wofstream myfile(L"../node/index.html");
		if (myfile.is_open())
		{
			myfile.imbue(utf8_locale);
			myfile << "<html>\n";
			myfile << "<head>\n";
			myfile << "\t<meta charset=\"UTF-8\">\n";
			myfile << "\t<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n";
			myfile << "\t<link rel=\"stylesheet\" href=\"css/style.css\">\n";
			myfile << "\t<title>Textractor</title>\n";
			myfile << "</head>\n";
			myfile << "<body>\n";
			myfile << "\t<p>";
			myfile << sentence;
			myfile << "</p>\n";
			myfile << "</body>\n";
			myfile << "</html>";
			myfile.close();
		}
	}
	return false;
}
