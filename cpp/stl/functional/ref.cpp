#include <iostream>
#include <functional>
#include <string>

// ref 函数式编程中应用
using namespace std::placeholders;

const std::string DEFALUT("");

class String{
public:
	String() = default;
	String(const char* str):value(str){

	}

	String(const std::string& str):value(str){

	}

	operator const std::string&(){
		return value;
	}

private:
	std::string value;
};

class Data{
private:
	enum FLAGS{ EMPTY, INT, FLOAT, STRING};
	FLAGS flags;
	union {
		int nValue;
		float fValue;
		//String sValue;
	}v;

public:
	void setValue(int value){
		flags = INT;
		v.nValue = value;
	}

	void setValue(float value){
		flags = FLOAT;
		v.fValue = value;
	}
	/*
	void setValue(const String& value){
		flags = STRING;
		v.sValue = value;
	}
	*/

	explicit operator int(){
		if (flags != INT) 
			return 0;
		return v.nValue;
	}

	explicit operator float(){
		if (FLOAT != flags)
			return 0.f;
		return v.fValue;
	}

	/*
	explicit operator const std::string&(){
		if (STRING != flags)
			return DEFALUT;
		return v.sValue;
	}*/

	Data* operator&(){
		std::cout << "operator&()" << std::endl;
		return nullptr;
	}

	Data():flags(EMPTY){
	}

};

void plus(int& v, int& factor){ ++v += factor; }

int main(int argc, char* argv[]){
	
	Data data;
	data.setValue(1234);
	std::cout << "data:" << (int)data << std::endl;

	Data& rdata = data;
	rdata.setValue(0.3f);
	std::cout << "rdata:" << (float)rdata << std::endl;
	std::cout << "data:" << (int)data << std::endl;

	Data* ptr = std::addressof(data);
	if (ptr)
		std::cout << "ptr:" << (int)(*ptr) << std::endl;

	std::cout << "--------" << std::endl;
	int num = 10;
	auto func = std::bind(plus, _1, std::ref(num)); // 注意这里应用的作用
	int ret = 10;
	func(ret);
	std::cout << "ret:" << ret << std::endl;
	num++;
	ret = 10;
	func(ret);
	std::cout << "num++ ret:" << ret << std::endl;

	return 0;
}
