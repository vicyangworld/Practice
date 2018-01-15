#ifndef _H_BINARYTREE
#define _H_BINARYTREE
#include "ThreadBTreeNode.h"
class BTree
{
private:
	BTreeNode* m_proot;
	int m_leafFlaf;
	BTreeNode* m_pre;
	BTreeNode *m_pBThead;
public:
	BTree():m_proot(NULL),m_leafFlaf(0),m_pre(NULL),m_pBThead(NULL){}
	BTree(int _flag):m_proot(NULL),m_leafFlaf(_flag),m_pre(NULL),m_pBThead(NULL){}
	~BTree(){
		if (m_pBThead)
		{
			delete m_pBThead;
		}
	}
	BTreeNode* getRoot() const{
		return m_proot;
	}
	//中序遍历(递归)
	void inOrder();
	//中序遍历(非递归)
	void NotReInOrder();
	//前序遍历(递归)
	void preOrder();
	//前序遍历(非递归)
	void NotRePreOrder();
	//后序遍历(递归)
	void postOrder();
	//后序遍历(非递归)
	void NotRePostOrder();
	//求结点个数
	int GetSize();
	//求叶子结点个数
	int GetLeaves();
	//求树高
	int GetHeight();
	//层次法求树高
	int layerHeight();
	void Create(int *itemArr, int num, int &index);
	void Destroy();
	void layerOrder();
	BTreeNode* GetParent(BTreeNode *);
	BTreeNode* Find(const int item) const;

	//Threading
	bool InOrderThreading();

protected:
	//中序遍历
	void inOrder(BTreeNode*);
	//前序遍历
	void preOrder(BTreeNode*);
	//后序遍历
	void postOrder(BTreeNode*);
	//结点个数
	int GetSize(BTreeNode*);
	//叶子结点
	int GetLeaves(BTreeNode*);
	//树高
	int GetHeight(BTreeNode*);
	void Create(BTreeNode *&node, int *itemArr, int num, int &index);
	void Destroy(BTreeNode *&node);
	BTreeNode* GetParent(BTreeNode *node,BTreeNode * current);
	BTreeNode* Find(BTreeNode*, const int item) const;
	void _InOrderThreading(BTreeNode *&p);
	void InOrderThreading_Print();
};

#endif