#ifndef _H_SEQSTACK_
#define _H_SEQSTACK_

#include <stdlib.h>
using std::cout;
using std::endl;
template<typename T> class SeqStack
{
private:
	int m_nTop;
	T *m_pEleemnts;
	int m_nMaxSize;
public:
	SeqStack(int sx):m_nTop(-1),m_nMaxSize(sx){
		m_pEleemnts = new T[sx];
		if (m_pEleemnts == NULL)
		{
			cout<<"Application Error"<<endl;
			exit(1);
		}
	}
	~SeqStack(){
		delete[] m_pEleemnts;
	}
public:
	void Push(const T item);
	T Pop();
	T GetTop() const;
	int Length() const;
	void Print();
	void MakeEmpty(){
		m_nTop = -1;
	}
	bool IsEmpty() const{
		return m_nTop == -1;
	}
	bool IsFull() const{
		return m_nTop == m_nMaxSize - 1;
	}
};

template<typename T> void SeqStack<T>::Push(const T item)
{
	if (IsFull())
	{
		cout<<"The stack is full!"<<endl;
		return;
	}
	m_pEleemnts[++m_nTop]=item;
}

template<typename T> T SeqStack<T>::Pop(){
	if (IsEmpty())
	{
		cout<<"There is no element"<<endl;
		exit(1);
	}
	return m_pEleemnts[m_nTop--];
}

template<typename T> T SeqStack<T>::GetTop() const{
	if (IsEmpty())
	{
		cout<<"There is no element"<<endl;
		exit(1);
	}
	return m_pEleemnts[m_nTop];
}

template<typename T> void SeqStack<T>::Print(){
	cout<<"bottom";
	for (int i = 0; i < m_nTop; ++i)
	{
		cout<<"-->"<<m_pEleemnts[i];
	}
	cout<<"-->top"<<endl<<endl;
}

template<typename T> int SeqStack<T>::Length() const{
	return m_nTop+1;
}

#endif