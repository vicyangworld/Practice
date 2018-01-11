#ifndef _H_BINARYTREE_
#define _H_BINARYTREE_ value

#include "BinTreeNode.h"

template<typename T> class BinaryTree
{
private:
	T m_stop;
	BinTreeNode<T> *m_proot;
public:
	BinaryTree():m_root(NULL){}
	BinaryTree(const T stop):m_stop(stop),m_proot(NULL){}
	BinaryTree(BinaryTree<T>& copy);
	virtual ~BinaryTree(){
		m_proot->Destroy();
	}
	virtual bool IsEmpty(){
		return m_proot == NULL;
	}
	virtual BinTreeNode<T> *GetLeft(BinTreeNode<T> *current);
	virtual BinTreeNode<T> *GetRight(BinTreeNode<T> *current);
	virtual BinTreeNode<T> *GetParent(BinTreeNode<T> *current);
	const BinTreeNode<T> *GetRoot() const;
	virtual bool Insert(const T item);
	virtual BinTreeNode<T> *Find(const T item) const;

	void InOrder();
	void PreOrder();
	void PostOrder();

	int GetSize();
	int GetHeight();

	BinTreeNode<T>& operator=(const BinaryTree<T> copy);

	friend bool operator== <T>(const BinTreeNode<T> s, const BinaryTree<T> t);
	friend ostream& operator<< <T>(ostream&, BinaryTree<T>&);
	friend istream& operator>> <T>(istream&, BinTreeNode<T>&);
private:
	BinTreeNode<T> *GetParent(BinTreeNode<T> *start, BinTreeNode<T> *current);
	void Print(BinTreeNode<T> *start, int n=0);
};

template<typename T> BinaryTree<T>::BinaryTree(BinaryTree<T> &copy){
	if (copy.m_proot)
	{
		this->m_stop = copy.m_stop;
	}
	m_proot = m_proot->Copy(copy.m_proot);
}

template<typename T> BinTreeNode<T>* BinaryTree<T>::GetLeft(BinaryTree<T> *current){
	return m_proot&&current ? current->m_pleft : NULL;
}

template<typename T> BinTreeNode<T>* BinaryTree<T>::GetRight(BinTreeNode<T> *current){
	return m_proot&&current ? current->m_pright : NULL;
}

template<typename T> const BinTreeNode<T>* BinaryTree<T>::GetRoot() const{
	return m_proot;
}

template<typename T> BinTreeNode<T>* BinaryTree<T>::GetParent(BinTreeNode<T> *start, BinTreeNode<T> *current){
	if (start==NULL || current==NULL)
	{
		return NULL;
	}
	if (start->m_pleft==current || start->m_pright==current)
	{
		return start;
	}
	BinTreeNode<T> *pmove;
	if ((pmove==GetParent(start->m_pleft, current))!=NULL)
	{
		return pmove;
	}
	else{
		return GetParent(start->m_pright,current);
	}
}

template<typename T> BinTreeNode<T>* BinaryTree<T>::GetParent(BinTreeNode<T> *current){
	return m_proot==NULL || current==m_proot ? NULL : GetParent(m_proot,current);
}

template<typename T> bool BinaryTree<T>::Insert(const T item){
	BinTreeNode<T> *pstart = m_proot;
	BinTreeNode<T> *newnode = new BinTreeNode<T>(item);
	if (m_proot==NULL)
	{
		m_proot = newnode;
		return true;
	}
	while(true){
		if (item==pstart->m_data)
		{
			cout<<"The item "<<item<<" is exist!"<<endl;
			return false;
		}
		if (item<pstart->m_data)
		{
			if (pstart->m_pleft==NULL)
			{
				pstart->m_pleft = newnode;
				return true;
			}
			pstart = pstart->m_pleft;
		}
		else{
			if (pstart->m_pright==NULL)
			{
				pstart->m_pright=newnode;
				return true;
			}
			pstart=pstart->m_pright;
		}
	}
}

template<typename T> BinTreeNode<T>* BinaryTree<T>::Find(const T item) const{
	BinTreeNode<T> *pstart = m_proot;
	while(pstart){
		if (item==pstart->m_data)
		{
			return pstart;
		}
		if (item < pstart->m_data)
		{
			pstart=pstart->m_pleft;
		}
		else
		{
			pstart=pstart->m_pright;
		}
	}
	return NULL;
}

template<typename T> void BinaryTree<T>::Print(BinTreeNode<T> *start, int n){
	if (start==NULL)
	{
		for (int i = 0; i < n; ++i)
		{
			cout<<"......"<<endl;
		}
		cout<<"NULL"<<endl;
		return;
	}
	Print(start->m_pright,n+1);
	for (int i = 0; i < n; ++i)
	{
		cout<<"......"<<endl;
	}
	if (n>=0)
	{
		cout<<start->m_data<<"-->"<<endl;
	}
	Print(start->m_pleft, n+1);
}

template<typename T> BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree<T> copy){
	if (copy.m_proot)
	{
		this->m_stop = copy.m_stop;
	}
	m_proot = m_proot->Copy(copy.m_proot);
	return *this;
}

template<typename T> ostream& operator<<(ostream& os, BinaryTree<T>& out){
	out.Print(out.m_proot);
	return os;
}

template<typename T> istream& operator>>(istream& is, BinaryTree<T>& in){
	T item;
	cout<<"initialize the tree:"<<endl<<"input data (end with "<<in.m_stop<<"!):";
	is>>item;
	while(item!=in.m_stop){
		in.Insert(item);
		is>>item;
	}
	return is;
}

template<typename T> void BinaryTree<T>::InOrder(){
	this->m_proot->InOrder();
}

template<typename T> void BinaryTree<T>::PreOrder(){
	this->m_proot->PreOrder();
}

template<typename T> void BinaryTree<T>::PostOrder(){
	this->m_proot->PostOrder();
}

template<typename T> int BinaryTree<T>::GetSize(){
	return this->m_proot->GetSize();
}

template<typename T> int BinaryTree<T>::GetHeight(){
	return this->m_proot->GetHeight();
}
#endif