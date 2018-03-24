#include <iostream>

using std::cout;
using std::endl;

void insertSort(int a[], int len)
{
	if (a==NULL || len<0)
	{
		return;
	}
  //从第二个元素开始比较
	for (int i = 1; i < len; ++i)
	{
		int key = a[i];
		int j=i-1;
    //移动
		while(j>=0 && a[j]>key)
		{
			a[j+1] = a[j];
			j--;
		}
    //插入
		a[j+1] = key;
	}
}

int main(int argc, char const *argv[])
{
	int a[6] = {5,1,3,2,4,0};
	insertSort(a,sizeof(a)/sizeof(int));
	for (int i = 0; i < sizeof(a)/sizeof(int); ++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
