#include "number.h"

Number::Number():m_data(0){

}

Number::Number(int data):m_data(data){

}

Number::~Number(){}

Number::operator int(){
	return m_data;
}

int Number::operator()(){
	return m_data;
}

int Number::value(){
	return m_data;
}
