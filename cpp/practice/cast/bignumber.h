#ifndef _BIGNUMBER_H_
#define _BIGNUMBER_H_

class BigNumber: public Number{

public:
	BigNumber(int data):Number(data){}
	void desc(){
		std::cout << "class type: BigNumber" << std::endl;
	}

	void change(int data){
		m_data = data;
	}

};

#endif 
