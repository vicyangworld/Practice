template<typename T> class CircularList;
template<typename T> class ListNode{
private:
	T m_data;
	ListNode *m_pnext;
private:
	friend class CircularList<T>;
	ListNode():m_pnext(NULL){}
	ListNode(const T item, ListNode<T> *next=NULL):m_data(item),m_pnext(next){}
	~ListNode(){
		m_pnext = NULL;
	}
};