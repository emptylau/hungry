 /********************************************************************
 # File Name:    pig.cpp
 # Version:      1.0
 # Mail:         jchenglau@163.com 
 # Created Time: 2015-11-23
 *********************************************************************/

#include <iostream>
#include "pig.h"


Pig::Pig(std::string& data)
{
	std::cout << __FUNCTION__ << "&" << std::endl;
}

Pig::Pig(std::string&& data)
{
	std::cout << __FUNCTION__ << "&&" << std::endl;
}

Pig::~Pig(){

}

Pig& Pig::operator=(const Pig& pig)
{
	if (this != &pig) {
		this->m_data = pig.m_data;
	}

	std::cout << __FUNCTION__ << "&" << std::endl;

	return *this;
}

Pig& Pig::operator=(Pig&& pig)
{
	if (this != &pig){

		this->m_data = pig.m_data;
	}

	std::cout << __FUNCTION__ << "&&" << std::endl;

	return *this;
}





