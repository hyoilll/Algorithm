#include <iostream>
using namespace std;

void selectSort(int* arr, int length)
{
	int minIdx = 0;

	for (int i = 0; i < length; ++i)
	{//1,4,2,3,5,7,4,9,4,0
		minIdx = i;
		for (int j = i + 1; j < length; ++j)
		{
			if (arr[minIdx] > arr[j])
			{
				minIdx = j;
			}
		}

		int temp = arr[i];
		arr[i] = arr[minIdx];
		arr[minIdx] = temp;
	}
}

void insertSort(int* arr, int length)
{
	int idx = 0;
	for (int i = 1; i < length; ++i)
	{ //1,4,2,3,5,7,4,9,4,0
		idx = i;

		for (int j = i - 1; j >= 0; --j)
		{
			if (arr[idx] < arr[j])
			{
				int temp = arr[idx];
				arr[idx] = arr[j];
				arr[j] = temp;
				idx = j;
			}
		}
	}
}

void bubbleSort(int* arr, int length)
{
	for (int i = 0; i < length - 1; ++i)
	{
		for (int j = 1; j < length + i; ++j)
		{
			if (arr[j - 1] > arr[j])
			{
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = arr[j];
			}
		}
	}
}

void quickSort(int* arr, int start, int end)
{
	int pivot = 0;
	int max = 0;
	int min = 0;

	for (int i = start; i < end; ++i)
	{
		if (arr[pivot] < arr[i])
		{

		}
	}
}

int main()
{
	const int length = 9;
	int arr[length] = { 5,3,8,4,9,1,6,2,7 };

	//selectSort(arr, length);
	//insertSort(arr, length);
	quickSort(arr, 0, length);
	for (int i = 0; i < length; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}