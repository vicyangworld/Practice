#ifndef _H_HTREE_
#define _H_HTREE_
#include <iostream>
#include "HTreeNode.h"
class HTree{
private:
	HTreeNode * m_HT;
	int m_nAllNodes;
public:
	HTree(int *, int n);
	void View();
private:
	void _initHTree();
	void _selectMin(int i,int &s1, int &s2);
};


#endif
