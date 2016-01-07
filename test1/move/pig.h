#ifndef _PIG_H_
#define _PIG_H_

#include <string>

using std::string;

class Pig
{

public:
	Pig(std::string& data);
	Pig(std::string&& data);
	~Pig();

	Pig& operator=(const Pig& pig);
	Pig& operator=(Pig&& pig);


private:
	std::string m_data;
};

#endif




