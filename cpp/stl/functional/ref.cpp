#include <iostream>
#include <functional>
#include <string>

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

	Data():flags(EMPTY){
	}

};

int main(int argc, char* argv[]){
	
//	Data data;

//	data.setVaule(1234);

	return 0;
}
