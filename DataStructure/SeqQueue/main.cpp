#include <iostream>
#include "SeqQueue.h"

int main(int argc, char const *argv[])
{
	SeqQueue<int> queue(10);
	int init[10] = {1,2,3,4,5,6,7,8,9,10};
	for (int i = 0; i < 5; ++i)
	{
		queue.Append(init[i]);
	}
	cout<<"Length:"<<queue.Length()<<endl;
	queue.Print();

	cout<<"after delete:"<<endl;
	queue.Delete();
	queue.Print();

	for (int i = 5; i < 10; ++i)
	{
		queue.Append(init[i]);
	}
	cout<<"Length:"<<queue.Length()<<endl;
	queue.Print();
	queue.Append(11);
	cout<<"Length:"<<queue.Length()<<endl;
	queue.Print();

	queue.Append(45);
	
	return 0;
}