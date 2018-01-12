#ifndef _H_HEAP_
#define _H_HEAP_ value

using std::cout;
using std::endl;

template<typename T> class MinHeap
{
private:
	static const int nDefaultSize = 100;
	const int m_nMaxSize;
	T *m_pheap;
	int m_nCurrentSize;
public:
	MinHeap(int size):m_nMaxSize(size>nDefaultSize ? size : nDefaultSize),
			m_pheap(new T[m_nMaxSize]),m_nCurrentSize(0){}
	MinHeap(T heap[], int n);
	~MinHeap(){
		delete [] m_pheap;
	}

	bool Insert(const T item);
	bool Delete(const T item);
	bool IsEmpty() const{
		return m_nCurrentSize==0;
	}
	bool IsFull() const{
		return m_nCurrentSize==m_nMaxSize;
	}
	void Print(const int start=0, int n=0);
private:
	void Adjust(const int start, const int endd);
};

template<typename T> void MinHeap<T>::Adjust(const int start, const int end){
	int i = start;
	int j = i*2+1;
	T temp = m_pheap[i];
	while(j <= end){
		if (j<end && m_pheap[j]>m_pheap[j+1])
		{
			j++;
		}
		if (temp <= m_pheap[j])
		{
			break;
		}
		else
		{
			m_pheap[i] = m_pheap[j];
			i = j;
			j = 2*i+1;
		}
	}
	m_pheap[i] = temp;
}

template<typename T> MinHeap<T>::MinHeap(T heap[], int n):m_nMaxSize(n>nDefaultSize?n:nDefaultSize){
	m_pheap = new T[m_nMaxSize];
	for (int i = 0; i < n; ++i)
	{
		m_pheap[i]  = heap[i];
	}

	m_nCurrentSize = n;
	int pos = (n-2)/2;
	while(pos>=0){
		Adjust(pos,n-1);
		pos--;
	}
}

template<typename T> bool MinHeap<T>::Insert(const T item){
	if (m_nCurrentSize == m_nMaxSize)
	{
		cout<<"Heap Full!"<<endl;
		return false;
	}
	m_pheap[m_nCurrentSize] = item;
	int j = m_nCurrentSize;
	int i = (j-2)/2;
	T temp = m_pheap[j];
	while(j > 0){
		if (m_pheap[i] <= temp)
		{
			break;
		}
		else{
			m_pheap[j] = m_pheap[i];
			j = i;
			i = (j-1)/2;
		}
	}
	m_pheap[j] = temp;
	m_nCurrentSize++;
	return true;
}

template<typename T> bool MinHeap<T>::Delete(const T item){
	if (m_nCurrentSize == 0)
	{
		cout<<"Head Empty!"<<endl;
		return false;
	}
	for (int i = 0; i < m_nCurrentSize; ++i)
	{
		if (m_pheap[i] == item)
		{
			m_pheap[i] = m_pheap[m_nCurrentSize-1];
			Adjust(i,m_nCurrentSize-2);
			m_nCurrentSize--;
			i=0;
		}
	}
	return true;
}

template<typename T> void MinHeap<T>::Print(const int start, int n){
	if (start >= m_nCurrentSize)
	{
		return;
	}
	Print(start*2+2, n+1);
	for (int i = 0; i < n; ++i)
	{
		cout<<"   ";
	}
	cout<<m_pheap[start]<<"-->"<<endl;
	Print(start*2+1,n+1);
}
#endif