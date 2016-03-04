#ifndef _LIST_H_
#define _LIST_H_

template <typename T>
struct ListElement{
	T data;
	ListElement* next;
};

template <typename T>
class List{
public:
	List();
	~List();


public:
	void push_back(T obj);
	void push_front(T obj);
	void pop_back();
	void pop_front();

	T& front();
	T& back();

	const T& front() const;
	const T& back() const;

private:
	ListElement<T>* m_pHead;
	ListElement<T>* m_pTail;

	int m_size;
};

#endif
