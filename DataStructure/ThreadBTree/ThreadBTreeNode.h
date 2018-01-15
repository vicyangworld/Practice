#ifndef _H_BINARYTREENODE_
#define _H_BINARYTREENODE_

typedef enum {Link, Thread} PointTag;
typedef struct BTreeNode
{
	int m_data;
	struct BTreeNode *m_lChild;
	struct BTreeNode *m_rChild;
	PointTag m_lTag;
	PointTag m_rTag;
}BTreeNode;

#endif