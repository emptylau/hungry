#ifndef _STRING_H_
#define _STRING_H_
#include <stddef.h>

class String
{
public:

	String() = default;
	explicit String(const char* cstr);
	explicit String(const String& str);
	~String();

	String& operator=(const String& str);
	char& operator[](int idx);

	friend std::ostream& operator<<(std::ostream& os, const String& str);

public:
	size_t size();
	bool   empty();
	void   reverse();
	const char* c_str();

private:
	char* m_pData;
	size_t m_len;
};

#endif 
