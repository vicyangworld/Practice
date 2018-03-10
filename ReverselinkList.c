#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node* next;
} node;
//指针的指针是为了修改链表
//因为直接传递过来指针也“值传递”，不过是复制出另外一个指针，
//若要在指针的指针就可以是的一级指针*pHead被传递进这个函数了，、
//就可以在这个指针的基础上就行修改
void insert(node** pHead, int value)
{
	node* nn;
	nn=(node*)malloc(sizeof(node));
	nn->data = value;
	nn->next = NULL;
	if (*pHead==NULL)
	{
		*pHead = nn;
		return;
	}

	node* pMove = *pHead;

	while(pMove->next!=NULL)
	{
		pMove = pMove->next;
	}
	pMove->next = nn;
}

void reverse(node **pHead)
{
	if ((*pHead)->next == NULL)
	{
		return;
	}
	node* pre = NULL;
	node* cur = *pHead;
	node* next = cur->next;
	while(next != NULL)
	{
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	*pHead = pre;
}

void print(node* pHead)
{
	if (pHead->next == NULL)
	{
		return;
	}
	do{
		printf("%d  ", pHead->data);
		pHead = pHead->next;

	}while(pHead!=NULL);
	printf("\n");
}

int main(int argc, char const *argv[])
{
	node* pHead = NULL;
	insert(&pHead,1);
	insert(&pHead,2);
	insert(&pHead,3);
	insert(&pHead,4);
	print(pHead);
	reverse(&pHead);
	print(pHead);
	return 0;
}
