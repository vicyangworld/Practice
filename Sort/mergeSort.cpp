#include <iostream>
using std::cout;
using std::endl;

template<typename T>
//left [p...q]  size:q-p+1  index:0...q-p
//right[q+1 r]  size:r-q    index:0...r-q-1
void merge(T arr[], int p, int q, int r){
	int i = 0;
	int j = 0;
	T *temp = new T[r-p+1];
	int d = q - p + 1;
	for (int idx = p; idx < r+1; ++idx)
	{
		temp[idx-p] = arr[idx];
	}
	for (int k = p; k < r+1; ++k)
	{
		if(temp[i] <= temp[j+d]){
			arr[k] = temp[i];
			i = i + 1;
		}else{
			arr[k] = temp[j+d];
			j = j + 1;
		}
		if (i == q-p+1)
		{
			for (int idx = k+1; idx < r+1; ++idx)
			{
				arr[idx] = temp[j+d];
				j++;
			}
			break;
		}
		if (j == r-q)
		{
			for (int idx = k+1; idx < r+1; ++idx)
			{
				arr[idx] = temp[i];
				i++;
			}
			break;
		}
	}
	delete [] temp;
}

template<typename T>
void _mergeSort(T arr[], int p, int r){
	if (p < r)
	{
		int q = (p + r)/2;
		_mergeSort(arr, p, q);
		_mergeSort(arr, q+1, r);
		merge(arr, p, q, r);
	}
}

template<typename T>
void mergeSort(T arr[], int len){
	_mergeSort(arr, 0, len-1);
}


int main()
{
	int arr[] = { 61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62, 13 };
	int len = sizeof(arr)/sizeof(int);
	mergeSort(arr, len);
	for (int i = 0; i < len; i++)
		cout << arr[i] << ' ';
	cout << endl;

	float arrf[] = { 17.5, 19.1, 0.6, 1.9, 10.5, 12.4, 3.8, 19.7, 1.5, 25.4, 28.6, 4.4, 23.8, 5.4 };
	len = (int) sizeof(arrf) / sizeof(float);
	mergeSort(arrf, len);
	for (int i = 0; i < len; i++)
		cout << arrf[i] << ' ';
	cout << endl;

	return 0;
}
