#include <iostream>
using std::cout;
using std::endl;

template<typename T>
void selectSort(T A[],int len)
{
	int i,j,min;
	for(i=0;i<len;i++){
		min=i;
		for(j=i+1;j<len;j++){
			if(A[j]<A[min])
				min=j;
		}
		if(i!=min){
			A[i]=A[i]+A[min];
			A[min]=A[i]-A[min];
			A[i]=A[i]-A[min];
		}
	}
}

int main()
{
	int arr[] = { 100, 34, 61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62 };
	int len = sizeof(arr)/sizeof(int);
	// insertSort(arr,len);
	selectSort(arr,len);
	for (int i = 0; i < len; i++)
	cout << arr[i] << ' ';
	cout << endl;

	float arrf[] = { 34.0, 23.8, 19.0, 17.5, 19.1, 0.6, 1.9, 10.5, 12.4, 3.8, 19.7, 1.5, 25.4, 28.6, 4.4, 23.8, 5.4 };
	len = (int) sizeof(arrf) / sizeof(float);
	// insertSort(arrf,len);
	selectSort(arrf,len);
	for (int i = 0; i < len; i++)
	cout << arrf[i] << ' ';
	cout << endl;

	return 0;
}
