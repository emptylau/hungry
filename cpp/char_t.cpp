#include <iostream>
#include <stdio.h>
#include <typeinfo>
#include <wchar.h>
#include <locale>

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "");
	char char_str[] = "我是中国人";
	wchar_t wchar_str[] = L"我是中国人"; 
	char16_t char16_str[] = u"jcheng lau";
	char32_t char32_str[] = U"jcheng lau";

	printf("char\t%s, size %d\n", char_str, sizeof(char_str));
	wprintf(L"wchar_t\t%s size %d\n", wchar_str, sizeof(wchar_str));
//	printf("char16_str\t%s size %d\n", char16_str, sizeof(char16_str));
	wprintf(L"char32_str\t%s size %d\n", char32_str, sizeof(char32_str));

	int wchar_str_length = sizeof(wchar_str)/sizeof(wchar_str[0]);
	std::wcout << wchar_str << wchar_str_length << std::endl;
	for (int index = 0; index < wchar_str_length; ++index){
		wchar_t ch = wchar_str[index];
		wprintf(L"%c ", ch);
	}
	puts("");

	wprintf(L"我是中国人\n");
	wprintf(L"ab我是中国人\n");
	wprintf(L"abc\n");

	std::cout << R"(raw string 
		raw string)" << std::endl;

	return 0;
}
