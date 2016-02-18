#ifndef _DATA_TYPE_H_
#define _DATA_TYPE_H_

#include <iostream>

class Integer {

public:
	Integer():m_nData(0){
	}

	Integer(int value):m_nData(value){

	}

	friend const Integer operator+(Integer&, Integer&);
	friend const Integer operator -(Integer&, Integer&);
	friend std::ostream& operator<<(std::ostream&, const Integer&);
	friend std::istream& operator>>(std::istream&, Integer&);

private:
	int m_nData;
};

const Integer operator +(Integer& val1, Integer& val2){
	return val1.m_nData + val2.m_nData;
}

const Integer operator -(Integer& val1, Integer& val2){
	return val1.m_nData - val2.m_nData;
}

std::ostream& operator <<(std::ostream& cout, const Integer& val){
	return cout << val.m_nData;
}

std::istream& operator >>(std::istream& cin, Integer& val){
	int data;
	cin >> data;
	val.m_nData = data;
	return cin;
}

#endif //!_DATA_TYPE_H_


