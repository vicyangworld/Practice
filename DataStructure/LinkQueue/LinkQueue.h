#ifndef _H_LINKQUEUE_
#define _H_LINKQUEUE_ 1000

#include <stdlib.h>
#include <iostream>
#include "QueueNode.h"

using std::cout;
using std::endl;

template<typename T> class LinkQueue
{
private:
	QueueNode<T> *m_prear;
	QueueNode<T> *m_pfront;
	int m_nLength;
public:
	LinkQueue():m_prear(NULL),m_pfront(NULL),m_nLength(0){}
	~LinkQueue(){
		MakeEmpty();
	}
	void Append(const T item);
	T Delete();
	T GetFront();
	void MakeEmpty();
	void Print();
	int IsEmpty() const{
		return m_pfront == NULL;
	}
	int Length(){
		return m_nLength;
	}
};

template<typename T> void LinkQueue<T>::MakeEmpty(){
	QueueNode<T> *pdel;
	while(m_pfront){
		pdel = m_pfront;
		m_pfront = m_pfront->m_pnext;
		delete pdel;
	}
	m_nLength = 0;
}

template<typename T> void LinkQueue<T>::Append(const T item){
	if (m_pfront==NULL)
	{
		m_pfront = new QueueNode<T>(item);
		m_prear = m_pfront;
	}
	else
	{
		m_prear->m_pnext = new QueueNode<T>(item);
		m_prear = m_prear->m_pnext;
	}
	m_nLength++;
}

template<typename T> T LinkQueue<T>::Delete(){
	if (IsEmpty())
	{
		cout<<"There is no element!"<<endl;
		exit(1);
	}
	QueueNode<T> *pdel = m_pfront;
	T temp = m_pfront->m_data;
	m_pfront = m_pfront->m_pnext;
	delete pdel;
	m_nLength--;
	return temp;
}

template<typename T> T LinkQueue<T>::GetFront(){
	if (IsEmpty())
	{
		cout<<"There is no element!"<<endl;
		exit(1);
	}
	return m_pfront->m_data;
}

template<typename T> void LinkQueue<T>::Print(){
	QueueNode<T> *pmove = m_pfront;
	cout<<"fron";
	while(pmove){
		cout<<"-->"<<pmove->m_data;
		pmove = pmove->m_pnext;
	}
	cout<<"-->rear"<<endl<<endl;
}

#endif