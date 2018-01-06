#include "SingleList.h"

int main()
{
	SingleList<int> list;
	for (int i = 0; i < 20; ++i)
	{
		list.Insert(i+1, i);
	}
	for (int i = 0; i < 5; ++i)
	{
		list.Insert(3,i*3);
	}
	std::cout<<"the Length of the list is "<<list.Length()<<std::endl;
	list.Print();

	list.Remove(5);
	std::cout<<"the Length of the list is "<<list.Length()<<std::endl;
	list.Print();

	list.RemoveAll(3);
	std::cout<<"the Length of the list is "<<list.Length()<<std::endl;
	list.Print();

	std::cout<<"The third element is "<<list.Get(3)<<std::endl;

	//std::cout<<*list.Find(18,1)<<std::endl;
	list.Find(100);

	list.MakeEmpty();

	std::cout<<"the Length of the list id "<<list.Length()<<std::endl;
	list.Print();
	return 0;
}