#include <iostream>
#include <stdlib.h> 
using std::cout;
using std::endl;
using std::cin;

static int _count = 0;

void move(int id, char src, char des ){
	_count++;
	cout<<id <<": "<<src<<" -> "<<des<<endl;
}

//参数的意思：将n个盘子从src通过trans移动到des
void hanoi(int n, char src, char trans, char des){

	if (n==1)
	{
		move(1,src,des);
	}
	else
	{
		hanoi(n-1,src,des,trans);//第一步：将n-1个盘子看成整体，从源塔通过目标塔移动到中间塔上
		move(n,src,des);         //第二部，将第n个盘子从src移动到des上
		hanoi(n-1,trans,src,des);//第三部，将n-1个盘子从中间塔上借助源塔移动到目标塔上
	}
}

int main()
{
	int n;
	cout<<"Please input the layers:";
	cin>>n;
	hanoi(n,'x','y','z');
	cout<<"Total Steps: "<<_count<<endl;
	system("Pause"); 
	return 0;
}
