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
	cout<<"Can't find the element you want to find"<<endl;
	return -1;
}

template <typename Type>
bool SeqList<Type>::IsElement(Type x) const
{
	if (Find(x)==-1)
	{
		return false;
	}
	return true;
}

template <typename Type>
void SeqList<Type>::Insert(Type x, int i)
{
	if (i<0 || i>m_ncurrentsize)
	{
		cout<<"Insert location is wrong"<<endl;
		exit(1);
	}
	if (m_ncurrentsize==m_nmaxsize)
	{
		cout<<"List is full"<<endl;
		exit(1);
	}
	for (int j = m_ncurrentsize; j>i ; j--)
	{
		m_elements[j] = m_elements[j-1];
	}
	m_elements[i]=x;
	m_ncurrentsize++;
}

template<typename Type>
bool SeqList<Type>::Remove(Type x)
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
		cout<<"Can't find the element you want to remove."<<endl;
		return false;
	}
	return true;
}

template <typename Type>
void SeqList<Type>::Print()
{
	cout<<"------------"<<endl;
	for (int i = 0; i < m_ncurrentsize; ++i)
	{
		cout<<i+1<<":\t"<<m_elements[i]<<endl;
	}
	cout<<"------------"<<endl;
}
