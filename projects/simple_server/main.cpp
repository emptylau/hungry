#include <iostream>
#include "dataqueue.hpp"

struct Integer{
	int data;

	Integer():data(0){
	}

	Integer(int data_):data(data_){
	}
};

int main(int argc, char* argv[]){

	if (argc < 3){
		std::cout << R"(usage: test [size] [start])" << std::endl;
		return 0;
	}

	int size = atoi(argv[1]);
	int start = atoi(argv[2]);

	Queue<QueueData<Integer>> que;

	Integer* tmp = nullptr;
	QueueData<Integer>* pNode = nullptr;
	for (int idx = start; idx < start+size; ++idx){
		tmp = new Integer(idx);
		pNode = new QueueData<Integer>(tmp);
		que.push(pNode);
	}

	while (que.pop(pNode)){
		tmp = (Integer*)pNode->data;
		std::cout << tmp->data << std::endl;
	}

	return 0;
}
