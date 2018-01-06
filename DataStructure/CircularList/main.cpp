#include <iostream>
#include "CircularList.h"

using std::cout;
using std::endl;

int main()
{
	CircularList<int> list;
	for (int i = 0; i < 20; ++i)
	{
		list.Insert(i*3,i);
	}
	cout<<"Length:"<<list.Length()<<endl;
	list.Print();

	for (int i = 0; i < 5; ++i)
	{
		list.Insert(3,i*3);
	}
	cout<<"Length:"<<list.Length()<<endl;

	list.Remove(5);
	cout<<"After Remove,Length:"<<list.Length()<<endl;
	list.Print();

	list.RemoveAll(2);
	cout<<"After Remove all 3 item,Length:"<<list.Length()<<endl;
	list.Print();

	return 0;
}