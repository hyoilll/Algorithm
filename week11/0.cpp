#include <iostream>

using namespace std;

int fibo(int n)
{ 
	int* arr = new int[n + 1];

	arr[0] = 1;
	arr[1] = 2;

	for (int i = 2; i <= n; ++i)
	{
		arr[i] = arr[i - 2] + arr[i - 1];
	}

	int result = arr[n];

	delete[] arr;

	return result;
}

int main()
{

	cout << "fibo(" << 5 << ") : " << fibo(5) << endl;

	return 0;
}