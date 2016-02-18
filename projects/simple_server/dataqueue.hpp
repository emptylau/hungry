#ifndef _DATAQUEUE_H_
#define _DATAQUEUE_H_

template <class M>
struct QueueData{
	QueueData* next;
	M* data;

	QueueData(){
		next = nullptr;
		data = nullptr;
	}

	QueueData(M* data_):data(data_){
		next = nullptr;
	}

	~QueueData(){
		if (data){
			delete data;
			data = nullptr;
		}
	}
};

template <class T=QueueData<int>>
class Queue
{
public:
	Queue();
	~Queue();

	bool push(T* data);
	bool pop(T*& data);

	T* front();
	T* back();

	int size();
	bool empty();

	

private:
	T* m_pHeadNode;
	T* m_pTailNode;

	int m_nSize;
};


template <class T>
Queue<T>::Queue()
	:m_pHeadNode(nullptr)
	 ,m_pTailNode(nullptr)
	 ,m_nSize(0)
{

}

template <class T>
Queue<T>::~Queue(){

	T* tmp = nullptr;
	while (m_pHeadNode){
		tmp = m_pHeadNode;
		m_pHeadNode = m_pHeadNode->next;

		delete tmp;
	}
}

template <class T>
bool Queue<T>::push(T* data){

	if (data) {

		if (m_pTailNode){
			m_pTailNode->next = data;
		}

		m_pTailNode = data;

		if (!m_pHeadNode){
			m_pHeadNode = data;
		}

		++m_nSize;
		
		return true;
	}

	return false;
}

template <class T>
bool Queue<T>::pop(T*& data){

	if (m_pHeadNode){

		data = m_pHeadNode;
		if (m_pHeadNode == m_pTailNode){
			m_pTailNode = nullptr;
		}
		m_pHeadNode = m_pHeadNode->next;

		--m_nSize;

		return true;
	}

	return false;
}

template <class T>
T* Queue<T>::front(){
	return m_pHeadNode;
}

template <class T>
T* Queue<T>::back(){
	return m_pTailNode;
}

template <class T>
bool Queue<T>::empty(){
	return 0 == m_nSize;
}

template <class T>
int Queue<T>::size(){
	return m_nSize;
}

#endif //!_DATAQUEUE_H_
