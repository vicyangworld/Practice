#include <iostream>
#include "SeqList.h"

using namespace std;

int main()
{
	SeqList<int> test(15);
	int array[15]={1,2,3,4,5,6,7,8,9,0,11,12,13,14,15};
	for (int i = 0; i < 15; ++i)
	{
		test.Insert(array[i],0);
	}

	test.Insert(1,0);
}