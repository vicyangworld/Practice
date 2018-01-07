#include <iostream>
#include "LinkStack.h"

int main(int argc, char const *argv[])
{
	LinkStack<int> stack;
	int init[11]={1,2,3,4,5,6,7,8,9,10,12};
	for (int i = 0; i < 11; ++i)
	{
		stack.Push(init[i]);
	}
	cout<<"Length:"<<stack.Length()<<endl;
	stack.Print();

	cout<<"Top:";
	cout<<stack.GetTop()<<endl;

	stack.Pop();
	cout<<"After Pop(): "<<endl;
	cout<<"Length:"<<stack.Length()<<endl;
	stack.Print();
	return 0;
}
