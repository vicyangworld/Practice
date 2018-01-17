#include <iostream>
#include <stack>
#include <queue>
#include <stdlib.h>
#include "ThreadBTree.h"
using namespace std;

//建立二叉树的算法
void BTree::Create(BTreeNode*& node, int *itemArr, int num, int &index)
{
	if ( index>=num)
	{
		cout<<"Please input correct tree!!"<<endl;
		exit(1);
	}
	if (itemArr[index] == m_leafFlaf)
	{
		node = NULL;
		return;
	}
	else{
		node = new BTreeNode;
		node->m_data = itemArr[index];
		Create(node->m_lChild,itemArr,num,++index);
		Create(node->m_rChild,itemArr,num,++index);
	}
}
void BTree::Create(int *itemArr, int num, int &index)
{
	if (m_proot !=NULL)
	{
		cout<<"The Tree is existed!"<<endl;
		exit(1);
	}
	Create(m_proot, itemArr, num, index);
}

void BTree::Destroy(BTreeNode *&pnode)
{
	if (pnode && pnode->m_lTag==Link && pnode->m_rTag==Link)
	{
		Destroy(pnode->m_lChild);
		Destroy(pnode->m_rChild);
		delete pnode;
		pnode = NULL;
	}
}

void BTree::Destroy(){
	Destroy(m_proot);
}

BTreeNode* BTree::Find(BTreeNode*pstart, const int item) const{
	if (pstart->m_data == item)
	{
		return pstart;
	}
	if (pstart->m_lTag==Link)
	{
		pstart = Find(pstart->m_lChild, item);
	}
	if (pstart!=NULL && pstart->m_data==item)
	{
		return pstart;
	}
	else
	{
		if (pstart->m_rTag==Link)
		{
			return Find(pstart->m_rChild, item);
		}
	}
}

BTreeNode* BTree::Find(const int item) const{
	return Find(m_proot,item);
}


BTreeNode * BTree::GetParent(BTreeNode *pstart,BTreeNode * current){
	if (pstart==NULL|| current==NULL)
	{
		return NULL;
	}
	if ((pstart->m_lChild==current && pstart->m_lTag==Link) || (pstart->m_rChild==current) && pstart->m_lTag==Link)
	{
		return pstart;
	}
	BTreeNode *pmove;
	if (pstart->m_lTag==Link)
	{
		pmove = GetParent(pstart->m_lChild, current);
	}
	if (pmove != NULL)
	{
		return pmove;
	}
	else{
			if (pstart->m_rTag==Link)
			{
				return GetParent(pstart->m_rChild,current);
			}
			else
			{
				return NULL;
			}
	}
}

BTreeNode * BTree::GetParent(BTreeNode * current){
	return (m_proot==NULL||current==m_proot) ? NULL : GetParent(m_proot,current);
}
void BTree::layerOrder(){
	queue<BTreeNode*> que;
	que.push(m_proot);
	while(!que.empty()){
		BTreeNode* temp = que.front();
		que.pop();
		cout<<temp->m_data<<" ";
		if(temp->m_lChild != NULL && temp->m_lTag==Link)
		{
			que.push(temp->m_lChild);
		}
		if(temp->m_rChild != NULL && temp->m_rTag==Link)
		{
			que.push(temp->m_rChild);
		}
	}
	cout<<endl;
}

//中序访问二叉树(递归)
void BTree::inOrder(BTreeNode* pnode)
{
	if(pnode!=0) //是if，而不是while
	{
		inOrder(pnode->m_lChild); //递归访问
		cout<<pnode->m_data<<" ";
		inOrder(pnode->m_rChild); //递归访问
	}
}

//利用重载的方法
void BTree::inOrder()
{
	inOrder(m_proot);
	cout<<endl;
}

//中序遍历(非递归)
void BTree::NotReInOrder()
{
	stack<BTreeNode*> stk;

	BTreeNode* pnode=getRoot();

	while(!stk.empty()||pnode != NULL)
	{
		while(pnode != NULL)
		{
			stk.push(pnode);
			pnode = pnode->m_lChild;
		}

		if(!stk.empty())
		{
			pnode = stk.top();
			stk.pop();
			cout<<pnode->m_data<<" ";
			pnode = pnode->m_rChild;
		}
	}
}

//前序递归访问二叉树(递归)
void BTree::preOrder(BTreeNode* pnode)
{
	if(pnode != NULL  && pnode->m_lTag==Link && pnode->m_rTag==Link) //是if，而不是while
	{
		cout<<pnode->m_data<<" ";
		preOrder(pnode->m_lChild); //递归访问
		preOrder(pnode->m_rChild); //递归访问
	}
}


//重载形式
void BTree::preOrder()
{
	preOrder(m_proot);
	cout<<endl;
}

//前序遍历(非递归)
void BTree::NotRePreOrder()
{
	stack<BTreeNode*> stk;
	BTreeNode* pnode=getRoot();
	stk.push(pnode);

	while(!stk.empty())
	{
		pnode=stk.top();
		stk.pop();

		cout<<pnode->m_data<<" ";

		if(pnode->m_rChild != NULL && pnode->m_rTag==Link)
			stk.push(pnode->m_rChild);
		if(pnode->m_lChild!=0 && pnode->m_lTag==Link)
			stk.push(pnode->m_lChild);
	}
}

//后序遍历(递归)
void BTree::postOrder(BTreeNode* pnode)
{
	if(pnode != NULL) //是if，而不是while
	{
		postOrder(pnode->m_lChild); //递归访问
		postOrder(pnode->m_rChild); //递归访问
		cout<<pnode->m_data<<" ";
	}
}

//重载形式
void BTree::postOrder()
{
	postOrder(m_proot);
	cout<<endl;
}




//后序非递归访问要定义新的结构体类型
struct Node
{
	BTreeNode* tp;
	bool flag;
};

//后序遍历(非递归)
void BTree::NotRePostOrder()
{
	Node node; //定义Node结构体的一个结点
	stack<Node> stk;

	BTreeNode* pnode=getRoot();
	while(!stk.empty()||pnode!=0)
	{
		while(pnode!=0)
		{
			node.tp=pnode;
			node.flag=0;
			stk.push(node);
			pnode=pnode->m_lChild;
		}

		if(!stk.empty())
		{
			node=stk.top();
			stk.pop();
			pnode=node.tp; //将栈顶的BTreeNode*部分赋给r
			if(node.flag==1)
			{
				cout<<pnode->m_data<<" ";
				pnode=0; //表示已经访问了该结点
			}
			else
			{
				node.flag=1;
				stk.push(node);
				pnode=pnode->m_rChild;
			}
		}
	}
}

//求二叉树结点个数的函数
int BTree::GetSize(BTreeNode* node)
{
	//二叉树的结点个数为左右子树的高度之和再+1
	if(node == NULL) return 0; 
	else
		return 1+GetSize(node->m_lChild)+GetSize(node->m_rChild);
}

//重载形式
int BTree::GetSize()
{
	return GetSize(m_proot);
}

//求二叉树叶子结点个数的函数
int BTree::GetLeaves(BTreeNode* node)
{
	//当为空时，返回0；当找到叶子时返回1
	if(node==0) return 0; 
	else
		if(node->m_lChild == NULL && node->m_lTag==Link && node->m_rChild == NULL && node->m_rTag == Link)
			return 1;
		else
			return GetLeaves(node->m_lChild) + GetLeaves(node->m_rChild);
}

//重载形式
int BTree::GetLeaves()
{
	return GetLeaves(m_proot);
}

//求二叉树高度的函数
int BTree::GetHeight(BTreeNode* pnode)
{
	if(pnode==0) return 0;
	else
	{
		//二叉树的高度为左右子树的最大者+1
		int lHei=GetHeight(pnode->m_lChild);
		int rHei=GetHeight(pnode->m_rChild);
		return lHei>rHei ? lHei+1 : rHei+1;
	}
}

//重载形式
int BTree::GetHeight()
{
	return GetHeight(m_proot);
}


//层次遍历求树高需要利用的新结构
struct LayerBTreeNode
{
	BTreeNode* ptr;
	int height;
};

//层次遍历求高度
int BTree::layerHeight()
{
	queue<LayerBTreeNode> que;
	LayerBTreeNode temp,lTemp,rTemp; //牺牲空间来获得算法的清晰度

	BTreeNode* pnode = getRoot();

	int hei=1;
	temp.ptr=pnode;
	temp.height=1;
	que.push(temp); //先将根对应的LayerBTreeNode对象进队

	//不为空时
	while(!que.empty())
	{
		//BTreeNode* btreePtr=0;
		temp=que.front(); //取出队首元素
		que.pop();
		pnode=temp.ptr;
		//用当前的高度跟取出的队首进行比较
		if(hei<temp.height)
			hei=temp.height;
		if((pnode->m_lChild!=NULL && pnode->m_lTag==Link) || pnode->m_rChild!=NULL &&  pnode->m_rTag==Link)
		{
			//如果它的左右子树不为空，则进队列
			if(pnode->m_lChild != NULL && pnode->m_lTag==Link)
			{
				lTemp.ptr=pnode->m_lChild;
				lTemp.height=temp.height+1; //在原来高度基础上加1,再入队列
				que.push(lTemp);
			}
			if(pnode->m_rChild != NULL &&  pnode->m_rTag==Link)
			{
				rTemp.ptr=pnode->m_rChild;
				rTemp.height=temp.height+1;
				que.push(rTemp);
			}
		}
	}
	return hei;
}

void BTree::_InOrderThreading(BTreeNode *&pCurrent){
	if (pCurrent != NULL)
	{
		_InOrderThreading(pCurrent->m_lChild);
		if (pCurrent->m_lChild == NULL)
		{
			pCurrent->m_lTag = Thread;
			pCurrent->m_lChild = m_pre;
		}
		if (m_pre->m_rChild == NULL) 
		{
			m_pre->m_rTag = Thread;
			m_pre->m_rChild = pCurrent;
		}
		m_pre = pCurrent;
		_InOrderThreading(pCurrent->m_rChild);
	}
}

bool BTree::InOrderThreading(){
	m_pBThead = new BTreeNode;
	m_pBThead->m_data = 0;
	if (m_pBThead == NULL)
	{
		cout<<"Can not new a BTreeNode Object!"<<endl;
		return false;
	}
	m_pBThead->m_rChild = NULL;  //iniciation
	BTreeNode *pmove = m_proot;
	if (m_proot == NULL)
	{
		m_pBThead->m_lChild = m_pBThead;
		m_pBThead->m_lTag   = Link;
		m_pBThead->m_rChild = m_pBThead;
		m_pBThead->m_rTag   = Link;
	}
	else
	{
		m_pre = m_pBThead;
		m_pBThead->m_lChild = m_proot;  //
		m_pBThead->m_lTag   = Link;
		_InOrderThreading(pmove);       //
		m_pre->m_rChild = m_pBThead;
		m_pre->m_rTag = Thread;
		m_pBThead->m_rChild = m_pre;
	}
	InOrderThreading_Print();
	return true;
}

void BTree::InOrderThreading_Print(){
    BTreeNode *p;  
    p = m_pBThead->m_lChild;           //p指向根结点  
    do{
        while(p->m_lTag == Link)   //当ltag = 0时循环到中序序列的第一个结点  
        {  
            p = p->m_lChild;  
        }
        cout<<" "<<p->m_data; //显示结点数据，可以更改为其他对结点的操作 
        while(p->m_rTag == Thread && p->m_rChild != m_pBThead)  
        {  
            p = p->m_rChild;  
            cout<<" "<<p->m_data; 
        }  
        p = p->m_rChild;           //p进入其右子树   
    }while(p != m_pBThead);	
    cout<<endl;
}