#ifndef _H_BINARYTREE
#define _H_BINARYTREE
#include "BTreeNode.h"
class BTree
{
private:
	BTreeNode* m_proot;
	int m_leafFlaf;
public:
	BTree():m_proot(NULL),m_leafFlaf(0){}
	BTree(int _flag):m_proot(NULL),m_leafFlaf(_flag){}
	BTreeNode* getRoot() const{
		return m_proot;
	}
	//�������(�ݹ�)
	void inOrder();
	//�������(�ǵݹ�)
	void NotReInOrder();
	//ǰ�����(�ݹ�)
	void preOrder();
	//ǰ�����(�ǵݹ�)
	void NotRePreOrder();
	//�������(�ݹ�)
	void postOrder();
	//�������(�ǵݹ�)
	void NotRePostOrder();
	//�������
	int GetSize();
	//��Ҷ�ӽ�����
	int GetLeaves();
	//������
	int GetHeight();
	//��η�������
	int layerHeight();
	void Create(int *itemArr, int num, int &index);
	void Destroy();
	void layerOrder();
	BTreeNode* GetParent(BTreeNode *);
	BTreeNode* Find(const int item) const;

protected:
	//�������
	void inOrder(BTreeNode*);
	//ǰ�����
	void preOrder(BTreeNode*);
	//�������
	void postOrder(BTreeNode*);
	//������
	int GetSize(BTreeNode*);
	//Ҷ�ӽ��
	int GetLeaves(BTreeNode*);
	//����
	int GetHeight(BTreeNode*);
	void Create(BTreeNode *&node, int *itemArr, int num, int &index);
	void Destroy(BTreeNode *&node);
	BTreeNode* GetParent(BTreeNode *node,BTreeNode * current);
	BTreeNode* Find(BTreeNode*, const int item) const;
};

#endif