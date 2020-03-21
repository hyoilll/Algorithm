#include <iostream>
using namespace std;

template <class T>
class Array
{
private:
	T* arr;
	int size;
	int capacity;

public:
	Array(const int& length)
	{
		arr = new T[length];
		size = 0;
		capacity = length;

		cout << "construction" << endl;
	}

	~Array()
	{
		cout << "destruction" << endl;
		delete[] arr;
	}

	void add(const T& value)
	{
		arr[size++] = value;
	}

	int getLength() const
	{
		return size;
	}

	T getArr(int index) const
	{
		return arr[index];
	}

	void remove(int index)
	{
		for (int i = index; i < size - 1; ++i)
		{
			arr[i] = arr[i + 1];
		}
		size--;
	}

};


int main()
{
	Array <double>arr(5);

	arr.add(10.1);
	arr.add(20.1);
	arr.add(30.1);

	arr.remove(2);

	for (int i = 0; i < arr.getLength(); ++i)
	{
		cout << arr.getArr(i) << " ";
	}
	cout << endl;

	return 0;
}

/*
class Array
{
private:
	int* arr;
	int size;
	int capacity;

public:
	Array(const int& length)
	{
		arr = new int[length];
		size = 0;
		capacity = length;

		cout << "construction" << endl;
	}

	~Array()
	{
		cout << "destruction" << endl;
		delete[] arr;
	}

	void AddArray(const int& value)
	{
		arr[size++] = value;
	}

	int getLength()
	{
		return size;
	}

	int getArr(int index)
	{
		return arr[index];
	}

	void removeArray(int index)
	{
		for (int i = index; i < size - 1; ++i)
		{
			arr[i] = arr[i + 1];
		}
		size--;
	}

};


int main()
{
	Array arr(5);

	arr.AddArray(10);
	arr.AddArray(20);
	arr.AddArray(30);

	arr.removeArray(2);

	for (int i = 0; i < arr.getLength(); ++i)
	{
		cout << arr.getArr(i) << " ";
	}
	cout << endl;

	return 0;
}
*/

//--------------------------------------------------------------------

/*
class Array
{
private:
	int* arr;
	int size;
	int capacity;

public:
	void InitArray(const int& length)
	{
		arr = new int[length];
		size = 0;
		capacity = length;
	}

	void UninitArray()
	{
		delete[] arr;
	}

	void AddArray(const int& value)
	{
		arr[size++] = value;
	}

	int getLength()
	{
		return size;
	}

	int getArr(int index)
	{
		return arr[index];
	}

	void removeArray(int index)
	{
		for (int i = index; i < size - 1; ++i)
		{
			arr[i] = arr[i + 1];
		}
		size--;
	}

};


int main()
{
	Array arr;

	arr.InitArray(5);

	arr.AddArray(10);
	arr.AddArray(20);
	arr.AddArray(30);

	arr.removeArray(2);

	for (int i = 0; i < arr.getLength(); ++i)
	{
		cout << arr.getArr(i) << " ";
	}
	cout << endl;

	arr.UninitArray();

	return 0;
}
*/

//------------------------------------------------------------

/*
struct Array
{
	int* arr;
	int size;
};

void AddArray(Array& arr, const int& value)
{
	arr.arr[arr.size++] = value;
}

void InitArray(Array& arr, const int& length)
{
	arr.arr = new int[length];
	arr.size = 0;
}

void UninitArray(Array& arr)
{
	delete[] arr.arr;
}

int getLength(Array& arr)
{
	return arr.size;
}

int getArr(Array& arr, int index)
{
	return arr.arr[index];
}

void removeArray(Array& arr, int index)
{
	for (int i = index; i < arr.size - 1; ++i)
	{
		arr.arr[i] = arr.arr[i + 1];
	}
	arr.size--;
}

int main()
{
	Array arr;

	InitArray(arr, 5);

	AddArray(arr, 10);
	AddArray(arr, 20);
	AddArray(arr, 30);

	removeArray(arr, 0);

	for (int i = 0; i < getLength(arr); ++i)
	{
		cout << getArr(arr, i) << " ";
	}
	cout << endl;

	UninitArray(arr);

	return 0;
}
*/

//--------------------------------------------------------------------

/*
struct Array
{
	int* arr;
	int size;
};

void AddArray(Array& arr, const int& value)
{
	arr.arr[arr.size++] = value;
}

void InitArray(Array& arr, const int& length)
{
	arr.arr = new int[length];
	arr.size = 0;
}

void UninitArray(Array& arr)
{
	delete[] arr.arr;
}

int getLength(Array& arr)
{
	return arr.size;
}

int getArr(Array& arr, int index)
{
	return arr.arr[index];
}

int main()
{
	Array arr;

	InitArray(arr, 5);

	AddArray(arr, 10);
	AddArray(arr, 20);
	AddArray(arr, 30);

	for (int i = 0; i < getLength(arr); ++i)
	{
		cout << getArr(arr, i) << " ";
	}
	cout << endl;

	UninitArray(arr);

	return 0;
}
*/

//----------------------------------------------------------

/*
struct Array
{
	int* arr;
	int size;
};

void AddArray(Array& arr, const int& value)
{
	arr.arr[arr.size++] = value;
}

void printArray(const Array& arr)
{
	for (int i = 0; i < arr.size; ++i)
		cout << arr.arr[i] << " ";
	cout << endl;
}

void InitArray(Array& arr, const int& length)
{
	arr.arr = new int[length];
	arr.size = 0;
}

void UninitArray(Array& arr)
{
	delete[] arr.arr;
}

int main()
{
	Array arr;

	InitArray(arr, 5);

	AddArray(arr, 10);
	AddArray(arr, 20);
	AddArray(arr, 30);

	printArray(arr);

	UninitArray(arr);

	return 0;
}
*/

//---------------------------------------------------------------

/*
struct Array
{
	int arr[5] = { 0 };
	int size;
};

void AddArray(Array& arr, const int& value)
{
	arr.arr[arr.size++] = value;
}

void printArray(const Array& arr)
{
	for (int i = 0; i < arr.size; ++i)
		cout << arr.arr[i] << " ";
	cout << endl;
}

void InitArray(Array& arr)
{
	arr.size = 0;
}

void UninitArray(Array& arr)
{

}

int main()
{
	Array arr;

	InitArray(arr);

	AddArray(arr, 10);
	AddArray(arr, 20);
	AddArray(arr, 30);

	printArray(arr);

	UninitArray(arr);

	return 0;
}
*/

//-----------------------------------------------------------

/*
struct Array
{
	int arr[5] = { 0 };
	int size = 0;
};

void AddArray(Array& arr, const int& value)
{
	arr.arr[arr.size++] = value;
}

void printArray(const Array& arr)
{
	for (int i = 0; i < arr.size; ++i)
		cout << arr.arr[i] << " ";
	cout << endl;
}

int main()
{
	Array arr;

	AddArray(arr, 10);
	AddArray(arr, 20);
	AddArray(arr, 30);

	printArray(arr);

	return 0;
}
*/

//--------------------------------------------------------------------

/*
void AddArray(int* arr, int& size, const int value)
{
	arr[size++] = value;
}

void printArray(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int arr[5] = { 0 };
	int size = 0;

	AddArray(arr, size, 10);
	AddArray(arr, size, 20);
	AddArray(arr, size, 30);

	printArray(arr, size);

	return 0;
}
*/

//-----------------------------------------------------------------------

/*
int main()
{
	int arr[5] = { 0 };
	int size = 0;

	arr[size++] = 10;
	arr[size++] = 20;
	arr[size++] = 30;

	for (int i = 0; i < size; ++i)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}
*/

//-----------------------------------------------------------------

/*
int main()
{
	int* arr = new int[5]{ 10,20,30,40,50 };

	for (int i = 0; i < 5; ++i)
		cout << arr[i] << " ";
	cout << endl;

	delete[] arr;

	return 0;
}
*/

//------------------------------------------------------------------

/*
int main()
{
	int arr[5] = { 10,20,30,40,50 };

	for (int i = 0; i < 5; ++i)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}
*/