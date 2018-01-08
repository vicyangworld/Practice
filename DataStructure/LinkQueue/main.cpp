
#include "LinkQueue.h"

int main(int argc, char const *argv[])
{
	LinkQueue<int> queue;
	int init[10]={1,2,3,4,5,6,7,8,9,10};
	for (int i = 0; i < 10; ++i)
	{
		queue.Append(i);
	}
	cout<<"length:"<<queue.Length()<<endl;
	queue.Print();

	queue.Delete();
	cout<<"length after delete:"<<queue.Length()<<endl;
	queue.Print();

	cout<<"front:"<<queue.GetFront()<<endl;

	queue.MakeEmpty();
	queue.Print();

	queue.Delete();
	return 0;
}