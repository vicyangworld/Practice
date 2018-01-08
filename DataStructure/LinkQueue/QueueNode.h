#ifndef _H_QUEUENODE_
#define _H_QUEUENODE_ value

template<typename T> class LinkQueue;
template<typename T> class QueueNode
{
private:
	T m_data;
	QueueNode<T> *m_pnext;
private:
	friend class LinkQueue<T>;
	QueueNode(const T item, QueueNode<T> *next=NULL):m_data(item),m_pnext(next){}
	~QueueNode(){}
};

#endif
