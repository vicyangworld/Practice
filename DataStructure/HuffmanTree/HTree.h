#ifndef _H_HTREE_
#define _H_HTREE_
#include <iostream>
#include "HTreeNode.h"
#include "HCode.h"
class HTree{
private:
	HTreeNode * m_HT;
	int m_nAllNodes;
	int m_nLeaves;
	HCode *m_HC;
public:
	HTree(int *, int n);
	void View();
	void Incode();
	void Decode();
	void Decode(char *);
private:
	void _initHTree();
	void _selectMin(int i,int &s1, int &s2);
	void _viewCode();
};


#endif
