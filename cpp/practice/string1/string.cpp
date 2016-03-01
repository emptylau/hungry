#include <iostream>
#include <cassert>
#include "string.h"

char* strcpy(char*, const char*);
size_t strlen(const char*);

String::String(){
	std::cout << "String::String()" << std::endl;
}

String::String(const char* cstr){

	std::cout << "String::String(const char*)" << std::endl;

	m_len = strlen(cstr);
	m_pData = new char[m_len+1];

	strcpy(m_pData, cstr);
}

String::String(const String& str){

	std::cout << "String::String(const String& str)" << std::endl;

	m_len = str.m_len;
	m_pData = new char[m_len+1];
	
	strcpy(m_pData, str.m_pData);
}

// 注意移动构造和拷贝构造的区别
String::String(String&& str){
	std::cout << "String::String(String&&)" << std::endl;

	m_len = str.m_len;
	m_pData = str.m_pData;
	str.m_pData = nullptr;
}

String::~String(){
	std::cout << "String::~String()" << std::endl;
	if (m_pData)
		delete[] m_pData;
}

// What's mean ?
String& String::operator=(const String& str){

	std::cout << "String::operator=(const String&)" << std::endl;

	if (this == &str){
		return *this;
	}

	if (0 == str.m_len){
		m_len = 0;	
		m_pData[0] = '\0';
	}
	else {
		m_len = str.m_len;
		
		if (!m_pData)
			delete []m_pData;

		m_pData = new char[m_len+1];
		strcpy(m_pData, str.m_pData);
	}

	return *this;

}

String& String::operator=(String&& str){
	std::cout << "String::operator=(String&&)" << std::endl;

	if (this == &str)
		return *this;

	m_len = str.m_len;
	m_pData = str.m_pData;
	str.m_pData = nullptr;
	str.m_pData = 0;

	return *this;
}

char& String::operator[](int idx){

	if (0 > idx ){
		idx = 0;
	}
	else if (idx > m_len){
		idx = m_len;
	}

	return m_pData[idx];
}

size_t String::size(){
	return m_len;
}

bool String::empty(){
	return 0 == m_len;
}

// std::string 是如何做到返回c-style string的？
const char* String::c_str(){
	return m_pData;
}

void String::reverse(){
	int first = 0;
	int last = m_len;

	while (first != last && first < --last){
		m_pData[first] ^= m_pData[last];
		m_pData[last] = m_pData[first] ^ m_pData[last];
		m_pData[first] = m_pData[first] ^ m_pData[last];
		++first;
	}
}

std::ostream& operator<<(std::ostream& os, const String& str){
	os << str.m_pData;	
	return os;
}

char* strcpy(char* pDest, const char* pSrc){

	assert(pDest && pSrc);

	char* orig = pDest;

	// '\0' 也不能忘记拷贝咯
	while ((*pDest++ = *pSrc++) != '\0');

	return orig;
}

size_t strlen(const char* str){

	if (!str) return 0;

	size_t len = 0;
	const char* p = str;
	while (*p++) ++len;
	return len;
}
