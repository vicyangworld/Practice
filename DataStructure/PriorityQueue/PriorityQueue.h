#ifndef _H_PRIORITYQUEUE_
#define _H_PRIORITYQUEUE_ 1000

#include "QueueNode.h"
#include "Compare.h"
#include <stdlib.h>

using std::cout;
using std::endl;

template<typename T, typename CMP> class PriorityQueue
{
private:
	QueueNode<T,CMP> *m_prear;
	QueueNode<T,CMP> *m_pfront;
	int m_nLength;
public:
	PriorityQueue():m_prear(NULL),m_pfront(NULL),m_nLength(0){}
	~PriorityQueue(){
		MakeEmpty();
	}
	void MakeEmpty();
	void Append(const T item);
	T Delete();
	T GetFront() const;
	void Print() const;
	int Length() const{
		return m_nLength;
	}
	bool IsEmpty() const{
		return m_pfront == NULL;
	}
};

template<typename T, typename CMP> void PriorityQueue<T,CMP>::MakeEmpty(){
	QueueNode<T,CMP> *pdel;
	while(m_pfront){
		pdel = m_pfront;
		m_pfront = m_pfront->m_pnext;
		delete pdel;
	}
	m_nLength = 0;
}

template<typename T,typename CMP> void PriorityQueue<T,CMP>::Append(const T item){
	if (m_pfront==NULL)
	{
		m_pfront = new QueueNode<T,CMP>(item);
		m_prear = m_pfront;
	}
	else{
		m_prear->m_pnext = new QueueNode<T,CMP>(item);
		m_prear = m_prear->m_pnext;
	}
	m_nLength++;
}

template<typename T,typename CMP>T PriorityQueue<T,CMP>::Delete(){
	if (IsEmpty())
	{
		cout<<"There is no element!"<<endl;
		exit(1);
	}
	QueueNode<T,CMP> *pdel = m_pfront;
	QueueNode<T,CMP> *pmove = m_pfront;
	while(pmove->m_pnext){
		if (CMP::lt(pmove->m_pnext->m_data, pdel->m_pnext->m_data))
		{
			pdel = pmove;
		}
		pmove = pmove->m_pnext;
	}
	bool bFirst = false;
	if (CMP::lt(m_pfront->m_data, pdel->m_pnext->m_data))
	{
		pdel = m_pfront;
		m_pfront = pdel->m_pnext;
	}
	pmove=pdel;
	pdel = pdel->m_pnext;
	pmove->m_pnext = pdel->m_pnext;

	T temp = pdel->m_data;
	delete pdel;
	m_nLength--;
	return temp;
}

template<typename T, typename CMP> T PriorityQueue<T,CMP>::GetFront() const{
	if (IsEmpty())
	{
		cout<<"There is no element!"<<endl;
		exit(1);
	}
	QueueNode<T,CMP> *pmin = m_pfront;
	QueueNode<T,CMP> *pmove= m_pfront->m_pnext;
	while(pmove){
		if (CMP::lt(pmove->m_data, pmin->m_data))
		{
			pmin = pmove;
		}
		pmove = pmove->m_pnext;
	}
	return pmin->m_data;
}

template<typename T, typename CMP> void PriorityQueue<T,CMP>::Print() const{
	QueueNode<T,CMP> *pmove = m_pfront;
	cout<<"front";
	while(pmove){
		cout<<"-->"<<pmove->m_data;
		pmove = pmove->m_pnext;
	}
	cout<<"-->rear"<<endl<<endl;
}
#endif