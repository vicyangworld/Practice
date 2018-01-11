#ifndef _H_BINTREENODE_
#define _H_BINTREENODE_ value

template<typename T> class BinaryTree;
template<typename T> class BinTreeNode
{
private:
	BinTreeNode<T> *m_pleft, *m_pright;
	T m_data;
public:
	friend class BinaryTree<T>;
	BinTreeNode():m_pleft(NULL),m_pright(NULL){}
	BinaryTree(T item, BinTreeNode<T> *left=NULL,BinTreeNode<T> *right=NULL)
		:m_data(item),m_pleft(left),m_pright(right){}
	~BinTreeNode();
	T GetData() const;
	BinTreeNode<T> *GetLeft() const;
	BinTreeNode<T> *GetRight() const;
	void SetData(const T data);
	void SetLeft(const BinTreeNode<T> *left);
	void SetRight(const BinTreeNode<T> *right);

	void InOrder();
	void PreOrder();
	void PostOrder();

	int GetSize();
	int GetHeight();
	BinTreeNode<T> *Copy(const BinTreeNode<T> *copy);
	void Destroy(){
		if (this!=NULL)
		{
			this->m_pleft->Destroy();
			this->m_pright->Destroy();
			delete this;
		}
	}
	friend bool equal<T>(const BinTreeNode<T> *s, const BinTreeNode<T> *t);
};

template<typename T> T BinTreeNode<T>::GetData() const{
	return this!=NULL?m_data:-1;
}

template<typename T> BinTreeNode<T>* BinTreeNode<T>::GetLeft() const{
	return this!=NULL ? m_pleft : NULL;
}

template<typename T> BinTreeNode<T>* BinTreeNode<T>::GetRight() const{
	return this!=NULL ? m_pright : NULL;
}

template<typename T> void BinTreeNode<T>::SetData(const T data){
	if (this!=NULL)
	{
		m_data = data;
	}
}

template<typename T> void BinTreeNode<T>::SetLeft(const BinTreeNode<T> *left){
	if (this!=NULL)
	{
		m_pleft = left;
	}
}


template<typename T> void BinTreeNode<T>::SetRight(const BinTreeNode<T> *right){
	if (this!=NULL)
	{
		m_pright = right;
	}
}

template<typename T> BinTreeNode<T>* BinTreeNode<T>::Copy(const BinTreeNode<T> *copy){
	if (copy == NULL)
	{
		return NULL;
	}
	BinTreeNode<T> *temp = new BinTreeNode<T>(copy->m_data);
	temp->m_pleft = Copy(copy->m_pleft);
	temp->m_pright= Copy(copy->m_pright);
	return temp;
}

template<typename T> bool equal(const BinTreeNode<T> *s, const BinTreeNode<T> *t){
	if (s==NULL && t==NULL)
	{
		return true;
	}
	if (s && t && s->m_data==t->m_data && equal(s->m_pleft,t->m_pleft) && equal(s->m_pright,t->m_pright))
	{
		return true;
	}
	return false;
}


template<typename T> void BinTreeNode<T>::InOrder(){
	if (this!=NULL)
	{
		this<<"--->"<<this->m_data;
		this->m_pright->InOrder();
	}
}

template<typename T> void BinTreeNode<T>::PreOrder(){
	if (this != NULL)
	{
		cout<<"-->"<<this->m_data;
		this->m_pleft->PreOrder();
		this->m_pright->PreOrder();
	}
}

template<typename T> void BinTreeNode<T>::PostOrder(){
	if (this!=NULL)
	{
		this->m_pleft->PostOrder();
		this->m_pright->PostOrder();
		cout<<"-->"<<this->m_data;
	}
}

template<typename T> int BinTreeNode<T>::GetSize(){
	if (this==NULL)
	{
		return 0;
	}
	return 1 + this->m_pleft->GetSize() + this->m_pright->GetSize();
}

template<typename T> int BinTreeNode<T>::GetHeight(){
	if (this->NULL)
	{
		return -1;
	}
	int lheight,rheight;
	lheight = this->m_pleft->GetHeight();
	rheight = this->m_pright->GetHeight();
	return 1 + (lheight>rheight ? lheight : rheight);
}
#endif