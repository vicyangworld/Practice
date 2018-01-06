#include <iostream>
#include "SeqStack.h"

#include "SeqStack.h"

int main(int argc, char const *argv[])
{
	SeqStack<int> stack(10);
	int init[10]={1,2,3,4,5,6,7,8,9,10};
	for (int i = 0; i < 10; ++i)
	{
		stack.Push(init[i]);
	}
	cout<<"Length:"<<endl;
	stack.Print();
	stack.Push(88);
	cout<<"Pop:"<<stack.Pop()<<endl;
	stack.Print();

	cout<<"make empty"<<endl;
	stack.MakeEmpty();
	stack.Print();

	stack.Pop();
	return 0;
}