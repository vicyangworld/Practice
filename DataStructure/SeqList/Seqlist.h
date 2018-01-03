const int DefaultSize=100;

template <typename Type>
class SeqList{
public:
	SeqList(int sz=DefaultSize) : m_nmaxsize(sz),m_ncurrentsize(-1)
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
		return m_ncurrentsize+1
	}
	int Find(Type x) const;
	int IsElement(Type x) const;
	int Insert(Type x, int i);
	int Remove(Type x);
	int IsEmpty()
	{
		return m_ncurrentsize==-1;
	}
	int IsFull()
	{
		return m_ncurrentsize == m_nmaxsize-1;
	}
	Type Get(int i)
	{
		return i<0 || i>m_ncurrentsize ? (cout<<"can't find the element"<<endl,0) : m_elements[i];
	}
	void Print();
private:
	Type *m_elements;
	const int m_nmaxsize;
	int m_ncurrentsize;
};
