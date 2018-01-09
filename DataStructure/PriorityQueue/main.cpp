#include <iostream>
#include "cstlib.h"
#include "PriorityQueue.h"

int main(int argc, char const *argv[])
{
	PriorityQueue<int,Compare<int>> queue;
	int init[10]={1,9,4,7,3,,5,2,10,6,8};
	for (int i = 0; i < 10; ++i)
	{
		queue.Append(init[i]);
	}
	cout<<"Length:"<<queue.Length()<<endl;
	queue.Print();
	cout<<"after delete:"<<endl;
	queue.Delete();
	queue.Print();

	system("pause");
	system("cls");

	PriorityQueue<SpecialData,SpecialCompare> spe_queue;
	int init2[5][2]={{23,2},{12,6},{65,8},{56,1},{39,4}};
	SpecialData data[5];
	for (int i = 0; i < 5; ++i)
	{
		data[i].m_npir = init2[i][1];
		data[i].m_ntenor = init2[i][0];
	}
	for (int i = 0; i < 5; ++i)
	{
		spe_queue.Append(data[i])
	}
	spe_queue.Print();
	cout<<"Front:";
	cout<<spe_queue.GetFront()<<endl<<endl;
	spe_queue.Delete();
	cout<<"after delete:"
	spe_queue.Print();
	return 0;
}
