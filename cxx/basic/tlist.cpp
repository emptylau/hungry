#include <iostream>

struct ListElement{
	int data;
	struct ListElement* next;
};

class List{

public:
	void push(int data);
	int pop();

	int getSize(){
		return m_size;
	};

	bool isEmpty(){
		return 0 != m_size;
	};

private:
	ListElement* m_phead;
	ListElement* m_ptail;
	int m_size;
};


int main(int argc, char* argv[]){

	return 0;
}




