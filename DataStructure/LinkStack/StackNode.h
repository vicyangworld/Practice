#ifndef _H_STACKNODE_
#define _H_STACKNODE_ 1000
#include <stdlib.h>

template<typename T> class LinkStack;
template<typename T> class StackNode
{
private:
	T m_data;
	StackNode<T> *m_pnext;
public:
	friend class LinkStack<T>;
	StackNode(T dt, StackNode<T> *next=NULL):m_data(dt),m_pnext(next){};
	~StackNode(){};
};

#endif
