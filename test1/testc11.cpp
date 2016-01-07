 /********************************************************************
 # File Name:    testc11.cpp
 # Version:      1.0
 # Mail:         jchenglau@163.com 
 # Created Time: 2015-11-18
 *********************************************************************/

#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;


int main(int argc, char* argv[])
{
	int nData[] = {
		1, 2, 3, 4, 5
	};

	cout << typeid(nData).name() << endl;
	decltype(nData) nArray;
	cout << typeid(nArray).name() << endl;

	for(auto iter: nData)
	{

		cout << iter << endl;
	}

	return 0;
}

