#include "ListNode.h"
template<typename T> class DuLinkList{
private:
	ListNode<T> *head;
	int m_nLength;
public:
	DuLinkList():head(new ListNode<T>()),m_nLength(0){
		head->m_pprior = head;
		head->m_pnext  = head;
	}
	~DuLinkList(){
		MakeEmpty();
		delete head;
	}
public:
	void MakeEmpty();
	int Length();
	ListNode<T> *Find(int n=0);
	ListNode<T> *FindData(T item);
	bool Insert(T item, int n=0);
	T GetData(int n=0);
	T Remove(int n=0);
	void Print();
};

template<typename T> void DuLinkList<T>::MakeEmpty(){
	ListNode<T> *pmove = head->m_pnext;
	ListNode<T> *pdel;
	while(pmove != head)
	{
		pdel = pmove;
		pmove = pmove->m_pnext;
		delete pdel;
	}
	head->m_pnext  = head;
	head->m_pprior = head;
	m_nLength = 0;
}

template<typename T> int DuLinkList<T>::Length()
{
	// ListNode<T> *pprior = head->m_pprior;
	// ListNode<T> *pnext  = head->m_pnext;
	// int count = 0;
	// while(true)
	// {
	// 	if (pprior->m_pnext == pnext)
	// 	{
	// 		break;
	// 	}
	// 	if (pprior==pnext && pprior!=head)
	// 	{
	// 		count++;
	// 		break;
	// 	}
	// 	count += 2;
	// 	pprior = pprior->m_pprior;
	// 	pnext  = pnext->m_pnext;
	// }
	// return count;
	return m_nLength;
}

template<typename T> ListNode<T>* DuLinkList<T>::Find(int n){
	if (n<0)
	{
		std::cout<<"The n is out of boundary"<<std::endl;
		return NULL;
	}
	ListNode<T>*pmove = head->m_pnext;
	for (int i = 0; i < n; ++i)
	{
		pmove = pmove->m_pnext;
		if (pmove == head)
		{
			std::cout<<"The n is out of boundary"<<std::endl;
			return NULL;
		}
	}
	return pmove;
}

template<typename T> ListNode<T>* DuLinkList<T>::FindData(T item)
{
	ListNode<T> *pprior = head->m_pprior;
	ListNode<T> *pnext  = head->m_pnext;
	while(pprior->m_pnext != pnext && pprior != pnext)
	{
		if (pprior->m_data == item)
		{
			return pprior;
		}
		if (pnext->m_data == item)
		{
			return pnext;
		}
		pprior=pprior->m_pprior;
		pnext = pnext->m_pnext;
	}
	std::cout<<"Can't find the element"<<std::endl;
	return NULL;
}

template<typename T> bool DuLinkList<T>::Insert(T item, int n)
{
	if (n<0)
	{
		std::cout<<"The n is out of boundary"<<std::endl;
		return false;
	}
	ListNode<T> *newnode = new ListNode<T>(item);
	ListNode<T> *pmove = head;
	if (newnode == NULL)
	{
		std::cout<<"Application Error!"<<std::endl;
		exit(1);
	}
	for (int i = 0; i < n; ++i)
	{
		pmove = pmove->m_pnext;
		if (pmove == head)
		{
			std::cout << "The n is out of boundary"<<std::endl;
			return false;
		}
	}
	newnode->m_pnext = pmove->m_pnext;
	newnode->m_pprior= pmove;
	pmove->m_pnext   = newnode;
	newnode->m_pnext->m_pprior = newnode;
	m_nLength++;
	return true;
}

template<typename T> T DuLinkList<T>::Remove(int n)
{
	if (n<0)
	{
		std::cout<<"The n is out of boundary"<<std::endl;
		exit(1);
	}
	ListNode<T> *pmove = head;
	ListNode<T> *pdel;
	for (int i = 0; i < n; ++i)
	{
		pmove = pmove->m_pnext;
		if (pmove == head)
		{
			std::cout<<"The n is out of boundary"<<std::endl;
			exit(1);
		}
	}

	pdel = pmove;
	pmove->m_pprior->m_pnext = pmove->m_pnext;
	pmove->m_pnext->m_pprior = pmove->m_pprior;
	T temp = pdel->m_data;
	delete pdel;
	m_nLength--;
	return temp;
}

template<typename T> T DuLinkList<T>::GetData(int n)
{
	if (n<0)
	{
		std::cout<<"The n is out of boundary"<<std::endl;
		exit(1);
	}
	ListNode<T> *pmove = head;
	for (int i = 0; i < n; ++i)
	{
		pmove = pmove->m_pnext;
		if (pmove==head)
		{
			std::cout<<"The n is out of boundary"<<std::endl;
			exit(1);
		}
	}
	return pmove->m_data;
}

template<typename T> void DuLinkList<T>::Print()
{
	ListNode<T> *pmove = head->m_pnext;
	std::cout<<"head";
	while(pmove != head)
	{
		std::cout<<"-->"<<pmove->m_data;
		pmove = pmove->m_pnext;
	}
	std::cout<<"-->over"<<std::endl<<std::endl;
}