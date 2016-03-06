#include "list.h"
#include <iostream>


ListElement<T>* List::createNewElement(){
	ListElement<T>* p = new ListElement<T>();
	p->next = nullptr;
	return p;
}

void List::removeElement(ListElement<T>* p){
	delete p;
	p = nullptr;
}

List::List()
	:m_pHead(nullptr)
	 ,m_pTail(nullptr)
{

}

List::~List(){
	
	ListElement<T>* p = nullptr;
	while (m_pHead) {
		p = m_pHead;
		m_pHead = m_pHead->next;
		removeElement(p);
		--m_uSize;
	}

	std::cout << "size: " << m_uSize;
}

void List::push_back(const T& obj){

	ListElement<T>* pElem = createNewElement();
	assert(pElem);
	pElem->data = obj;

	if (!m_pHead){
		m_pHead = pElem;	
		m_pTail = pElem; 
	}
	else {

		m_pTail->next = pElem;
		m_pTail = pElem;
	}

	++m_uSize;
}

void List::push_back(T&& obj){
	ListElement<T>* pElem = createNewElement();
	assert(pElem);
	pElem->data = obj;

	if (!m_pHead){
		m_pHead = pElem;
		m_pTail = pElem;
	}
	else {
		m_pTail->next = pElem;
		m_pTail = pElem;
	}

	++m_uSize;
}

void List::push_front(const T& obj){

	ListElement<T>* pElem = createNewElement();
	assert(pElem);
	pElem->data = obj;

	if (!m_pHead){
		m_pHead = pElem;
		m_pTail = pElem;
	}
	else {
		pElem->next = m_pHead;
		m_pHead = pElem;
	}

	++m_uSize;
}

void List::push_front(T&& obj){
	ListElement<T>* pElem = createNewElement();
	assert(pElem);
	pElem->data = obj;

	if (!m_pHead){
		m_pHead = pElem;
		m_pTail = pElem;
	}
	else {
		pElem->next = m_pHead;
		m_pHead = pElem;
	}

	++m_uSize;
}

void List::pop_back(){

	if (m_pHead == m_pTail){ 
		if (m_pHead){
			removeElement(m_pTail);
			m_pHead = nullptr;
			m_pTail = nullptr;
		}
		else{
			return;
		}
	}
	else {

		ListElement<T>* p = m_pHead;
		while (p && p->next != m_pTail){
			p = p->next;	
		}

		removeElement(m_pTail);
		m_pTail = p;
		m_pTail->next = nullptr;
	}

	--m_uSize;
}

void List::pop_front(){
	if (m_pHead == m_pTail){
		if (m_pHead){
			removeElement(m_pHead);
			m_pHead = nullptr;
			m_pTail = nullptr;
		}
		else {
			return;
		}
	}
	else {
		ListElement<T>* p = m_pHead;
		m_pHead = m_pHead->next;
		removeElement(p);
	}
	--m_uSize;
}

Iterator List::insert(const Iterator& itr, const T& obj){

	ListElement<T>* p = m_pHead;
	while(p && p != itr){
		p = p->next;	
	}

	if (p){
		p = createNewElement();
		p->data = obj;

		p->next = itr->next;
		itr->next = p;

		if (itr == m_pTail){
			m_pTail = p;
		}

		++m_uSize;
		return p;
	}

	return nullptr;
}

Iterator List::insert(const Iterator& itr, T&& obj){

	if (!itr){
		return nullptr;
	}
	
	Iterator p = m_pHead;
	while (p && p != m_pTail){
		p = p->next;
	}

	if (p){
		p = createNewElement();
		p->data = obj;

		p->next = itr->next;
		itr->next = p;

		if (itr == m_pTail){
			m_pTail = p;
		}

		++m_uSize;
		return p;
	}

	return nullptr;
}

T& List::front(){
	return m_pHead;	
}

const T& List::front() const{
	return m_pHead;
}

T& List::back(){
	return m_pTail;
}

const T& List::back() const {
	return m_pTail;	
}

unsigned int List::size(){
	return m_uSize;
}

bool List::empty(){
	return (0 == m_uSize);
}



