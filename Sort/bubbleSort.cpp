#include <iostream>
using std::cout;
using std::endl;

//for int or float
template<typename T>
void bubbleSort(T arr[], int len)
{
	for (int i = 0; i < len-1; i++)
	{
		for (int j = 0; j < len-1-i; j++)
		{
			if (arr[j] > arr[j+1])
			{
				arr[j] = arr[j] + arr[j+1];
				arr[j+1] = arr[j] - arr[j+1];
				arr[j] = arr[j] - arr[j+1];
			}
		}
	}
}
int main()
{
	int arr[] = { 61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62 };
	int len = sizeof(arr)/sizeof(int);
	bubbleSort(arr, len);
	for (int i = 0; i < len; i++)
		cout << arr[i] << ' ';
	cout << endl;

	float arrf[] = { 17.5, 19.1, 0.6, 1.9, 10.5, 12.4, 3.8, 19.7, 1.5, 25.4, 28.6, 4.4, 23.8, 5.4 };
	len = (int) sizeof(arrf) / sizeof(*arrf);
	bubbleSort(arrf, len);
	for (int i = 0; i < len; i++)
		cout << arrf[i] << ' ';
	cout << endl;

	return 0;
}
