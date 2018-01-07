#ifndef _H_SEQQUEQUE_
#define _H_SEQQUEQUE_ 1000

#include <stdlib.h>

using std::cout;
using std::endl;

template<typename T> class SeqQueue
{
private:
	int m_nrear;
	int m_nfront;
	int m_ncount;
	int m_nMaxSize;
	T *m_pelements;
public:
	SeqQueue(int sx):m_nrear(0),m_nfront(0),m_ncount(0),m_nMaxSize(sx){
		m_pelements = new T[sx];
		if (m_pelements == NULL)
		{
			cout<<"Application Error!"<<endl;
			exit(1);
		}
	}
	~SeqQueue(){
		delete[] m_pelements;
	};
public:
	void MakeEmpty();
	bool IsEmpty();
	bool IsFull();
	int Length() const;
	bool Append(const T item);
	T Delete();
	T Get();
	void Print();
};

template<typename T> void SeqQueue<T>::MakeEmpty(){
	this->m_ncount = 0;
	this->m_nfront  = 0;
	this->m_nrear  = 0;
}

template<typename T> bool SeqQueue<T>::IsEmpty(){
	return m_ncount == 0;
}

template<typename T> bool SeqQueue<T>::IsFull(){
	return m_ncount == m_nMaxSize;
}

template<typename T> int SeqQueue<T>::Length() const{
	return m_ncount;
}

template<typename T> bool SeqQueue<T>::Append(const T item){
	if (IsFull())
	{
		cout<<"The queue is full!"<<endl;
		return false;
	}
	m_pelements[m_nrear] = item;
	m_nrear = (m_nrear+1)%m_nMaxSize;
	m_ncount++;
	return true;
}

template<typename T> T SeqQueue<T>::Delete(){
	if (IsEmpty())
	{
		cout<<"There is no element!"<<endl;
		exit(1);
	}
	T temp = m_pelements[m_nfront];
	m_nfront = (m_nfront+1) % m_nMaxSize;
	m_ncount--;
	return temp;
}

template<typename T> T SeqQueue<T>::Get(){
	if (IsEmpty())
	{
		cout<<"There is no element!"<<endl;
		exit(1);
	}
	return m_pelements[m_nfront];
}

template<typename T> void SeqQueue<T>::Print(){
	cout<<"front";
	for (int i = 0; i < m_ncount; ++i)
	{
		cout<<"-->"<<m_pelements[(m_nfront+i+m_nMaxSize) % m_nMaxSize];
	}
	cout<<"-->rear"<<endl<<endl;
}

#endif