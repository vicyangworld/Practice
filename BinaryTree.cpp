#include<iostream>
#include<stdexcept>

using namespace std;

typedef struct node
{
	int value;
	struct node *left;
	struct node *right;
} node;

node* constructCore(int *preStart, int *preEnd,int *inStart, int *inEnd)
{
	int rootValue = *preStart;
	node *root = new node();
	root->value = rootValue;
	root->left = NULL;
	root->right = NULL;
	if (preEnd == preStart)
	{
		if (inEnd ==inStart && *preStart==*inStart)
		{
			return root;
		}
		else{
			std::logic_error ex("invalid input");
			throw std::exception(ex);
		}
	}

	int *pMove = inStart;
	while(pMove<=inEnd && *pMove!=rootValue)
	{
		pMove++;
	}
	if (pMove==inEnd && *pMove != rootValue)
	{
		std::logic_error ex("invalid input");
		throw std::exception(ex);	
	}
	int leftCount = pMove-inStart;
	if (leftCount>0)
	{
		root->left = constructCore(preStart+1, preStart+leftCount, inStart, pMove-1);
	}

	int rightCount = inEnd - pMove;
	if (rightCount>0)
	{
		root->right = constructCore(preStart+leftCount+1, preEnd, pMove+1, inEnd);	
	}
	return root;
}

node* construct(int *preOrder,int *inOrder,int length){
	if (preOrder==NULL || inOrder==NULL)
	{
		std::logic_error ex("invalid input");
		throw std::exception(ex);
	}
	return constructCore(preOrder,preOrder+length-1,inOrder,inOrder+length-1);
}

void postOrderPrint(node *root)
{
	if (root==NULL)
	{
		return;
	}
	postOrderPrint(root->left);
	postOrderPrint(root->right);
	std::cout<<root->value<<" ";
}
int main(int argc, char const *argv[])
{
	int preOrder[] = {1,2,4,7,3,5,6,8};
	int inOrder[] = {4,7,2,1,5,3,8,6};
	node *root = construct(preOrder,inOrder,sizeof(preOrder)/sizeof(int));
	postOrderPrint(root);
	return 0;
}