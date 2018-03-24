#include <iostream>
using std::cout;
using std::endl;

template<typename T>
void quickSort(T a[],int first, int end)
{
	if(first >= end || a==NULL) return;
	int i = first;   //哨兵1
	int j = end;     //哨兵2
	T key = a[i];    /*用数组的第一个记录作为分区元素*/
	while(i != j){
		//首先要从右向左扫描
		while(i<j && a[j]>=key)    /*从右向左扫描，找第一个码值小于key的记录，并交换到key*/
			--j;
		a[i] = a[j];
		while(i<j && a[i]<=key)
			++i;
		a[j]=a[i];    /*从左向右扫描，找第一个码值大于key的记录，并交换到右边*/
	}
	a[i]=key;    /*分区元素放到正确位置*/
	quickSort(a,first,i-1);
	quickSort(a,i+1,end);
}

int main()
{
	int arr[] = { 61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62 };
	int len = sizeof(arr)/sizeof(int);
	quickSort(arr, 0,len-1);
	for (int i = 0; i < len; i++)
		cout << arr[i] << ' ';
	cout << endl;

	float arrf[] = { 17.5, 19.1, 0.6, 1.9, 10.5, 12.4, 3.8, 19.7, 1.5, 25.4, 28.6, 4.4, 23.8, 5.4 };
	len = (int) sizeof(arrf) / sizeof(float);
	quickSort(arrf, 0,len-1);
	for (int i = 0; i < len; i++)
		cout << arrf[i] << ' ';
	cout << endl;

	return 0;
}
