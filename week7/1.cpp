#include <iostream>
#include <list>
#include <array>
using namespace std;

struct Hash
{
	list<int>* table;
	int tableSize;

	//function pointer
	//int 반환타입 , hashFun 함수포인터 이름, (int , int) 함수 매개변수
	int (*hashFun)(int , int);
};


int hashFun(int key, int tableSize)
{
	int addr = 0;

	addr = key % tableSize;

	return addr;
}

void push(Hash& h, int key)
{
	int addr = (h.hashFun)(key, h.tableSize);

	h.table[addr].push_back(key);
}

bool find(Hash& h, int key)
{
	int addr = (h.hashFun)(key, h.tableSize);

	for (list<int>::iterator iter = h.table[addr].begin(); iter != h.table[addr].end(); ++iter)
	{
		if (*iter == key)
		{
			return true;
		}
	}

	return false;
}

void pop(Hash& h, int key)
{
	int addr = (h.hashFun)(key, h.tableSize);

	for (list<int>::iterator iter = h.table[addr].begin(); iter != h.table[addr].end(); ++iter)
	{
		if (*iter == key)
		{
			h.table[addr].erase(iter);
			break;
		}
	}
}

void printHash(Hash& h)
{
	for (int i = 0; i < h.tableSize; ++i)
	{
		cout << "[ " << i << " ] : ";

		for (list<int>::iterator iter = h.table[i].begin(); iter != h.table[i].end(); ++iter)
		{
			cout << *iter << " ";
		}

		cout << endl;
	}
}

void initHash(Hash& h, int size, int (*phf)(int, int) = 0)
{
	if (phf == 0) //디폴트 값
		h.hashFun = hashFun;
	else //함수포인터 phf값이 세팅이 되면
		h.hashFun = phf;
	
	h.tableSize = size;
	h.table = new list<int>[size];
}

void uninitHash(Hash& h)
{
	delete[] h.table;
}

int myHashFun(int key, int tableSize)
{
	return (key >> 2) % tableSize;
}

int main()
{
	Hash h;

	initHash(h, 10, myHashFun); //user hashFunction
	//initHash(h, 10); //default hashFunction

	push(h, 10);
	push(h, 57);
	push(h, 65);
	push(h, 59);
	push(h, 32);
	push(h, 20);

	printHash(h);

	uninitHash(h);

	return 0;
}

//struct Hash
//{
//	list<int>* table;
//	int tableSize;
//};
//
//
//int hashFun(int key, int tableSize)
//{
//	int addr = 0;
//
//	addr = key % tableSize;
//
//	return addr;
//}
//
//void push(Hash& h, int key)
//{
//	int addr = hashFun(key, h.tableSize);
//
//	h.table[addr].push_back(key);
//}
//
//bool find(Hash& h, int key)
//{
//	int addr = hashFun(key, h.tableSize);
//
//	for (list<int>::iterator iter = h.table[addr].begin(); iter != h.table[addr].end(); ++iter)
//	{
//		if (*iter == key)
//		{
//			return true;
//		}
//	}
//
//	return false;
//}
//
//void pop(Hash& h, int key)
//{
//	int addr = hashFun(key, h.tableSize);
//
//	for (list<int>::iterator iter = h.table[addr].begin(); iter != h.table[addr].end(); ++iter)
//	{
//		if (*iter == key)
//		{
//			h.table[addr].erase(iter);
//			break;
//		}
//	}
//}
//
//void printHash(Hash& h)
//{
//	for (int i = 0; i < h.tableSize; ++i)
//	{
//		cout << "[ " << i << " ] : ";
//
//		for (list<int>::iterator iter = h.table[i].begin(); iter != h.table[i].end(); ++iter)
//		{
//			cout << *iter << " ";
//		}
//
//		cout << endl;
//	}
//}
//
//void initHash(Hash& h, int size)
//{
//	h.tableSize = size;
//	h.table = new list<int>[size];
//}
//
//void uninitHash(Hash& h)
//{
//	delete[] h.table;
//}
//
//
//
//int main()
//{
//	Hash h;
//
//	initHash(h, 10);
//
//	push(h, 10);
//	push(h, 57);
//	push(h, 65);
//	push(h, 59);
//	push(h, 32);
//	push(h, 20);
//
//	printHash(h);
//
//	pop(h, 65);
//
//	printHash(h);
//
//	uninitHash(h);
//
//	return 0;
//}

//struct Hash
//{
//	list<int>* table;
//	int tableSize;
//};
//
//
//int hashFun(int key, int tableSize)
//{
//	int addr = 0;
//
//	addr = key % tableSize;
//
//	return addr;
//}
//
//void push(Hash& h, int key)
//{
//	int addr = hashFun(key, h.tableSize);
//
//	h.table[addr].push_back(key);
//}
//
//bool find(Hash& h, int key)
//{
//	int addr = hashFun(key, h.tableSize);
//
//	for (list<int>::iterator iter = h.table[addr].begin(); iter != h.table[addr].end(); ++iter)
//	{
//		if (*iter == key)
//		{
//			return true;
//		}
//	}
//
//	return false;
//}
//
//void printHash(Hash& h)
//{
//	for (int i = 0; i < h.tableSize; ++i)
//	{
//		cout << "[ " << i << " ] : ";
//
//		for (list<int>::iterator iter = h.table[i].begin(); iter != h.table[i].end(); ++iter)
//		{
//			cout << *iter << " ";
//		}
//
//		cout << endl;
//	}
//}
//
//void initHash(Hash& h, int size)
//{
//	h.tableSize = size;
//	h.table = new list<int>[size];
//}
//
//void uninitHash(Hash& h)
//{
//	delete[] h.table;
//}
//
//int main()
//{
//	Hash h;
//
//	initHash(h, 100);
//
//	push(h, 10);
//	push(h, 57);
//	push(h, 65);
//	push(h, 59);
//	push(h, 32);
//	push(h, 20);
//
//	printHash(h);
//
//	if (find(h, 52) == true)
//		cout << "true" << endl;
//	else
//		cout << "false" << endl;
//
//	uninitHash(h);
//
//	return 0;
//}

//struct Hash
//{
//	list<int> table[10];
//};
//
//
//int hashFun(int key)
//{
//	int addr = 0;
//
//	addr = key % 10;
//
//	return addr;
//}
//
//void push(Hash& h, int key)
//{
//	int addr = hashFun(key);
//
//	h.table[addr].push_back(key);
//}
//
//bool find(Hash& h, int key)
//{
//	int addr = hashFun(key);
//
//	for (list<int>::iterator iter = h.table[addr].begin(); iter != h.table[addr].end(); ++iter)
//	{
//		if (*iter == key)
//		{
//			return true;
//		}
//	}
//
//	return false;
//}
//
//void printHash(Hash& h)
//{
//	for (int i = 0; i < 10; ++i)
//	{
//		cout << "[ " << i << " ] : ";
//
//		for (list<int>::iterator iter = h.table[i].begin(); iter != h.table[i].end(); ++iter)
//		{
//			cout << *iter << " ";
//		}
//
//		cout << endl;
//	}
//}
//
//int main()
//{
//	Hash h;
//
//	push(h, 10);
//	push(h, 57);
//	push(h, 65);
//	push(h, 59);
//	push(h, 32);
//	push(h, 20);
//
//	printHash(h);
//
//	if (find(h, 52) == true)
//		cout << "true" << endl;
//	else
//		cout << "false" << endl;
//
//	return 0;
//}

//list<int> table[10];
//
//int hashFun(int key)
//{
//	int addr = 0; 
//
//	addr = key % 10;
//
//	return addr;
//}
//
//void push(int key)
//{
//	int addr = hashFun(key);
//
//	table[addr].push_back(key);
//}
//
//bool find(int key)
//{
//	int addr = hashFun(key);
//
//	for (list<int>::iterator iter = table[addr].begin(); iter != table[addr].end(); ++iter)
//	{
//		if (*iter == key)
//		{
//			return true;
//		}
//	}
//
//	return false;
//}
//
//void printHash()
//{
//	for (int i = 0; i < 10; ++i)
//	{
//		cout << "[ " << i << " ] : ";
//
//		for (list<int>::iterator iter = table[i].begin(); iter != table[i].end(); ++iter)
//		{
//			cout << *iter << " ";
//		}
//		
//		cout << endl;
//	}
//}
//
//int main()
//{
//	push(10);
//	push(57);
//	push(65);
//	push(59);
//	push(32);
//	push(20);
//
//	printHash();
//
//	if (find(52) == true)
//		cout << "true" << endl;
//	else
//		cout << "false" << endl;
//
//	return 0;
//}

//int main()
//{
//	list<int> li;
//
//	li.push_back(10);
//	li.push_back(20);
//	li.push_back(30);
//
//	//begin() 첫번째 원소 가르킴
//	list<int>::iterator iter = li.begin();
//
//	li.erase(iter);
//
//	//end() 마지막 다음 원소 가르킴
//	//list<int>::iterator endIter = li.end();
//
//	for (list<int>::iterator iter = li.begin(); iter != li.end(); ++iter)
//	{
//		cout << *iter << endl;
//	}
//
//	return 0;
//}

//int main()
//{
//	list<int> li;
//
//	li.push_back(10);
//	li.push_back(20);
//	li.push_back(30);
//
//	//begin() 첫번째 원소 가르킴
//	list<int>::iterator iter = li.begin();
//
//	//end() 마지막 다음 원소 가르킴
//	list<int>::iterator endIter = li.end();
//
//	for (; iter != endIter; ++iter)
//	{
//		cout << *iter << endl;
//	}
//
//	return 0;
//}

//int main()
//{
//	list<int> li;
//
//	li.push_back(10);
//	li.push_back(20);
//	li.push_back(30);
//
//	list<int>::iterator iter = li.begin();
//
//	cout << *iter << endl;
//	iter++;
//
//	cout << *iter << endl;
//	iter++;
//
//	cout << *iter << endl;
//	return 0;
//}