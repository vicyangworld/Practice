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
	m_nLeaves = n;
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

void HTree::Incode(){
	if (m_HT == NULL)
	{
		cout<<"No Huffman Tree!"<<endl;
		exit(1);
	}
    int i = 0;
    int c = 0;
    int p = 0;
    HCode cd;//缓冲变量
    m_HC = new HCode[m_nLeaves];

    for(i=0;i<m_nLeaves;i++)//依次检测前N个节点，前N个节点为叶子节点，即从Huffman从下往上获得单个字符的编码  
    {  
        cd.start = MAXBIT;
        cd.val = m_HT[i].m_weight;  
        c = i;              //c为当前节点location  
        p = m_HT[i].m_parent; //p is the parent of c
        while(p != -1)  
        {  
        	cd.start--;
            if(m_HT[p].m_lchild == c) 
                cd.bits[cd.start]='0';//tree[i]是左子树，生成代码'0'
            else  
                cd.bits[cd.start]='1';//tree[i]是右子树，生成代码'1'  
            c = p;  
            p = m_HT[p].m_parent;  
        }

        m_HC[i].val = cd.val;//
        m_HC[i].start = cd.start;
        for (int j = cd.start; j < MAXBIT; ++j)
        {
        	m_HC[i].bits[j] = cd.bits[j];
        }
    }
    _viewCode();
}

void HTree::_viewCode(){
	for (int i = 0; i < m_nLeaves; ++i)
	{
		for (int j = 0; j < MAXBIT; ++j)
		{
			cout<<m_HC[i].bits[j];
		}
		cout<<"\t"<<m_HT[i].m_weight<<endl;
	}
}
void HTree::Decode(){
	for (int i=0;i<m_nLeaves;i++)
	{
		cout<<m_HT[i].m_weight<<endl;
	}
}
void HTree::Decode(char * pCode){
	int nMove = m_nAllNodes-1;//root node
	int i = 0;
	while(m_HT[nMove].m_lchild != -1){
		if(pCode[i]=='0' || pCode[i]=='1')
		{
			nMove = pCode[i] == '0' ? m_HT[nMove].m_lchild : m_HT[nMove].m_rchild;
			i++;
		}
		else{
			cout<<"Wrong parameter of decode()"<<endl;
			exit(1);		
		}
	}
	if (pCode[i]!='\0')
	{
		cout<<"Wrong parameter of decode()"<<endl;
		exit(1);
	}
	cout<<"decode: "<<m_HT[nMove].m_weight<<endl;
}