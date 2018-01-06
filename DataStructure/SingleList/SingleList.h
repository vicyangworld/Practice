#include <stdlib.h>
#include "ListNode.h"
template<typename T>
class SingleList
{
public:
	SingleList():head(new ListNode<T>()),m_length(0){};
	~SingleList(){
		MakeEmpty();
		delete head;
	};
	void MakeEmpty();
	int Length();
	ListNode<T> *Find(T value, int n);
	ListNode<T> *Find(int n);
	bool Insert(T item, int n=0);
	T Remove(int n=0);
	bool RemoveAll(T item);
	T Get(int n);
	void Print();
private:
	ListNode<T> *head;
	int m_length;
};

template<typename T>
void SingleList<T>::MakeEmpty(){
	ListNode<T> *pdel;
	while(head->m_pnext != NULL)
	{
		pdel = head->m_pnext;
		head->m_pnext = pdel->m_pnext;
		delete pdel;
	}
	m_length = 0;
}

template<typename T>
int SingleList<T>::Length()
{
	return m_length;
}

template<typename T> 
ListNode<T> * SingleList<T>::Find(int n)
{
	if (n<0)
	{
		std::cout<<"The n is out of boundary"<<std::endl;
		return NULL;
	}
	ListNode<T> *pmove=head->m_pnext;
	for (int i = 0; i<n && pmove; ++i)
	{
		pmove=pmove->m_pnext;
	}
	if (pmove==NULL)
	{
		std::cout<<"The n is out of boundary"<<std::endl;
		return NULL;
	}
	return pmove;
}

template<typename T> ListNode<T>* SingleList<T>::Find(T value, int n)
{
	if (n<1)
	{
		std::cout<<"The n is illegal"<<std::endl;
		return NULL;
	}
	ListNode<T>* pmove=head;
	int count = 0;
	while(count != n && pmove)
	{
		pmove=pmove->m_pnext;
		if (pmove->m_data==value)
		{
			count++;
		}
	}
	if (pmove == NULL)
	{
		std::cout<<"Can't find the element"<<std::endl;
		return NULL;
	}
	return pmove;
}

template<typename T>
bool SingleList<T>::Insert(T item, int n)
{
	if (n<0)
	{
		std::cout<<"The n is illegal"<<std::endl;
		return false;
	}
	ListNode<T> *pmove = head;
	ListNode<T> *pnode = new ListNode<T>(item);
	if (pnode==NULL)
	{
		std::cout<<"Applocation error!"<<std::endl;
		return false;
	}
	for (int i = 0; i < n && pmove; ++i)
	{
		pmove=pmove->m_pnext;
	}
	if (pmove==NULL && m_length>0)
	{
		std::cout<<"the n is illegal"<<std::endl;
		return false;
	}
	pnode->m_pnext = pmove->m_pnext;
	pmove->m_pnext = pnode;
	m_length++;
	return true;
}

template<typename T>
bool SingleList<T>::RemoveAll(T item)
{
	ListNode<T> *pmove = head;
	ListNode<T> *pdel=head->m_pnext;
	while(pdel != NULL)
	{
		if (pdel->m_data==item)
		{
			pmove->m_pnext=pdel->m_pnext;
			delete pdel;
			pdel=pmove->m_pnext;
			continue;
		}
		pmove=pmove->m_pnext;
		pdel=pdel->m_pnext;
		m_length--;
	}
	return true;
}

template<typename T> 
T SingleList<T>::Remove(int n)
{
	if (n<0)
	{
		std::cout<<"can't find the element"<<std::endl;
		exit(1);
	}
	ListNode<T> *pmove=head;
	ListNode<T> *pdel;
	for (int i = 0; i < n && pmove->m_pnext; ++i)
	{
		pmove = pmove->m_pnext;
	}
	if (pmove->m_pnext==NULL)
	{
		std::cout<<"can't find the element"<<std::endl;
		exit(1);
	}
	pdel = pmove->m_pnext;
	pmove->m_pnext=pdel->m_pnext;
	T temp = pdel->m_data;
	m_length--;
	delete pdel;
	return temp;
}

template<typename T> T SingleList<T>::Get(int n)
{
	if (n<0)
	{
		std::cout<<"The n is out of boundary"<<std::endl;
		exit(1);
	}
	ListNode<T> *pmove = head->m_pnext;
	for (int i = 0; i < n; ++i)
	{
		pmove=pmove->m_pnext;
		if (NULL==pmove)
		{
			std::cout<<"The n is out of boundary"<<std::endl;
			exit(1);
		}
	}
	return pmove->m_data;
}

template<typename T>
void SingleList<T>::Print()
{
	ListNode<T> *pmove=head->m_pnext;
	std::cout<<"head";
	while(pmove)
	{
		// std::cout<<pmove;
		std::cout<<"->"<<pmove->m_data;
		pmove=pmove->m_pnext;
	}
	std::cout<<"-->over"<<std::endl;
}