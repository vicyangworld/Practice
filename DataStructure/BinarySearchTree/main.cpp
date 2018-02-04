#include <iostream>
#include "BST.h"

using std::cout;
using std::endl;
using std::ostream;
using std::istream;

int main(int argc, char const *argv[])
{
	BinaryTree<float> tree(-1);
	float init[18] = {
		17.0,6.6,22,20,32,56,2,3,52,6.6,14,21,18,30,6.6,67,31,17.0
	};
	cout<<sizeof(init)/sizeof(int)<<endl;
	tree.Create(init,sizeof(init)/sizeof(int));
	cout<<tree<<endl;
	cout<<"size = "<<tree.GetSize()<<endl;
	tree.Insert(11);
	cout<<tree<<endl;
	cout<<"size = "<<tree.GetSize()<<endl;
	tree.Insert(11);
	cout<<tree<<endl;
	cout<<"size = "<<tree.GetSize()<<endl;
	tree.Delete(11);
	cout<<tree<<endl;
	cout<<"size = "<<tree.GetSize()<<endl;
	tree.Delete(12);
	cout<<tree<<endl;
	cout<<"size = "<<tree.GetSize()<<endl;
	cout<<"-----------------------------------------"<<endl;

	return 0;
}
