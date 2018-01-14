#include <iostream>
#include <stack>
#include <queue>
#include "BTree.h"
using namespace std;

//�������������㷨
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

//�������صķ���
void BTree::inOrder()
{
	inOrder(m_proot);
	cout<<endl;
}

//������ʶ�����(�ݹ�)
void BTree::inOrder(BTreeNode* r)
{
	if(r!=0) //��if��������while
	{
		inOrder(r->m_lChild); //�ݹ����
		cout<<r->m_data<<" ";
		inOrder(r->m_rChild); //�ݹ����
	}
}

//�������(�ǵݹ�)
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

//������ʽ
void BTree::preOrder()
{
	preOrder(m_proot);
	cout<<endl;
}

//ǰ��ݹ���ʶ�����(�ݹ�)
void BTree::preOrder(BTreeNode* pnode)
{
	if(pnode!=0) //��if��������while
	{
		cout<<pnode->m_data<<" ";
		preOrder(pnode->m_lChild); //�ݹ����
		preOrder(pnode->m_rChild); //�ݹ����
	}
}


//ǰ�����(�ǵݹ�)
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


//������ʽ
void BTree::postOrder()
{
	postOrder(m_proot);
	cout<<endl;
}

//�������(�ݹ�)
void BTree::postOrder(BTreeNode* r)
{
	if(r!=0) //��if��������while
	{
		postOrder(r->m_lChild); //�ݹ����
		postOrder(r->m_rChild); //�ݹ����
		cout<<r->m_data<<" ";
	}
}


//����ǵݹ����Ҫ�����µĽṹ������
struct Node
{
	BTreeNode* tp;
	bool flag;
};

//�������(�ǵݹ�)
void BTree::NotRePostOrder()
{
	Node node; //����Node�ṹ���һ�����
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
			r=node.tp; //��ջ����BTreeNode*���ָ���r
			if(node.flag==1)
			{
				cout<<r->m_data<<" ";
				r=0; //��ʾ�Ѿ������˸ý��
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

//��������������ĺ���
int BTree::GetSize(BTreeNode* node)
{
	//�������Ľ�����Ϊ���������ĸ߶�֮����+1
	if(node == NULL) return 0; 
	else
		return 1+GetSize(node->m_lChild)+GetSize(node->m_rChild);
}

//������ʽ
int BTree::GetSize()
{
	return GetSize(m_proot);
}



//�������Ҷ�ӽ������ĺ���
int BTree::GetLeaves(BTreeNode* node)
{
	//��Ϊ��ʱ������0�����ҵ�Ҷ��ʱ����1
	if(node==0) return 0; 
	else
		if(node->m_lChild == NULL && node->m_rChild == NULL)
			return 1;
		else
			return GetLeaves(node->m_lChild) + GetLeaves(node->m_rChild);
}

//������ʽ
int BTree::GetLeaves()
{
	return GetLeaves(m_proot);
}

//��������߶ȵĺ���
int BTree::GetHeight(BTreeNode* r)
{
	if(r==0) return 0;
	else
	{
		//�������ĸ߶�Ϊ���������������+1
		int lHei=GetHeight(r->m_lChild);
		int rHei=GetHeight(r->m_rChild);
		return lHei>rHei ? lHei+1 : rHei+1;
	}
}

//������ʽ
int BTree::GetHeight()
{
	return GetHeight(m_proot);
}


//��α�����������Ҫ���õ��½ṹ
struct LayerBTreeNode
{
	BTreeNode* ptr;
	int height;
};

//��α�����߶�
int BTree::layerHeight()
{
	queue<LayerBTreeNode> que;
	LayerBTreeNode temp,lTemp,rTemp; //�����ռ�������㷨��������

	BTreeNode* pnode = getRoot();

	int hei=1;
	temp.ptr=pnode;
	temp.height=1;
	que.push(temp); //�Ƚ�����Ӧ��LayerBTreeNode�������

	//��Ϊ��ʱ
	while(!que.empty())
	{
		//BTreeNode* btreePtr=0;

		temp=que.front(); //ȡ������Ԫ��
		que.pop();

		pnode=temp.ptr;

		//�õ�ǰ�ĸ߶ȸ�ȡ���Ķ��׽��бȽ�
		if(hei<temp.height)
			hei=temp.height;

		if(pnode->m_lChild!=NULL || pnode->m_rChild!=NULL)
		{
			//�����������������Ϊ�գ��������
			if(pnode->m_lChild != NULL)
			{
				lTemp.ptr=pnode->m_lChild;
				lTemp.height=temp.height+1; //��ԭ���߶Ȼ����ϼ�1,�������
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
