#include <iostream>
using namespace std;

class Node
{
private:
	int data;
	Node* next;

public:
	Node(const int& data_i) : data(data_i), next(nullptr) {}
	~Node() {}

	void setNext(Node* node) { next = node; }
	Node* getNext() { return next; }

	int getData() { return data; }
};

class List
{
private:
	Node* head;

public:
	List() :head(nullptr) {}
	~List() {}

	void add(Node& node);
	void remove(const int& data);
	void print();
};

void List::add(Node& node)
{
	if (head == nullptr)
	{
		head = &node;
	}
	else
	{
		Node* thisNode = head;

		while (true)
		{
			if (thisNode->getNext() == nullptr)
			{
				thisNode->setNext(&node);
				break;
			}
			else
			{
				thisNode = thisNode->getNext();
			}
		}
	}
}

void List::remove(const int& data)
{
	if (head == nullptr)
	{
		return;
	}
	else
	{
		Node* thisNode = head;
		Node* preNode = nullptr;

		while (true)
		{
			if (thisNode->getData() == data)
			{
				preNode->setNext(thisNode->getNext());
				break;
			}
			else if (thisNode->getNext() == nullptr)
			{
				break;
			}
			else
			{
				preNode = thisNode;
				thisNode = thisNode->getNext();
			}
		}
	}
}

void List::print()
{
	if (head != nullptr)
	{
		Node* thisNode = head;

		while (thisNode != nullptr)
		{
			cout << thisNode->getData() << endl;

			thisNode = thisNode->getNext();
		}
	}
}

int main()
{
	Node n1(10);
	Node n2(20);
	Node n3(30);

	List list;

	list.add(n1);
	list.add(n2);
	list.add(n3);

	list.print();
	cout << endl;

	list.remove(20);

	list.print();
	cout << endl;

	Node n4(40);
	list.add(n4);

	list.print();
	return 0;
}