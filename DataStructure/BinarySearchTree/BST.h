#ifndef _H_BINARYTREE_
#define _H_BINARYTREE_ 100000

#include <stdlib.h>
#include <math.h>
#include "BSTnode.h"
using std::cout;
using std::endl;
using std::ostream;
using std::istream;

static int s_idx = 0;
template<typename T> class BinaryTree
{
private:
	T m_stop;
	BinaryTreeNode<T> *m_proot;
public:
	BinaryTree():m_proot(NULL){}
	BinaryTree(const T stop):m_stop(stop),m_proot(NULL){}
	BinaryTree(BinaryTree<T>& copy);
	virtual ~BinaryTree(){
		m_proot->Destroy();
	}
	virtual bool IsEmpty(){
		return m_proot == NULL;
	}
	virtual BinaryTreeNode<T> *GetLeft(BinaryTreeNode<T> *current);
	virtual BinaryTreeNode<T> *GetRight(BinaryTreeNode<T> *current);
	virtual BinaryTreeNode<T> *GetParent(BinaryTreeNode<T> *current);
	const BinaryTreeNode<T> *GetRoot() const;
	virtual bool Insert(const T item);
	virtual BinaryTreeNode<T> *Find(const T item) const;
	void Create(const T* itemArr,int n);
	void Delete(const T item);

	void InOrder();
	void PreOrder();
	void PostOrder();

	int GetSize();
	int GetHeight();

	BinaryTree<T>& operator=(const BinaryTree<T> copy);

	friend bool operator==(const BinaryTree<T> s, const BinaryTree<T> t)
	{
		return Equal(s.m_proot, t.m_proot);
	}
	friend std::ostream& operator<<(std::ostream& os, BinaryTree<T>& out){
		out.InOrder(out.m_proot,1);
		return os;
	}
	friend std::istream& operator>>(std::istream& is, BinaryTree<T>& in){
		T item;
		cout<<"initialize the tree:"<<endl<<"input data (end with "<<in.m_stop<<"!):";
		is>>item;
		while(item!=in.m_stop){
			in.Insert(item);
			is>>item;
		}
		return is;
	}
private:
	BinaryTreeNode<T> *GetParent(BinaryTreeNode<T> *start, BinaryTreeNode<T> *current);
	void Print(BinaryTreeNode<T> *start, int n=0);
	void InOrder(BinaryTreeNode<T> *start, int level);
	void PreOrder(BinaryTreeNode<T> *start, int level);
	void PostOrder(BinaryTreeNode<T> *start, int level);
	void Delete(BinaryTreeNode<T> *&root, const T item);
};

template<typename T> BinaryTree<T>::BinaryTree(BinaryTree<T> &copy){
	if (copy.m_proot)
	{
		this->m_stop = copy.m_stop;
	}
	m_proot = m_proot->Copy(copy.m_proot);
}

template<typename T> BinaryTreeNode<T>* BinaryTree<T>::GetLeft(BinaryTreeNode<T> *current){
	return m_proot&&current ? current->m_pleft : NULL;
}

template<typename T> BinaryTreeNode<T>* BinaryTree<T>::GetRight(BinaryTreeNode<T> *current){
	return m_proot&&current ? current->m_pright : NULL;
}

template<typename T> const BinaryTreeNode<T>* BinaryTree<T>::GetRoot() const{
	return m_proot;
}

template<typename T> BinaryTreeNode<T>* BinaryTree<T>::GetParent(BinaryTreeNode<T> *start, BinaryTreeNode<T> *current){
	if (start==NULL || current==NULL)
	{
		return NULL;
	}
	if (start->m_pleft==current || start->m_pright==current)
	{
		return start;
	}
	BinaryTreeNode<T> *pmove;
	if ((pmove=GetParent(start->m_pleft, current))!=NULL)
	{
		return pmove;
	}
	else{
		return GetParent(start->m_pright,current);
	}
}

template<typename T> BinaryTreeNode<T>* BinaryTree<T>::GetParent(BinaryTreeNode<T> *current){
	return m_proot==NULL || current==m_proot ? NULL : GetParent(m_proot,current);
}

template<typename T> void BinaryTree<T>::Create(const T* itemArr, int n){
	if (m_proot != NULL)
	{
		cout<<"Wrong parameter fot create()"<<endl;
		return;
	}
	if (m_proot==NULL)
	{
		m_proot = new BinaryTreeNode<T>(itemArr[0]);
	}
	BinaryTreeNode<T> *pmove = m_proot;
	for (int i = 1; i < n; ++i)
	{
		pmove = m_proot;
		while(true){
			if (itemArr[i] == pmove->m_data)
			{
				//cout<<"The item "<<itemArr[idx]<<" is exist:"<<pmove->m_data<<endl;
				break;
			}
			if (itemArr[i] < pmove->m_data)
			{
				if (pmove->m_pleft==NULL)
				{
					pmove->m_pleft = new BinaryTreeNode<T>(itemArr[i]);
				}
				pmove = pmove->m_pleft;
			}
			else{
				if (pmove->m_pright==NULL)
				{
					pmove->m_pright = new BinaryTreeNode<T>(itemArr[i]);
				}
				pmove = pmove->m_pright;
			}			
		}
	}

	// while(idx < n){
	// 	if (itemArr[idx] == pmove->m_data)
	// 	{
	// 		cout<<"The item "<<itemArr[idx]<<" is exist:"<<pmove->m_data<<endl;
	// 		continue;
	// 	}
	// 	if (itemArr[idx] < pmove->m_data)
	// 	{
	// 		if (pmove->m_pleft==NULL)
	// 		{
	// 			pmove->m_pleft = new BinaryTreeNode<T>(itemArr[idx]);
	// 		}
	// 		pmove = pmove->m_pleft;
	// 	}
	// 	else{
	// 		if (pmove->m_pright==NULL)
	// 		{
	// 			pmove->m_pright = new BinaryTreeNode<T>(itemArr[idx]);
	// 		}
	// 		pmove=pstart->m_pright;
	// 	}
	// 	idx++;
	// }
}

template<typename T> bool BinaryTree<T>::Insert(const T item){
	BinaryTreeNode<T> *newnode = new BinaryTreeNode<T>(item);
	if (m_proot==NULL)
	{
		m_proot = newnode;
		return true;
	}
	BinaryTreeNode<T> *pstart = m_proot;

	while(true){
		if (item == pstart->m_data)
		{
			cout<<"The item "<<item<<" is exist:"<<pstart->m_data<<endl;
			return false;
		}
		if (item < pstart->m_data)
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
				pstart->m_pright = newnode;
				return true;
			}
			pstart=pstart->m_pright;
		}
	}
}

template<typename T> BinaryTreeNode<T>* BinaryTree<T>::Find(const T item) const{
	BinaryTreeNode<T> *pstart = m_proot;
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

template<typename T> void BinaryTree<T>::Print(BinaryTreeNode<T> *start, int n){
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

template<typename T> bool operator==(const BinaryTree<T> s, const BinaryTree<T> t){
	return equal(s.m_proot, t.m_proot);
}

template<typename T> void BinaryTree<T>::InOrder(BinaryTreeNode<T> *start, int level){
	if (start != NULL)
	{
		PreOrder(start->m_pleft,level+1);
		cout<<start->m_data<<" ";
		// cout<<start->m_data<<" at layer "<<level<<endl;
		PreOrder(start->m_pright,level+1);
	}

}
template<typename T> void BinaryTree<T>::InOrder(){
	InOrder(m_proot,1);
	cout<<endl;
}

template<typename T> void BinaryTree<T>::PreOrder(BinaryTreeNode<T> *start, int level){
	if (start != NULL)
	{
		// cout<<start->m_data<<" at layer "<<level<<endl;
		cout<<start->m_data<<" ";
		PreOrder(start->m_pleft,level+1);
		PreOrder(start->m_pright,level+1);
	}
}
template<typename T> void BinaryTree<T>::PreOrder(){
	PreOrder(m_proot,1);
	cout<<endl;
}

template<typename T> void BinaryTree<T>::PostOrder(BinaryTreeNode<T> *start, int level){
	if (start != NULL)
	{
		PreOrder(start->m_pleft,level+1);
		PreOrder(start->m_pright,level+1);
		// cout<<start->m_data<<" at layer "<<level<<endl;
		cout<<start->m_data<<" ";
	}	
}

template<typename T> void BinaryTree<T>::PostOrder(){
	PostOrder(m_proot,1);
	cout<<endl;
}

template<typename T> int BinaryTree<T>::GetSize(){
	return this->m_proot->GetSize();
}

template<typename T> int BinaryTree<T>::GetHeight(){
	return this->m_proot->GetHeight();
}

template<typename T> void BinaryTree<T>::Delete(const T item){
	Delete(m_proot,item);
}

template<typename T> void BinaryTree<T>::Delete(BinaryTreeNode<T> *&root,const T item)
{
	BinaryTreeNode<T> *pdel = root;
	BinaryTreeNode<T> *pleft = NULL;
	if (pdel == NULL)
	{
		cout<<"Not found item "<<item<<" to delete"<<endl;
		return;
	}
	if (pdel->m_data == item)
	{
		if (pdel->m_pright == NULL && pdel->m_pleft == NULL)
		{
			root = NULL;
			if(pdel) delete pdel;
			return;
		}
		else if(pdel->m_pright==NULL){   // m_pleft only
			root = pdel->m_pleft;
			if(pdel) delete pdel;
			return;
		}
		else if (pdel->m_pleft == NULL) // m_pright only
		{
			root = pdel->m_pright;
			if(pdel) delete pdel;
			return;
		}
		else{                            // both
			pleft = pdel->m_pright;     
			if (pleft->m_pleft == NULL)          //
			{
				pleft->m_pleft = pdel->m_pleft;
			}
			else
			{
				while(pleft->m_pleft != NULL){
					pleft  = pleft->m_pleft;
				}
			}
			pleft->m_pleft = pdel->m_pleft;
			pleft->m_pright= pdel->m_pright;
		}
		root = pleft;
		if(pdel) delete pdel;
		pdel = NULL;
		return;
	}
	else if(item > pdel->m_data)
	{
		Delete(pdel->m_pright,item);
	}
	else if(item < pdel->m_data){
		Delete(pdel->m_pleft,item);
	}
}
#endif