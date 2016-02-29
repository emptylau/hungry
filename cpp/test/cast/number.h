#ifndef _NUMBER_H_
#define _NUMBER_H_

class Number{

public:
	Number();

	// 由于构造函数具有隐式类型转换功能，为了将转换控制在自己手上，使用explicit吧
	explicit Number(int);
	
	~Number();

public:
	// 类型转换函数
	operator int();

	// 注意区分这两种不同的操作
	int operator()();

	int value();

private:
	int m_data;
};


#endif
