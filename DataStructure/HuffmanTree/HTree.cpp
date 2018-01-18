#include "HTree.h"
#include <stdlib.h>

using std::cout;
using std::endl;

HTree::HTree(int *arr, int n){
	if (n<1)
	{
		cout<<"Parameter Error!"<<endl;
		exit(1);
	}
	m_HT = NULL;

	m_nAllNodes = 2 * n - 1;
	_initHTree();
	for (int i=0;i<n;i++) //前n个是叶子节点
	{
		m_HT[i].m_weight = arr[i];
	}
	int s1,s2;  //最小的两个值在数组中的下标
	for (int i=n;i<m_nAllNodes;i++) //从第n个开始，为双亲节点，放在数组的后半段
	{
		_selectMin(i-1,s1,s2);
		m_HT[s1].m_parent = i;
		m_HT[s2].m_parent = i;
		m_HT[i].m_lchild = s1;
		m_HT[i].m_rchild = s2;
		m_HT[i].m_weight = m_HT[s1].m_weight + m_HT[s2].m_weight;
	}
}

void HTree::_initHTree(){
	m_HT = new HTreeNode[m_nAllNodes];
	for (int i=0; i<m_nAllNodes;i++)
	{
		m_HT[i].m_weight = 0;
		m_HT[i].m_lchild = -1;
		m_HT[i].m_rchild = -1;
		m_HT[i].m_parent = -1;
	}
}

void HTree::_selectMin(int n, int &s1,int &s2){
	int k = 0;
	while(m_HT[k].m_parent != -1){
		k++;
	}
	s1 = k;
	for (int j=0;j<=n;j++)
	{
		if (m_HT[j].m_parent == -1 && m_HT[j].m_weight<m_HT[s1].m_weight)
		{
			s1 = j;
		}
	}
	k = 0;
	while(m_HT[k].m_parent != -1 || k==s1)
	{
		k++;
	}
	s2 = k;
	for (int j=0;j<=n;j++)
	{
		if (m_HT[j].m_parent==-1 && m_HT[j].m_weight<m_HT[s2].m_weight && j!=s1){
			s2 = j;
		}
	}
}

void HTree::View(){
	cout<<"weight  "<<"parent   "<<"lchild   "<<"rchild"<<endl;
	for (int i=0;i<m_nAllNodes;i++)
	{
		cout<<m_HT[i].m_weight<<"   "<<m_HT[i].m_parent<<"   "<<m_HT[i].m_lchild<<"   "<<m_HT[i].m_rchild<<endl;
	}
}
