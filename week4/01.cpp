#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* prev;
	Node* next;
};

class List
{
private:
	Node* head;
	Node* tail;

	Node* allocNode(int data)
	{
		Node* n = new Node;
		n->data = data;
		n->prev = nullptr;
		n->next = nullptr;

		return n;
	}
public:
	List()
	{
		head = allocNode(0); //더미노드
		tail = allocNode(0); //더미노드

		head->next = tail;
		tail->prev = head;
	}

	~List()
	{
		/*for (Node* p = list.head; p != NULL;)
		{
			Node* np = p->next;
			delete p;
			p = np;
		}*/

		Node* thisNode = head;
		Node* preNode = nullptr;

		while (thisNode != nullptr)
		{
			preNode = thisNode;
			thisNode = thisNode->next;

			delete preNode;
		}
	}
	

	void addList(int data)
	{
		Node* p = allocNode(data);

		Node* ptail = tail->prev;

		ptail->next = p;
		p->prev = ptail;
		tail->prev = p;
		p->next = tail;
	}

	void printNextList()
	{
		Node* thisNode = head->next;

		while (thisNode->next != nullptr) //thisNode != tail
		{
			cout << thisNode->data << endl;
			thisNode = thisNode->next;
		}
	}

	void printPrevList()
	{
		Node* thisNode = tail->prev;

		while (thisNode->prev != nullptr) //thisNode != head
		{
			cout << thisNode->data << endl;
			thisNode = thisNode->prev;
		}
	}
};

int main()
{
	List list;

	list.addList(10);

	list.addList(20);

	list.addList(30);

	list.printNextList();

	list.printPrevList();

	return 0;
}

//-----------------------------------------------------------------

/*
struct Node
{
	int data;
	Node* prev;
	Node* next;
};

struct List
{
	Node* head;
	Node* tail;
};

Node* allocNode(int data)
{
	Node* n = new Node;
	n->data = data;
	n->prev = nullptr;
	n->next = nullptr;

	return n;
}

void addList(List& list, int data)
{
	Node* p = allocNode(data);

	Node* ptail = list.tail->prev;

	ptail->next = p;
	p->prev = ptail;
	list.tail->prev = p;
	p->next = list.tail;
}

void printNextList(List& list)
{
	Node* thisNode = list.head->next;
	
	while (thisNode->next != nullptr) //thisNode != tail
	{
		cout << thisNode->data << endl;
		thisNode = thisNode->next;
	}
}

void printPrevList(List& list)
{
	Node* thisNode = list.tail->prev;

	while (thisNode->prev != nullptr) //thisNode != head
	{
		cout << thisNode->data << endl;
		thisNode = thisNode->prev;
	}
}

void InitList(List& list)
{
	list.head = allocNode(0); //더미노드
	list.tail = allocNode(0); //더미노드

	list.head->next = list.tail;
	list.tail->prev = list.head;
}

void UninitList(List& list)
{
	//for (node* p = list.head; p != null;)
	//{
	//	node* np = p->next;
	//	delete p;
	//	p = np;
	//}

	Node* thisNode = list.head;
	Node* preNode = nullptr;

	while (thisNode != nullptr)
	{
		preNode = thisNode;
		thisNode = thisNode->next;

		delete preNode;
	}
}

int main()
{
	List list;

	InitList(list);

	addList(list, 10);

	addList(list, 20);

	addList(list, 30);

	printNextList(list);

	printPrevList(list);

	UninitList(list);

	return 0;
}
*/

//----------------------------------------------------------------

/*
struct Node
{
	int data;
	Node* prev;
	Node* next;
};

struct List
{
	Node* head;
	Node* tail;
};

Node* allocNode(int data)
{
	Node* n = new Node;
	n->data = data;
	n->prev = nullptr;
	n->next = nullptr;

	return n;
}

void addList(List& list, int data)
{
	Node* p = allocNode(data);

	Node* ptail = list.tail->prev;

	ptail->next = p;
	p->prev = ptail;
	list.tail->prev = p;
	p->next = list.tail;
}

void printNextList(List& list)
{
	cout << list.head->next->data << endl;
	cout << list.head->next->next->data << endl;
	cout << list.head->next->next->next->data << endl;
}

void printPrevList(List& list)
{
	cout << list.tail->prev->data << endl;
	cout << list.tail->prev->prev->data << endl;
	cout << list.tail->prev->prev->prev->data << endl;
}

void InitList(List& list)
{
	list.head = allocNode(0); //더미노드
	list.tail = allocNode(0); //더미노드

	list.head->next = list.tail;
	list.tail->prev = list.head;
}

void UninitList(List& list)
{

}

int main()
{
	List list;

	InitList(list);

	addList(list, 10);

	addList(list, 20);

	addList(list, 30);

	printNextList(list);

	printPrevList(list);

	UninitList(list);

	return 0;
}
*/

//--------------------------------------------------------------

/*
struct Node
{
	int data;
	Node* prev;
	Node* next;
};

struct List
{
	Node* head;
	Node* tail;
};

Node* allocNode(int data)
{
	Node* n = new Node;
	n->data = data;
	n->prev = nullptr;
	n->next = nullptr;

	return n;
}

void addNode(List& list, int data)
{
	Node* p = allocNode(data);

	Node* ptail = list.tail->prev;

	ptail->next = p;
	p->prev = ptail;
	list.tail->prev = p;
	p->next = list.tail;
}

void printNextList(List& list)
{
	cout << list.head->next->data << endl;
	cout << list.head->next->next->data << endl;
	cout << list.head->next->next->next->data << endl;
}

void printPrevList(List& list)
{
	cout << list.tail->prev->data << endl;
	cout << list.tail->prev->prev->data << endl;
	cout << list.tail->prev->prev->prev->data << endl;
}

int main()
{
	List list;
	list.head = allocNode(0); //더미노드
	list.tail = allocNode(0); //더미노드
	
	list.head->next = list.tail;
	list.tail->prev = list.head;

	addNode(list, 10);

	addNode(list, 20);

	addNode(list, 30);

	printNextList(list);

	printPrevList(list);

	return 0;
}
*/

//-----------------------------------------------------------

/*
struct Node
{
	int data;
	Node* prev;
	Node* next;
};

Node* allocNode(int data)
{
	Node* n = new Node;
	n->data = data;
	n->prev = nullptr;
	n->next = nullptr;

	return n;
}

void addNode(Node* head, Node* tail, int data)
{
	Node* p = allocNode(data);

	Node* ptail = tail->prev;

	ptail->next = p;
	p->prev = ptail;
	tail->prev = p;
	p->next = tail;
}

int main()
{
	Node* head = allocNode(0); //더미노드
	Node* tail = allocNode(0); //더미노드
	head->next = tail;
	tail->prev = head;

	addNode(head, tail, 10);

	addNode(head, tail, 20);

	addNode(head, tail, 30);

	cout << head->next->data << endl;
	cout << head->next->next->data << endl;
	cout << head->next->next->next->data << endl;

	cout << tail->prev->data << endl;
	cout << tail->prev->prev->data << endl;
	cout << tail->prev->prev->prev->data << endl;

	return 0;
}
*/

//----------------------------------------------------------------

/*
struct Node
{
	int data;
	Node* prev;
	Node* next;
};

Node* allocNode(int data)
{
	Node* n = new Node;
	n->data = data;
	n->prev = nullptr;
	n->next = nullptr;

	return n;
}

int main()
{
	Node* head = allocNode(0); //더미노드
	Node* tail = allocNode(0); //더미노드
	head->next = tail;
	tail->prev = head;

	Node* p = allocNode(10);

	Node* ptail = tail->prev;

	ptail->next = p;
	p->prev = ptail;
	tail->prev = p;
	p->next = tail;

	p = allocNode(20);

	ptail = tail->prev;

	ptail->next = p;
	p->prev = ptail;
	tail->prev = p;
	p->next = tail;

	p = allocNode(30);

	ptail = tail->prev;

	ptail->next = p;
	p->prev = ptail;
	tail->prev = p;
	p->next = tail;

	cout << head->next->data << endl;
	cout << head->next->next->data << endl;
	cout << head->next->next->next->data << endl;

	cout << tail->prev->data << endl;
	cout << tail->prev->prev->data << endl;
	cout << tail->prev->prev->prev->data << endl;

	return 0;
}
*/

//-----------------------------------------------------------

/*
struct Node
{
	int data;
	Node* prev;
	Node* next;
};

Node* allocNode(int data)
{
	Node* n = new Node;
	n->data = data;
	n->prev = nullptr;
	n->next = nullptr;

	return n;
}

int main()
{
	Node* head = nullptr;
	Node* tail = nullptr;

	Node* p = allocNode(10);

	head = p;
	tail = p;

	p = allocNode(20);

	tail->next = p;
	p->prev = tail;
	tail = p;

	p = allocNode(30);

	tail->next = p;
	p->prev = tail;
	tail = p;

	cout << head->data << endl;
	cout << head->next->data << endl;
	cout << head->next->next->data << endl;

	cout << tail->data << endl;
	cout << tail->prev->data << endl;
	cout << tail->prev->prev->data << endl;

	return 0;
}
*/

//------------------------------------------------------------

/*
struct Node
{
	int data;
	Node* link;
};

Node* allocNode(int data)
{
	Node* node = new Node;
	
	node->data = data;
	node->link = NULL;

	return node;
}

int main()
{
	Node* head = NULL;

	head = allocNode(10);
	head->link = allocNode(20);
	head->link->link = allocNode(30);
	head->link->link->link = allocNode(40);
	head->link->link->link->link = allocNode(50);

	for (Node* p = head; p != NULL; p = p->link)
	{
		cout << p->data << endl;
	}

	return 0;
}
*/

//---------------------------------------------------------------

/*
struct Node
{
	int data;
	Node* link;
};

int main()
{
	Node n1 = { 10, NULL };
	Node n2 = { 20, NULL };
	Node n3 = { 30, NULL };
	Node n4 = { 40, NULL };
	Node n5 = { 50, NULL };

	n1.link = &n2;
	n2.link = &n3;
	n3.link = &n4;
	n4.link = &n5;

	Node* head = &n1;

	for (Node* p = head; p != NULL; p = p->link)
	{
		cout << p->data << endl;
	}

	return 0;
}
*/

//----------------------------------------------------------------

/*
struct Node
{
	int data;
	Node* link;
};

int main()
{
	Node n1 = { 10, NULL };
	Node n2 = { 20, NULL };
	Node n3 = { 30, NULL };
	Node n4 = { 40, NULL };
	Node n5 = { 50, NULL };

	n1.link = &n2;
	n2.link = &n3;
	n3.link = &n4;
	n4.link = &n5;

	Node* head = &n1;

	Node* p = head;
	cout << p->data << endl;

	p = p->link;
	cout << p->data << endl;

	p = p->link;
	cout << p->data << endl;

	p = p->link;
	cout << p->data << endl;

	p = p->link;
	cout << p->data << endl;

	return 0;
}
*/

//-----------------------------------------------------------------------

/*
struct Node
{
	int data;
	Node* link;
};

int main()
{
	Node n1 = { 10, NULL };
	Node n2 = { 20, NULL };
	Node n3 = { 30, NULL };
	Node n4 = { 40, NULL };
	Node n5 = { 50, NULL };

	n1.link = &n2;
	n2.link = &n3;
	n3.link = &n4;
	n4.link = &n5;

	Node* head = &n1;
	cout << head->data << endl;
	cout << head->link->data << endl;
	cout << head->link->link->data << endl;
	cout << head->link->link->link->data << endl;
	cout << head->link->link->link->link->data << endl;

	return 0;
}
*/

//----------------------------------------------------------------------

/*
struct Node
{
	int data;
	Node* link;
};

int main()
{
	Node n1 = { 10, NULL };
	Node n2 = { 20, NULL };
	Node n3 = { 30, NULL };
	Node n4 = { 40, NULL };
	Node n5 = { 50, NULL };

	n1.link = &n2;
	n2.link = &n3;
	n3.link = &n4;
	n4.link = &n5;

	return 0;
}
*/