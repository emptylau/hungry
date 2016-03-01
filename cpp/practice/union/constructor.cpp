#include <iostream>

// 构造
union Data{
	int nValue;
	float fValue;	

	Data(float v){
		fValue = v;
	}

	Data(int v){
		nValue = v;
	}
};

class Number{
public:
	enum Flag{
		INT,
		FLT, 
	};
	Number(int v):data(v){
		flag = INT;
	}

	Number(float v):data(v){
		flag = FLT;
	}

	void print(){
		std::cout << "value: " 
			<< ((flag == INT) ? data.nValue: data.fValue) 
			<< std::endl;
	}

private:
	Data data;
	Flag flag;
};

int main(int argc, char* argv[]){

	Number num(20);
	num.print();

	Number real(20.1f);
	real.print();

	return 0;
}
