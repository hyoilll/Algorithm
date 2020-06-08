#include <iostream>
#include <algorithm> //heap
#include <queue>

using namespace std;

void printList(int* list)
{
	int size = list[0];

	cout << "size : " << size << endl;

	for (int i = 1; i <= size; ++i)
	{
		cout << list[i] << " ";
	}
	cout << endl;
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Push_heap(int* list)
{
	int size = ++list[0];
	int child = size; // new value
	int parent = child / 2;

	while (parent != 0)
	{
		if (list[child] > list[parent])
		{
			swap(list[child], list[parent]);
		}
		else
			break;

		child = parent;
		parent = child / 2;
	}
}

void Make_heap(int* list, int size)
{
	for (int i = 0; i < size; ++i)
	{
		Push_heap(list);
	}
}

int maxIdx(int* list, const int& left, const int& right)
{
	return list[left] > list[right] ? left : right;
}

void Pop_heap(int* list)
{
	swap(list[1], list[list[0]]);
	list[0]--;

	int parent = 1;
	int child = parent * 2; //left-child : 2, right-child : 3

	while (child <= list[0])
	{
		//left-child, right-child ªÎñéªÇÓŞª­ª¤ªâªÎªËª·ªŞª¹¡£
		//ñ§ö°ª·ª«ò¥ªÃªÆªÊª¤ªÈª­
		if (list[0] > child)
			child = maxIdx(list, child, child + 1);

		if (list[child] > list[parent])
		{
			swap(list[child], list[parent]);
		}
		else
			break;

		parent = child;
		child = parent * 2;
	}

}

void sort_heap(int* list, int size)
{
	for (int i = 0; i < size; ++i)
	{
		Pop_heap(list);
	}

	for (int i = 1; i <= size; ++i)
	{
		cout << list[i] << " ";
	}
	cout << endl;
}

int main()
{
	int list[10] = { 0, 50,60,30,10,20,90,70,58 };

	printList(list);

	Make_heap(list, 8);

	printList(list);

	sort_heap(list, 8);

	printList(list);

	return 0;
}

//void printList(int* list)
//{
//	int size = list[0];
//
//	cout << "size : " << size << endl;
//
//	for (int i = 1; i <= size; ++i)
//	{
//		cout << list[i] << " ";
//	}
//	cout << endl;
//}
//
//void swap(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//void Push_heap(int* list)
//{
//	int size = ++list[0];
//	int child = size; // new value
//	int parent = child / 2;
//
//	while (parent != 0)
//	{
//		if (list[child] > list[parent])
//		{
//			swap(list[child], list[parent]);
//		}
//		else
//			break;
//
//		child = parent;
//		parent = child / 2;
//	}
//}
//
//void Make_heap(int* list, int size)
//{
//	for (int i = 0; i < size; ++i)
//	{
//		Push_heap(list);
//	}
//}
//
//int maxIdx(int* list, const int& left, const int& right)
//{
//	return list[left] > list[right] ? left : right;
//}
//
//void Pop_heap(int* list)
//{
//	swap(list[1], list[list[0]]);
//	list[0]--;
//
//	int parent = 1;
//	int child = parent * 2; //left-child : 2, right-child : 3
//	
//	while (child <= list[0])
//	{
//		//left-child, right-child ªÎñéªÇÓŞª­ª¤ªâªÎªËª·ªŞª¹¡£
//		//ñ§ö°ª·ª«ò¥ªÃªÆªÊª¤ªÈª­
//		if (list[0] > child)
//			child = maxIdx(list, child, child + 1);
//
//		if (list[child] > list[parent])
//		{
//			swap(list[child], list[parent]);
//		}
//		else
//			break;
//
//		parent = child;
//		child = parent * 2;
//	}
//
//}
//
//int main()
//{
//	int list[10] = { 0, 50,60,30,10,20,90,70,58 };
//
//	printList(list);
//
//	Make_heap(list, 8);
//
//	printList(list);
//
//	Pop_heap(list);
//	Pop_heap(list);
//	Pop_heap(list);
//	Pop_heap(list);
//	Pop_heap(list);
//	Pop_heap(list);
//	Pop_heap(list);
//	Pop_heap(list);
//
//	printList(list);
//
//	return 0;
//}

//void printList(int* list)
//{
//	int size = list[0];
//
//	cout << "size : " << size << endl;
//
//	for (int i = 1; i <= size; ++i)
//	{
//		cout << list[i] << " ";
//	}
//	cout << endl;
//}
//
//void swap(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//void Push_heap(int* list)
//{
//	int size = ++list[0];
//	int child = size; // new value
//	int parent = child / 2;
//
//	while (parent != 0)
//	{
//		if (list[child] > list[parent])
//		{
//			swap(list[child], list[parent]);
//		}
//		else
//			break;
//
//		child = parent;
//		parent = child / 2;
//	}
//}
//
//void Make_heap(int* list, int size)
//{
//	for (int i = 0; i < size; ++i)
//	{
//		Push_heap(list);
//	}
//}
//
//int maxIdx(int* list, const int& left, const int& right)
//{
//	return list[left] > list[right] ? left : right;
//}
//
//void Pop_heap(int* list)
//{
//	swap(list[1], list[list[0]]);
//	list[0]--;
//
//	int child = 2; //left-child : 2, right-child : 3
//	int parent = 1;
//	
//	while (child <= list[0])
//	{
//		//left-child, right-child ªÎñéªÇÓŞª­ª¤ªâªÎªËª·ªŞª¹¡£
//		if (list[0] > child)
//			child = maxIdx(list, child, child + 1);
//
//		if (list[child] > list[parent])
//		{
//			swap(list[child], list[parent]);
//		}
//		else
//			break;
//
//		parent = child;
//		child = parent * 2;
//	}
//
//}
//
//int main()
//{
//	int list[10] = { 0, 50,60,30,10,20,90,70,58 };
//
//	printList(list);
//
//	Make_heap(list, 8);
//
//	printList(list);
//
//	Pop_heap(list);
//	
//	printList(list);
//
//	return 0;
//}

//void printList(int* list)
//{
//	int size = list[0];
//
//	cout << "size : " << size << endl;
//
//	for (int i = 1; i <= size; ++i)
//	{
//		cout << list[i] << " ";
//	}
//	cout << endl;
//}
//
//void swap(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//void Push_heap(int* list)
//{
//	int size = ++list[0];
//	int child = size; // new value
//	int parent = child / 2;
//
//	while (parent != 0)
//	{
//		if (list[child] > list[parent])
//		{
//			swap(list[child], list[parent]);
//		}
//		else
//			break;
//
//		child = parent;
//		parent = child / 2;
//	}
//}
//
//void Make_heap(int* list, int size)
//{
//	for (int i = 0; i < size; ++i)
//	{
//		Push_heap(list);
//	}
//}
//
//int main()
//{
//	int list[10] = { 0, 50,60,30,10,20,90,70,58 };
//
//	printList(list);
//
//	Make_heap(list, 8);
//
//	printList(list);
//	return 0;
//}

//void printList(int* list)
//{
//	int size = list[0];
//
//	cout << "size : " << size << endl;
//
//	for (int i = 1; i <= size; ++i)
//	{
//		cout << list[i] << " ";
//	}
//	cout << endl;
//}
//
//void swap(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//void Push_heap(int* list)
//{
//	int size = ++list[0];
//	int child = size; // new value
//	int parent = child / 2;
//
//	while (parent != 0)
//	{
//		if (list[child] > list[parent])
//		{
//			swap(list[child], list[parent]);
//		}
//		else
//			break;
//
//		child = parent;
//		parent = child / 2;
//	}
//}
//
//int main()
//{
//	int list[10] = { 0, 50,60,30,10,20,90,70,58 };
//
//	printList(list);
//
//	Push_heap(list);
//	Push_heap(list);
//	Push_heap(list);
//	Push_heap(list);
//	Push_heap(list);
//	Push_heap(list);
//	Push_heap(list);
//	Push_heap(list);
//
//	printList(list);
//	return 0;
//}

//void printList(int* list)
//{
//	int size = list[0];
//
//	cout << "size : " << size << endl;
//
//	for (int i = 1; i <= size; ++i)
//	{
//		cout << list[i] << " ";
//	}
//	cout << endl;
//}
//
//void swap(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//void Push_heap(int* list)
//{
//	int size = ++list[0];
//	int child = size; // new value
//	int parent = child / 2;
//
//	while (parent != 0)
//	{
//		if (list[child] > list[parent])
//		{
//			swap(list[child], list[parent]);
//		}
//		else
//			break;
//
//		child = parent;
//		parent = child / 2;
//	}
//}
//
//int main()
//{
//	int list[10] = { 5, 60,50,30,10,20,55,70,58 };
//
//	printList(list);
//
//	Push_heap(list);
//
//	printList(list);
//	return 0;
//}

//void printList(int* list)
//{
//	int size = list[0];
//
//	cout << "size : " << size << endl;
//
//	for (int i = 1; i <= size; ++i)
//	{
//		cout << list[i] << " ";
//	}
//	cout << endl;
//}
//
//int main()
//{
//	int list[10] = {8, 50,60,30,10,20,90,70,58 };
//
//	printList(list);
//
//	return 0;
//}

//void printList(int* list, int size)
//{
//	for (int i = 0; i < size; ++i)
//	{
//		cout << list[i] << " ";
//	}
//	cout << endl;
//}
//
//class Priority_queue
//{
//private:
//	int heap[10];
//	int size;
//
//public:
//	Priority_queue() :size(0) {}
//	
//	void push(int data)
//	{
//		heap[size++] = data;
//		push_heap(heap, heap + size);
//	}
//
//	int top()
//	{
//		return heap[0];
//	}
//
//	void pop()
//	{
//		pop_heap(heap, heap + size);
//		size--;
//	}
//};
//
//int main()
//{
//	Priority_queue q;
//
//	q.push(50);
//	q.push(60);
//	q.push(30);
//	q.push(10);
//	q.push(20);
//	q.push(90);
//	q.push(70);
//	q.push(58);
//
//	cout << q.top() << endl;
//	q.pop();
//
//	cout << q.top() << endl;
//	q.pop();
//
//	return 0;
//}

//void printList(int* list, int size)
//{
//	for (int i = 0; i < size; ++i)
//	{
//		cout << list[i] << " ";
//	}
//	cout << endl;
//}
//
//int main()
//{
//	//int list[10] = { 50,60,30,10,20,90,70,58 };
//	//int size = 8;
//
//	//printList(list, size);
//
//	//make_heap(list, list + size); //start, end
//
//	//printList(list, size);
//
//	//sort_heap(list, list + size);
//
//	//printList(list, size);
//
//	priority_queue<int> q;
//
//	q.push(50);
//	q.push(60);
//	q.push(30);
//	q.push(10);
//	q.push(20);
//	q.push(90);
//	q.push(70);
//	q.push(58);
//
//	cout << q.top() << endl;
//	q.pop();
//
//	cout << q.top() << endl;
//	q.pop();
//
//	return 0;
//}

//void printList(int* list, int size)
//{
//	for (int i = 0; i < size; ++i)
//	{
//		cout << list[i] << " ";
//	}
//	cout << endl;
//}
//
//int main()
//{
//	int list[10] = { 50,60,30,10,20,90,70,58 };
//	int size = 8;
//
//	printList(list, size);
//
//	make_heap(list, list + size); //start, end
//
//	printList(list, size);
//
//	sort_heap(list, list + size);
//
//	printList(list, size);
//	return 0;
//}

//void printList(int* list, int size)
//{
//	for (int i = 0; i < size; ++i)
//	{
//		cout << list[i] << " ";
//	}
//	cout << endl;
//}
//
//int main()
//{
//	int list[10] = { 50,60,30,10,20,90,70,58 };
//	int size = 8;
//
//	printList(list, size);
//
//	make_heap(list, list + size); //start, end
//
//	printList(list, size);
//
//	pop_heap(list, list + size); //delete root
//	--size;
//
//	pop_heap(list, list + size); //delete root
//	--size;
//
//	pop_heap(list, list + size); //delete root
//	--size;
//
//	printList(list, size);
//	return 0;
//}

//void printList(int* list, int size)
//{
//	for (int i = 0; i < size; ++i)
//	{
//		cout << list[i] << " ";
//	}
//	cout << endl;
//}
//
//int main()
//{
//	int list[10] = { 50,60,30,10,20,90,70,58 };
//	int size = 0;
//
//	//	printList(list, size);
//
//	//	make_heap(list, list + size); //start, end
//	++size;
//
//	push_heap(list, list + size);
//	printList(list, size);
//
//	++size;
//	push_heap(list, list + size);
//	printList(list, size);
//	
//	++size;
//	push_heap(list, list + size);
//	printList(list, size);
//
//	++size;
//	push_heap(list, list + size);
//	printList(list, size);
//
//	++size;
//	push_heap(list, list + size);
//	printList(list, size);
//	
//	++size;
//	push_heap(list, list + size);
//	printList(list, size);
//		
//	++size;
//	push_heap(list, list + size);
//	printList(list, size);
//	
//	++size;
//	push_heap(list, list + size);
//	printList(list, size);
//	
//	return 0;
//}

//void printList(int* list, int size)
//{
//	for (int i = 0; i < size; ++i)
//	{
//		cout << list[i] << " ";
//	}
//	cout << endl;
//}
//
//int main()
//{
//	int list[10] = { 50,60,30,10,20,90,70,58 };
//	int size = 0;
//
////	printList(list, size);
//
////	make_heap(list, list + size); //start, end
//
//	push_heap(list, list + 1);
//
//	printList(list, 1);
//
//	push_heap(list, list + 2);
//
//	printList(list, 2);
//
//	push_heap(list, list + 3);
//
//	printList(list, 3);
//
//	push_heap(list, list + 4);
//
//	printList(list, 4);
//
//	push_heap(list, list + 5);
//
//	printList(list, 5);
//
//	push_heap(list, list + 6);
//
//	printList(list, 6);
//
//	push_heap(list, list + 7);
//
//	printList(list, 7);
//
//	push_heap(list, list + 8);
//
//	printList(list, 8);
//
//	return 0;
//}

//void printList(int* list, int size)
//{
//	for (int i = 0; i < size; ++i)
//	{
//		cout << list[i] << " ";
//	}
//	cout << endl;
//}
//
//int main()
//{
//	int list[10] = { 50,60,30,10,20,90,70,58 };
//	int size = 8;
//
//	printList(list, size);
//
//	make_heap(list, list + size); //start, end
//
//	printList(list, size);
//
//	return 0;
//}