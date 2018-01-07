#ifndef _H_LINKSTACK_
#define _H_LINKSTACK_ 1000

#include <stdlib.h>
#include "StackNode.h"
using std::cout;
using std::endl;

template<typename T> class LinkStack
{
private:
	StackNode<T> *m_ptop;
	int m_nLength;
public:
	LinkStack():m_ptop(NULL),m_nLength(0){}
	~LinkStack(){
		MakeEmpty();
	}
public:
	void MakeEmpty();
	void Push(const T item);
	T Pop();
	T GetTop() const;
	int Length() const;
	void Print() const;
	bool IsEmpty() const{
		return m_ptop == NULL;
	}
};

template<typename T> void LinkStack<T>::MakeEmpty(){
	StackNode<T> *pmove;
	while(m_ptop != NULL){
		pmove = m_ptop;
		m_ptop = m_ptop->m_pnext;
		delete pmove;
	}
	m_nLength = 0;
}
template<typename T> T LinkStack<T>::GetTop() const{
	if (IsEmpty())
	{
		cout<<"There is no elements!"<<endl;
		exit(1);
	}
	return m_ptop->m_data;
}
template<typename T> void LinkStack<T>::Push(const T item){
	m_ptop = new StackNode<T>(item,m_ptop);
	m_nLength++;
}

template<typename T> T LinkStack<T>::Pop(){
	if (IsEmpty())
	{
		cout<<"There is no element"<<endl;
		exit(1);
	}
	StackNode<T> *pdel = m_ptop;
	m_ptop = m_ptop->m_pnext;
	T temp = pdel->m_data;
	delete pdel;
	m_nLength--;
	return temp;
}

template<typename T> int LinkStack<T>::Length() const{
	// int count=0;
	// StackNode<T> *pmove;
	// pmove = m_ptop;
	// while(pmove != NULL){
	// 	count++;
	// 	pmove = pmove->m_pnext;
	// }
	// return count;
	return m_nLength;
}

template<typename T> void LinkStack<T>::Print() const{
	StackNode<T> *pmove = m_ptop;
	cout<<"top";
	while(pmove != NULL){
		cout<<"-->"<<pmove->m_data;
		pmove = pmove->m_pnext;
	}
	cout<<"-->bottom"<<endl<<endl;
}
#endif
