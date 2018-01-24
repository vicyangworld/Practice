#include <iostream>
using std::cout;
using std::endl;

// template<typename T>
// void _shift_up(T arr[], int i){
// 	while(i/2>0 && arr[i]<arr[i/2]){
// 		arr[i/2] = arr[i/2] + arr[i];
// 		arr[i] = arr[i/2] - arr[i];
// 		arr[i/2] = arr[i/2] - arr[i];
// 		i = i/2;
// 	}
// }
// template<typename T>
// void _push(T arr[], T data, int n){
// 	arr[n] = data;
// 	_shift_up(arr,n);
// }

//2*i+2 right child of i
//2*i+1 left  child of i
//the max index of arr
//n+1 is the size of arr
template<typename T>
void _shift_down(T arr[], int i, int n){
	while(2*i+2<n+1){
		int k = i*2+1; 
		if (k+1<n && arr[k]<arr[k+1])
		{
			k++;
		}
		if (arr[i] < arr[k])
		{
			arr[i] = arr[i] + arr[k];
			arr[k] = arr[i] - arr[k];
			arr[i] = arr[i] - arr[k];
			i = k;
		}
		else{
			break;
		}
	}
}
template<typename T>
void _head_tail_exchange(T arr[], int n){
	arr[0] = arr[0] + arr[n];
	arr[n] = arr[0] - arr[n];
	arr[0] = arr[0] - arr[n];
	_shift_down(arr,0,n);
}

template<typename T>
void heapSort(T arr[], int len){
	int k = 0;
	for (int i = len/2-1; i >= 0; i--)  
		_shift_down(arr,i,len-1);
	for (int i = len-1; i > 0; --i)
	{
		_head_tail_exchange(arr,i);
	}
}

int main()
{
	int arr[] = { 100, 34, 5, 61, 17, 22, 29, 1, 45, 6, 12, 9, 14, 21, 31};
	int len = sizeof(arr)/sizeof(int);
	heapSort(arr,len);
	for (int i = 0; i < len; i++)
		cout << arr[i] << ' ';
	cout << endl;

	float arrf[] = { 34.0, 23.8, 19.0, 17.5, 19.1, 0.6, 1.9, 10.5, 12.4, 3.8, 19.7, 1.5, 25.4, 28.6, 4.4, 23.8, 5.4 };
	len = (int) sizeof(arrf) / sizeof(float);
	heapSort(arrf,len);
	for (int i = 0; i < len; i++)
		cout << arrf[i] << ' ';
	cout << endl;

	return 0;
}
