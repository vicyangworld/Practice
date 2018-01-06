#include <iostream>
#include <stdlib.h>
#include "DuLinkList.h"

int main(int argc, char const *argv[])
{
	
	DuLinkList<int> list;
	for (int i = 0; i < 20; ++i)
	{
		list.Insert(i*3,i);
	}
	std::cout<<"Length: "<<list.Length()<<std::endl;
	list.Print();
	for (int i = 0; i < 5; ++i)
	{
		list.Insert(3,i*3);
	}
	std::cout<<"Length: "<<list.Length()<<std::endl;
	list.Print();

	list.Remove(5);
	std::cout<<"Length: "<<list.Length()<<std::endl;
	list.Print();

	std::cout<<list.Find(4)->GetData()<<std::endl;
	std::cout<<"Length: "<<list.Length()<<std::endl;

	list.MakeEmpty();
	std::cout<<"Length: "<<list.Length()<<std::endl;
	list.Print();
	return 0;
}