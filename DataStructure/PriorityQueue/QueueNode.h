#ifndef _H_QUEUENODE_
#define _H_QUEUENODE_ value

template<typename T, typename CMP> class PriorityQueue;

template<typename T, typename CMP> class QueueNode
{
private:
	T m_data;
	QueueNode<T,CMP> *m_pnext;
private:
	friend class PriorityQueue<T,CMP>;
	QueueNode(const T item, QueueNode<T,CMP> *next=NULL):m_data(item),m_pnext(next){}
	~QueueNode(){}
};

#endif