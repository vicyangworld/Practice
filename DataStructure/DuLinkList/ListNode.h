template<typename T> class DuLinkList;
template<typename T> class ListNode{
private:
	T m_data;
	ListNode *m_pprior;
	ListNode *m_pnext;
private:
	friend class DuLinkList<T>;
	ListNode():m_pprior(NULL),m_pnext(){}
	ListNode(const T item, ListNode<T> *prior=NULL, ListNode<T> *next=NULL):m_data(item),m_pprior(prior),m_pnext(next){}
	~ListNode(){
		m_pprior = NULL;
		m_pnext  = NULL;
	}
public:
	T GetData(){
		return m_data;
	}
};