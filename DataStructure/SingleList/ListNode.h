#include <iostream>
template<typename T> class SingleList;
template<typename T> class ListNode
{
private:
	T m_data;
	ListNode *m_pnext;	
private:
	friend SingleList<T>;
	ListNode(){m_pnext=NULL;}
	ListNode(T item, ListNode<T> *next=NULL):m_data(item),m_pnext(next){}
	~ListNode(){m_pnext=NULL;}
	friend std::ostream& std::operator<<(std::ostream&,ListNode<T>*&);

public:
	T GetData();
};

template<typename T>
T ListNode<T>::GetData()
{
	return this->m_data;
}

template<typename T> std::ostream& std::operator<<(std::ostream& os, ListNode<T>*& out)
{
	os<<out->m_data;
	return os;
}
