#ifndef _H_BINTREENODE_
#define _H_BINTREENODE_ 100001

using std::cout;
using std::endl;

template<typename T> class BinaryTree;
template<typename T> class BinaryTreeNode
{
private:
	BinaryTreeNode<T> *m_pleft, *m_pright;
	T m_data;
public:
	friend class BinaryTree<T>;
	friend bool Equal(const BinaryTreeNode<T> *s, const BinaryTreeNode<T> *t){
		if (s==NULL && t==NULL)
		{
			return true;
		}
		if (s && t && s->m_data==t->m_data && Equal(s->m_pleft,t->m_pleft) && Equal(s->m_pright,t->m_pright))
		{
			return true;
		}
		return false;
	}
	
	BinaryTreeNode():m_pleft(NULL),m_pright(NULL){}
	BinaryTreeNode(T item, BinaryTreeNode<T> *left=NULL,BinaryTreeNode<T> *right=NULL)
		:m_data(item),m_pleft(left),m_pright(right){}
	~BinaryTreeNode(){}
	T GetData() const;
	BinaryTreeNode<T> *GetLeft() const;
	BinaryTreeNode<T> *GetRight() const;
	void SetData(const T data);
	void SetLeft(const BinaryTreeNode<T> *left);
	void SetRight(const BinaryTreeNode<T> *right);

	void InOrder();
	void PreOrder();
	void PostOrder();

	int GetSize();
	int GetHeight();
	BinaryTreeNode<T> *Copy(const BinaryTreeNode<T> *copy);
	void Destroy();

};

template<typename T> T BinaryTreeNode<T>::GetData() const{
	return this!=NULL?m_data:-1;
}

template<typename T> BinaryTreeNode<T>* BinaryTreeNode<T>::GetLeft() const{
	return this!=NULL ? m_pleft : NULL;
}

template<typename T> BinaryTreeNode<T>* BinaryTreeNode<T>::GetRight() const{
	return this!=NULL ? m_pright : NULL;
}

template<typename T> void BinaryTreeNode<T>::SetData(const T data){
	if (this!=NULL)
	{
		m_data = data;
	}
}

template<typename T> void BinaryTreeNode<T>::SetLeft(const BinaryTreeNode<T> *left){
	if (this!=NULL)
	{
		m_pleft = left;
	}
}


template<typename T> void BinaryTreeNode<T>::SetRight(const BinaryTreeNode<T> *right){
	if (this!=NULL)
	{
		m_pright = right;
	}
}

template<typename T> BinaryTreeNode<T>* BinaryTreeNode<T>::Copy(const BinaryTreeNode<T> *copy){
	if (copy == NULL)
	{
		return NULL;
	}
	BinaryTreeNode<T> *temp = new BinaryTreeNode<T>(copy->m_data);
	temp->m_pleft = Copy(copy->m_pleft);
	temp->m_pright= Copy(copy->m_pright);
	return temp;
}


template<typename T> void BinaryTreeNode<T>::Destroy(){
	if (this!=NULL)
	{
		this->m_pleft->Destroy();
		this->m_pright->Destroy();
		delete this;
	}
}

// template<typename T> bool Equal(const BinaryTreeNode<T> *s, const BinaryTreeNode<T> *t){
// 	if (s==NULL && t==NULL)
// 	{
// 		return true;
// 	}
// 	if (s && t && s->m_data==t->m_data && Equal(s->m_pleft,t->m_pleft) && Equal(s->m_pright,t->m_pright))
// 	{
// 		return true;
// 	}
// 	return false;
// }


template<typename T> void BinaryTreeNode<T>::InOrder(){
	if (this!=NULL)
	{
		this->m_pleft->InOrder();
		cout<<"--->"<<this->m_data;
		this->m_pright->InOrder();
	}
}

template<typename T> void BinaryTreeNode<T>::PreOrder(){
	if (this != NULL)
	{
		cout<<"-->"<<this->m_data;
		this->m_pleft->PreOrder();
		this->m_pright->PreOrder();
	}
}

template<typename T> void BinaryTreeNode<T>::PostOrder(){
	if (this!=NULL)
	{
		this->m_pleft->PostOrder();
		this->m_pright->PostOrder();
		cout<<"-->"<<this->m_data;
	}
}

template<typename T> int BinaryTreeNode<T>::GetSize(){
	if (this==NULL)
	{
		return 0;
	}
	return 1 + this->m_pleft->GetSize() + this->m_pright->GetSize();
}

template<typename T> int BinaryTreeNode<T>::GetHeight(){
	if (this==NULL)
	{
		return -1;
	}
	int lheight,rheight;
	lheight = this->m_pleft->GetHeight();
	rheight = this->m_pright->GetHeight();
	return 1 + (lheight>rheight ? lheight : rheight);
}
#endif