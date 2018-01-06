#include <stdlib.h>
#include "ListNode.h"

using std::cout;
using std::endl;

template<typename T> class CircularList{
private:
	ListNode<T> *head;
	int m_nLength;
public:
	CircularList():head(new ListNode<T>()),m_nLength(0){
		head->m_pnext = head;
	}
	~CircularList(){
		MakeEmpty();
		delete head;
	}
public:
	void MakeEmpty();
	int Length();
	ListNode<T> *Find(T value, int n);
	ListNode<T> *Find(int n);
	bool Insert(T item, int n=0);
	T Remove(int n=0);
	bool RemoveAll(T item);
	T GetData(int n);
	void Print();
};

template<typename T> void CircularList<T>::MakeEmpty(){
	ListNode<T> *pdel;
	ListNode<T> *pmove = head;
	while(pmove->m_pnext != head){
		pdel = pmove->m_pnext;
		pmove->m_pnext = pdel->m_pnext;
		delete pdel;
	}
	m_nLength = 0;
}

template<typename T> int CircularList<T>::Length(){
	// ListNode<T> *pmove = head;
	// int count = 0;
	// while(pmove->m_pnext != head){
	// 	pmove = pmove->m_pnext;
	// 	count++;
	// }
	// return count;
	return m_nLength;
}

template<typename T> ListNode<T> *CircularList<T>::Find(int n){
	if (n<0)
	{
		cout<<"The n is out of boundary"<<endl;
		return NULL;
	}
	ListNode<T> *pmove = head->m_pnext;
	for (int i = 0; i<n&&pmove!=head; ++i)
	{
		pmove = pmove->m_pnext;
	}
	if (pmove == head)
	{
		cout<<"The n is out of boundary"<<endl;
		return NULL;
	}
	return pmove;
}

template<typename T> ListNode<T>* CircularList<T>::Find(T value, int n){
	if (n<1)
	{
		cout<<"The n is illegal"<<endl;
		return NULL;
	}
	ListNode<T>* pmove=head;
	int count=0;
	while(count != n){
		pmove = pmove->m_pnext;
		if (pmove->m_data == value)
		{
			count++;
		}
		if (pmove==head && count==0)
		{
			cout<<"Can't find the element"<<endl;
			return NULL;
		}
	}
	return pmove;
}

template<typename T> bool CircularList<T>::Insert(T item, int n)
{
	if (n<0)
	{
		cout<<"The n is out of boundary"<<endl;
		return false;
	}
	ListNode<T> *pmove = head;
	ListNode<T> *pnode = new ListNode<T>(item);
	if (pnode == NULL)
	{
		cout<<"Application error!"<<endl;
		exit(1);
	}
	for (int i = 0; i < n; ++i)
	{
		pmove = pmove->m_pnext;
		if (pmove == head)
		{
			cout << "The n is out of boundary"<<endl;
			return false;
		}
	}
	pnode->m_pnext = pmove->m_pnext;
	pmove->m_pnext = pnode;
	m_nLength++;
	return true;
}

template<typename T> bool CircularList<T>::RemoveAll(T item)
{
	ListNode<T> *pmove=head;
	ListNode<T> *pdel=head->m_pnext;
	while(pdel !=head )
	{
		if (pdel->m_data == item)
		{
			pmove->m_pnext = pdel->m_pnext;
			delete pdel;
			pdel = pmove->m_pnext;
			m_nLength--;
			continue;
		}
		pmove = pmove->m_pnext;
		pdel=pdel->m_pnext;
	}
	return true;
}

template<typename T> T CircularList<T>::Remove(int n)
{
	if (n<0)
	{
		cout<<"Can't find the element"<<endl;
		exit(1);
	}
	ListNode<T>* pmove=head;
	ListNode<T>* pdel;
	for (int i = 0; i<n&&pmove->m_pnext!=head; ++i)
	{
		pmove = pmove->m_pnext;
	}
	if (pmove->m_pnext == head)
	{
		cout<<"can't find the element"<<endl;
		exit(1);
	}
	pdel = pmove->m_pnext;
	pmove->m_pnext = pdel->m_pnext;
	T temp = pdel->m_data;
	m_nLength--;
	delete pdel;
	return temp;
}

template<typename T> T CircularList<T>::GetData(int n){
	if (n<0)
	{
		cout<<"The n is out of boundary"<<endl;
		exit(1);
	}
	ListNode<T> *pmove = head->m_pnext;
	for (int i = 0; i < n; ++i)
	{
		pmove=pmove->m_pnext;
		if (pmove==head)
		{
			cout<<"The n is out of boundary"<<endl;
			exit(1);
		}
	}
	return pmove->m_data;
}

template<typename T> void CircularList<T>::Print(){
	ListNode<T> *pmove = head->m_pnext;
	cout<<"head";
	while(pmove != head)
	{
		cout<<"-->"<<pmove->m_data;
		pmove = pmove->m_pnext;
	}
	cout<<"-->over"<<endl<<endl;
}
