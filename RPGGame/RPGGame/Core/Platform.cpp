#include "Platform.h"

#include <time.h>
#include <stdlib.h>


const std::string platform::UTF_82ASCII(const std::string& sUtf8Code)
{
	wchar_t sWideChar[MAX_STRING_LENGTH];
	char sAsciiChar[MAX_STRING_LENGTH];

	//�Ȱ� utf8 תΪ unicode  
	::MultiByteToWideChar(CP_UTF8, 0, sUtf8Code.c_str(), -1, sWideChar, MAX_STRING_LENGTH);

	//���� unicode תΪ ascii  
	::WideCharToMultiByte(CP_OEMCP, 0, sWideChar, -1, sAsciiChar, MAX_STRING_LENGTH, NULL, NULL);

	return string(sAsciiChar);
}

int platform::Rank(const int iMax)
{
    srand(time(NULL));

    int iRankMax = (iMax <= 0) ? 1 : iMax;

    return rand()% iRankMax;
}
