#ifndef _H_BINARYTREENODE_
#define _H_BINARYTREENODE_

typedef struct BTreeNode
{
	int m_data;
	struct BTreeNode *m_lChild;
	struct BTreeNode *m_rChild;
}BTreeNode;

#endif