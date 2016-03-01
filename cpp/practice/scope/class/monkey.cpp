#include "monkey.h"

int Monkey::type = 10; // 不需要加 static
//int Monkey::type = 10; // 不能重复初始化赋值 

int Monkey::getType(){
	return type;
}
