#include <iostream>
#include "Seqlist.h"

int main()
{
	SeqList<int> test(15);
	int array[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	for (int i = 0; i < 14; ++i)
	{
		test.Insert(array[i],0);
	}
	std::cout<<"Length: "<<test.Length()<<endl;
	test.Print();
	test.Insert(5,0);
	std::cout<<"Length: "<<test.Length()<<endl;
	test.Print();
}