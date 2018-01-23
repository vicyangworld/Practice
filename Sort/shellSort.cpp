#include <iostream>
using std::cout;
using std::endl;

template<typename T>
void shellSort(T arr[],int len, int d)
{
	for(int inc=d; inc>0; inc/=2){
		for(int i=inc; i<len; ++i){
			int j = i-inc;
			T temp = arr[i];
			while(j>=0 && arr[j]>temp)
			{
				arr[j+inc] = arr[j];
				j = j-inc;
			}
			if((j+inc)!=i)
				arr[j+inc] = temp;
		}
	}
}

int main()
{
	int arr[] = { 100, 34, 61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62 };
	int len = sizeof(arr)/sizeof(int);
	// insertSort(arr,len);
	shellSort(arr,len,len/2);
	for (int i = 0; i < len; i++)
		cout << arr[i] << ' ';
	cout << endl;

	float arrf[] = { 34.0, 23.8, 19.0, 17.5, 19.1, 0.6, 1.9, 10.5, 12.4, 3.8, 19.7, 1.5, 25.4, 28.6, 4.4, 23.8, 5.4 };
	len = (int) sizeof(arrf) / sizeof(float);
	// insertSort(arrf,len);
	shellSort(arrf,len,len/2);
	for (int i = 0; i < len; i++)
		cout << arrf[i] << ' ';
	cout << endl;

	return 0;
}
