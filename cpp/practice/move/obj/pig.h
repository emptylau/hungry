#ifndef _PIG_H_
#define _PIG_H_

#include <string>

using std::string;

class Pig
{

public:
	Pig(std::string& data);
	Pig(std::string&& data); // 移动构造
	~Pig();

	Pig& operator=(const Pig& pig);
	Pig& operator=(Pig&& pig); // 移动赋值

private:
	std::string m_data;
};

#endif




