#include <iostream>
#include <stack>
#include <queue>
#include "BTree.h"
using namespace std;

//建立二叉树的算法
void BTree::Create(BTreeNode*& node, int *itemArr, int num, int &index)
{
	if ( index>=num)
	{
		cout<<"Please input correct tree!!"<<endl;
		getchar();
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

void BTree::Destroy(BTreeNode *&node)
{
	if (node)
	{
		Destroy(node->m_lChild);
		Destroy(node->m_rChild);
		delete node;
		node = NULL;
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
	pstart = Find(pstart->m_lChild, item);
	if (pstart!=NULL && pstart->m_data==item)
	{
		return pstart;
	}
	else
	{
		return Find(pstart->m_lChild, item);
	}
}

BTreeNode* BTree::Find(const int item) const{
	return Find(m_proot,item);
}


BTreeNode * BTree::GetParent(BTreeNode *start,BTreeNode * current){
	if (start==NULL || current==NULL)
	{
		return NULL;
	}
	if (start->m_lChild==current || start->m_rChild==current)
	{
		return start;
	}
	BTreeNode *pmove = GetParent(start->m_lChild, current);
	if (pmove != NULL)
	{
		return pmove;
	}
	else{
		return GetParent(start->m_rChild,current);
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
		if(temp->m_lChild != NULL)
		{
			que.push(temp->m_lChild);
		}
		if(temp->m_rChild != NULL)
		{
			que.push(temp->m_rChild);
		}
	}
	cout<<endl;
}

//利用重载的方法
void BTree::inOrder()
{
	inOrder(m_proot);
	cout<<endl;
}

//中序访问二叉树(递归)
void BTree::inOrder(BTreeNode* r)
{
	if(r!=0) //是if，而不是while
	{
		inOrder(r->m_lChild); //递归访问
		cout<<r->m_data<<" ";
		inOrder(r->m_rChild); //递归访问
	}
}

//中序遍历(非递归)
void BTree::NotReInOrder()
{
	stack<BTreeNode*> s;

	BTreeNode* r=getRoot();

	while(!s.empty()||r!=0)
	{
		while(r!=0)
		{
			s.push(r);
			r=r->m_lChild;
		}

		if(!s.empty())
		{
			r=s.top();
			s.pop();
			cout<<r->m_data<<" ";
			r=r->m_rChild;
		}
	}
}

//重载形式
void BTree::preOrder()
{
	preOrder(m_proot);
	cout<<endl;
}

//前序递归访问二叉树(递归)
void BTree::preOrder(BTreeNode* pnode)
{
	if(pnode!=0) //是if，而不是while
	{
		cout<<pnode->m_data<<" ";
		preOrder(pnode->m_lChild); //递归访问
		preOrder(pnode->m_rChild); //递归访问
	}
}


//前序遍历(非递归)
void BTree::NotRePreOrder()
{
	stack<BTreeNode*> s;
	BTreeNode* r=getRoot();
	s.push(r);

	while(!s.empty())
	{
		r=s.top();
		s.pop();

		cout<<r->m_data<<" ";

		if(r->m_rChild!=0)
			s.push(r->m_rChild);
		if(r->m_lChild!=0)
			s.push(r->m_lChild);
	}
}


//重载形式
void BTree::postOrder()
{
	postOrder(m_proot);
	cout<<endl;
}

//后序遍历(递归)
void BTree::postOrder(BTreeNode* r)
{
	if(r!=0) //是if，而不是while
	{
		postOrder(r->m_lChild); //递归访问
		postOrder(r->m_rChild); //递归访问
		cout<<r->m_data<<" ";
	}
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
	stack<Node> s;

	BTreeNode* r=getRoot();
	while(!s.empty()||r!=0)
	{
		while(r!=0)
		{
			node.tp=r;
			node.flag=0;
			s.push(node);
			r=r->m_lChild;
		}

		if(!s.empty())
		{
			node=s.top();
			s.pop();
			r=node.tp; //将栈顶的BTreeNode*部分赋给r
			if(node.flag==1)
			{
				cout<<r->m_data<<" ";
				r=0; //表示已经访问了该结点
			}
			else
			{
				node.flag=1;
				s.push(node);
				r=r->m_rChild;
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
		if(node->m_lChild == NULL && node->m_rChild == NULL)
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
int BTree::GetHeight(BTreeNode* r)
{
	if(r==0) return 0;
	else
	{
		//二叉树的高度为左右子树的最大者+1
		int lHei=GetHeight(r->m_lChild);
		int rHei=GetHeight(r->m_rChild);
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

		if(pnode->m_lChild!=NULL || pnode->m_rChild!=NULL)
		{
			//如果它的左右子树不为空，则进队列
			if(pnode->m_lChild != NULL)
			{
				lTemp.ptr=pnode->m_lChild;
				lTemp.height=temp.height+1; //在原来高度基础上加1,再入队列
				que.push(lTemp);
			}
			if(pnode->m_rChild != NULL)
			{
				rTemp.ptr=pnode->m_rChild;
				rTemp.height=temp.height+1;
				que.push(rTemp);
			}
		}
	}
	return hei;
}
