#include <iostream>
#include "ThreadBTree.h"
using std::cout;
using std::endl;
int main()
{
	int num[] = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,7,-1,-1};
	BTree tree(-1);
	int index=0;
	tree.Create(num,sizeof(num)/sizeof(int),index);
	cout<<tree.Find(4)->m_data<<endl;
	cout<<tree.GetParent(tree.Find(4))->m_data<<endl;
	cout<<"Layer Vist: ";
	tree.layerOrder();
	cout<<"Pre   Vist: ";
	tree.preOrder();
	cout<<"Number of leaves: "<<tree.GetLeaves()<<endl;
	cout<<"Height: "<<tree.layerHeight()<<endl;
	cout<<"Size: "<<tree.GetSize()<<endl;
	cout<<"Root: "<<tree.getRoot()->m_data<<endl;
	tree.InOrderThreading();
	tree.Destroy();
	tree.preOrder();
	return 0;
}
