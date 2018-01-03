#include "Seqlist.h"

template <typename Type>
int SeqList<Type>::Find(Type x) const
{
	for (int i = 0; i < m_ncurrentsize; ++i)
	{
		if (m_elements[i]==x)
		{
			return i;
		}
	}
	cout<<"can't find the element you want to find"<<endl;
	return -1;
}

template <typename Type>
int SeqList<Type>::IsElement(Type x) const
{
	if (Find(x)==-1)
	{
		return 0;
	}
	return 1;
}

template <typename Type>
int SeqList<Type>::Insert(Type x, int i)
{
	if (i<0 || i>m_ncurrentsize || m_ncurrentsize==m_nmaxsize-1)
	{
		cout<<"the operate is illegal"<<endl;
		return 0;
	}
	m_ncurrentsize++;
	for (int j = m_ncurrentsize; i >1 ; j--)
	{
		m_elements[i] = x;
	}
}

template<typename Type>
int SeqList<Type>::Remove(Type x)
{
	int size = m_ncurrentsize;
	for (int i = 0; i < m_ncurrentsize; ++i)
	{
		if (m_elements[i]==x)
		{
			for (int j = i; j < m_ncurrentsize; j++)
			{
				m_elements[j]=m_elements[j+1];
			}
			m_ncurrentsize--;
			continue;
		}
	}
	if (size==m_ncurrentsize)
	{
		cout<<"can't find the element you want to remove."<<endl;
		return 0;
	}
	return 1;
}

template <typename Type>
void SeqList<Type>::Print()
{
	for (int i = 0; i < m_ncurrentsize; ++i)
	{
		cout<<i+1<<":\t"<<m_elements[i]<<endl;
	}
	cout<<endl;
}
