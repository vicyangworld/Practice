#include <iostream>
#include <stdlib.h>
using std::cout;
using std::endl;

const int DefaultSize=100;
template <typename Type>
class SeqList{
private:
	Type *m_elements;
	const int m_nmaxsize;
	int m_ncurrentsize;
public:
	SeqList(int sz=DefaultSize) : m_nmaxsize(sz),m_ncurrentsize(0)
	{
		if (sz>0)
		{
			m_elements = new Type[m_nmaxsize];
		}
	}
	~SeqList()
	{
		delete[] m_elements;
	}
	int Length() const
	{
		return m_ncurrentsize;
	}
	int Find(Type x) const;
	bool IsElement(Type x) const;
	void Insert(Type x, int i);
	bool Remove(Type x);
	bool IsEmpty()
	{
		return m_ncurrentsize==0;
	}
	bool IsFull()
	{
		return m_ncurrentsize == m_nmaxsize;
	}
	Type Get(int i)
	{
		return i<0 || i>m_ncurrentsize ? (cout<<"can't find the element"<<endl,0) : m_elements[i];
	}
	void Print();
};

#include "Seqlist.cpp"