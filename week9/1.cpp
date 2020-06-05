#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* link;
};

Node* AllocNode(int data)
{
	Node* p = new Node;
	p->data = data;
	p->link = NULL;
	return p;
}

void AddNode(Node*& head, int data)
{
	if (head == NULL)
		head = AllocNode(data);
	else
	{
		Node* thisNode = head;

		while (true)
		{
			if (thisNode->link == NULL)
			{
				thisNode->link = AllocNode(data);
				break;
			}
			else
			{
				thisNode = thisNode->link;
			}
		}

		/*
			Node* tail;
			for (tail = head; tail->link != NULL; tail = tail->link);

			tail->link = AllocNode(data);
		*/
	}
}

void printNode(Node* head)
{
	for (Node* p = head; p != NULL; p = p->link)
	{
		cout << p->data << endl;
	}
}

void destroyNode(Node* head)
{
	for (Node* p = head; p != NULL; )
	{
		Node* np = p->link;
		delete p;
		p = np;
	}
}

///////////////////////////////////

struct Graph
{
	Node** head;
	int verSize; //������ ����
};

void addEdge(Graph& g, int start, int end)
{
	AddNode(g.head[start], end);
}

void printGraph(Graph& g)
{
	for (int i = 0; i < g.verSize; ++i)
	{
		cout << "vertex : " << i << " edge : ";

		for (Node* p = g.head[i]; p != NULL; p = p->link)
		{
			cout << "( " << i << ", " << p->data << " )";
		}

		cout << endl;
	}
}

void initGraph(Graph& g, int verSize)
{
	g.head = new Node * [verSize];

	for (int i = 0; i < verSize; ++i)
	{
		g.head[i] = NULL;
	}

	g.verSize = verSize;
}

void uninitGraph(Graph& g)
{
	for (int i = 0; i < g.verSize; ++i)
	{
		destroyNode(g.head[i]);
	}

	delete[] g.head;
}

void _DFS(Graph& g, int ver, int* visited)
{
	visited[ver] = 1; //�湮�� = 1, �湮���� = 0

	cout << ver << " ";

	for (Node* p = g.head[ver]; p != NULL; p = p->link)
	{
		//�湮 ���� �͸� �湮�ϵ���
		if (visited[p->data] == 0)
			_DFS(g, p->data, visited);
	}
}

void DFS(Graph& g, int ver)
{
	int* visited = new int[g.verSize];

	//���� �湮���� �ʾҴٴ� ǥ��
	for (int i = 0; i < g.verSize; ++i)
		visited[i] = 0;

	_DFS(g, ver, visited);

	delete[] visited;
}

#include <queue>
void BFS(Graph& g, int ver)
{
	int* visited = new int[g.verSize];

	//���� �湮���� �ʾҴٴ� ǥ��
	for (int i = 0; i < g.verSize; ++i)
		visited[i] = 0;

	queue<int> q;

	visited[ver] = 1;

	while (true)
	{
		cout << ver << " ";

		for (Node* p = g.head[ver]; p != NULL; p = p->link)
		{
			if (visited[p->data] == 0)
			{
				visited[p->data] = 1;

				q.push(p->data);
			}
		}

		if (q.empty())
			break;

		ver = q.front();
		q.pop();
	}

	delete[] visited;
}

int main()
{
	Graph g; 

	//5���� ������ ���� �׷����� ����
	initGraph(g, 5);

	addEdge(g, 0, 1); // 0 - 1 edge
	addEdge(g, 0, 3); // 0 - 3

	addEdge(g, 1, 0);
	addEdge(g, 1, 2);
	addEdge(g, 1, 3);

	addEdge(g, 2, 1);
	addEdge(g, 2, 3);

	addEdge(g, 3, 0);
	addEdge(g, 3, 1);
	addEdge(g, 3, 2);
	addEdge(g, 3, 4);

	addEdge(g, 4, 3);

	printGraph(g);

	//���� �켱 Ž�� 0�� �������� ����
	//DFS(g, 3);

	//�ʺ� �켱 Ž�� 0�� �������� ����
	BFS(g, 0);

	uninitGraph(g);

	return 0;
}

//struct Node
//{
//	int data;
//	Node* link;
//};
//
//Node* AllocNode(int data)
//{
//	Node* p = new Node;
//	p->data = data;
//	p->link = NULL;
//	return p;
//}
//
//void AddNode(Node*& head, int data)
//{
//	if (head == NULL)
//		head = AllocNode(data);
//	else
//	{
//		Node* thisNode = head;
//
//		while (true)
//		{
//			if (thisNode->link == NULL)
//			{
//				thisNode->link = AllocNode(data);
//				break;
//			}
//			else
//			{
//				thisNode = thisNode->link;
//			}
//		}
//
//		/*
//			Node* tail;
//			for (tail = head; tail->link != NULL; tail = tail->link);
//
//			tail->link = AllocNode(data);
//		*/
//	}
//}
//
//void printNode(Node* head)
//{
//	for (Node* p = head; p != NULL; p = p->link)
//	{
//		cout << p->data << endl;
//	}
//}
//
//void destroyNode(Node* head)
//{
//	for (Node* p = head; p != NULL; )
//	{
//		Node* np = p->link;
//		delete p;
//		p = np;
//	}
//}
//
/////////////////////////////////////
//
//struct Graph
//{
//	Node** head;
//	int verSize; //������ ����
//};
//
//void addEdge(Graph& g, int start, int end)
//{
//	AddNode(g.head[start], end);
//}
//
//void printGraph(Graph& g)
//{
//	for (int i = 0; i < g.verSize; ++i)
//	{
//		cout << "vertex : " << i << " edge : ";
//
//		for (Node* p = g.head[i]; p != NULL; p = p->link)
//		{
//			cout << "( " << i << ", " << p->data << " )";
//		}
//
//		cout << endl;
//	}
//}
//
//void initGraph(Graph& g, int verSize)
//{
//	g.head = new Node * [verSize];
//
//	for (int i = 0; i < verSize; ++i)
//	{
//		g.head[i] = NULL;
//	}
//
//	g.verSize = verSize;
//}
//
//void uninitGraph(Graph& g)
//{
//	for (int i = 0; i < g.verSize; ++i)
//	{
//		destroyNode(g.head[i]);
//	}
//
//	delete[] g.head;
//}
//
//void _DFS(Graph& g, int ver, int* visited)
//{
//	visited[ver] = 1; //�湮�� = 1, �湮���� = 0
//
//	cout << ver << " ";
//
//	for (Node* p = g.head[ver]; p != NULL; p = p->link)
//	{
//		//�湮 ���� �͸� �湮�ϵ���
//		if (visited[p->data] == 0)
//			_DFS(g, p->data, visited);
//	}
//}
//
//void DFS(Graph& g, int ver)
//{
//	int* visited = new int[g.verSize];
//
//	//���� �湮���� �ʾҴٴ� ǥ��
//	for (int i = 0; i < g.verSize; ++i)
//		visited[i] = 0;
//
//	_DFS(g, ver, visited);
//
//	delete[] visited;
//}
//
//int main()
//{
//	Graph g;
//
//	//5���� ������ ���� �׷����� ����
//	initGraph(g, 5);
//
//	addEdge(g, 0, 1); // 0 - 1 edge
//	addEdge(g, 0, 3); // 0 - 3
//
//	addEdge(g, 1, 0);
//	addEdge(g, 1, 2);
//	addEdge(g, 1, 3);
//
//	addEdge(g, 2, 1);
//	addEdge(g, 2, 3);
//
//	addEdge(g, 3, 0);
//	addEdge(g, 3, 1);
//	addEdge(g, 3, 2);
//	addEdge(g, 3, 4);
//
//	addEdge(g, 4, 3);
//
//	printGraph(g);
//
//	//���� �켱 Ž�� 0�� �������� ����
//	DFS(g, 0);
//
//	uninitGraph(g);
//
//	return 0;
//}

//struct Node
//{
//	int data;
//	Node* link;
//};
//
//Node* AllocNode(int data)
//{
//	Node* p = new Node;
//	p->data = data;
//	p->link = NULL;
//	return p;
//}
//
//void AddNode(Node*& head, int data)
//{
//	if (head == NULL)
//		head = AllocNode(data);
//	else
//	{
//		Node* thisNode = head;
//
//		while (true)
//		{
//			if (thisNode->link == NULL)
//			{
//				thisNode->link = AllocNode(data);
//				break;
//			}
//			else
//			{
//				thisNode = thisNode->link;
//			}
//		}
//
//		/*
//			Node* tail;
//			for (tail = head; tail->link != NULL; tail = tail->link);
//
//			tail->link = AllocNode(data);
//		*/
//	}
//}
//
//void printNode(Node* head)
//{
//	for (Node* p = head; p != NULL; p = p->link)
//	{
//		cout << p->data << endl;
//	}
//}
//
//void destroyNode(Node* head)
//{
//	for (Node* p = head; p != NULL; )
//	{
//		Node* np = p->link;
//		delete p;
//		p = np;
//	}
//}
//
/////////////////////////////////////
//
//struct Graph
//{
//	Node** head;
//	int verSize; //������ ����
//};
//
//void addEdge(Graph& g, int start, int end)
//{
//	AddNode(g.head[start], end);
//}
//
//void printGraph(Graph& g)
//{
//	for (int i = 0; i < g.verSize; ++i)
//	{
//		cout << "vertex : " << i << " edge : ";
//
//		for (Node* p = g.head[i]; p != NULL; p = p->link)
//		{
//			cout << "( " << i << ", " << p->data << " )";
//		}
//
//		cout << endl;
//	}
//}
//
//void initGraph(Graph& g, int verSize)
//{
//	g.head = new Node * [verSize];
//
//	for (int i = 0; i < verSize; ++i)
//	{
//		g.head[i] = NULL;
//	}
//
//	g.verSize = verSize;
//}
//
//void uninitGraph(Graph& g)
//{
//	for (int i = 0; i < g.verSize; ++i)
//	{
//		destroyNode(g.head[i]);
//	}
//
//	delete[] g.head;
//}
//
//int main()
//{
//	Graph g;
//
//	//5���� ������ ���� �׷����� ����
//	initGraph(g, 5);
//
//	addEdge(g, 0, 1); // 0 - 1 edge
//	addEdge(g, 0, 3); // 0 - 3
//
//	addEdge(g, 1, 0);
//	addEdge(g, 1, 2);
//	addEdge(g, 1, 3);
//
//	addEdge(g, 2, 1);
//	addEdge(g, 2, 3);
//
//	addEdge(g, 3, 0);
//	addEdge(g, 3, 1);
//	addEdge(g, 3, 2);
//	addEdge(g, 3, 4);
//
//	addEdge(g, 4, 3);
//
//	printGraph(g);
//
//	uninitGraph(g);
//
//	return 0;
//}

//struct Node
//{
//	int data;
//	Node* link;
//};
//
//Node* AllocNode(int data)
//{
//	Node* p = new Node;
//	p->data = data;
//	p->link = NULL;
//	return p;
//}
//
//void AddNode(Node*& head, int data)
//{
//	if (head == NULL)
//		head = AllocNode(data);
//	else
//	{
//		Node* thisNode = head;
//
//		while (true)
//		{
//			if (thisNode->link == NULL)
//			{
//				thisNode->link = AllocNode(data);
//				break;
//			}
//			else
//			{
//				thisNode = thisNode->link;
//			}
//		}
//
//		/*
//			Node* tail;
//			for (tail = head; tail->link != NULL; tail = tail->link);
//
//			tail->link = AllocNode(data);
//		*/
//	}
//}
//
//void printNode(Node* head)
//{
//	for (Node* p = head; p != NULL; p = p->link)
//	{
//		cout << p->data << endl;
//	}
//}
/////////////////////////////////////
//
//struct Graph
//{
//	Node** head;
//};
//
//void addEdge(Graph& g, int start, int end)
//{
//	AddNode(g.head[start], end);
//}
//
//void printGraph(Graph& g)
//{
//	for (int i = 0; i < 5; ++i)
//	{
//		cout << "vertex : " << i << " edge : ";
//
//		for (Node* p = g.head[i]; p != NULL; p = p->link)
//		{
//			cout << "( " << i << ", " << p->data << " )";
//		}
//
//		cout << endl;
//	}
//}
//
//void initGraph(Graph& g, int verSize)
//{
//	g.head = new Node * [verSize];
//
//	for (int i = 0; i < verSize; ++i)
//	{
//		g.head[i] = NULL;
//	}
//}
//
//void uninitGraph(Graph& g)
//{
//	delete[] g.head;
//}
//
//int main()
//{
//	Graph g;
//
//	//5���� ������ ���� �׷����� ����
//	initGraph(g, 5);
//
//	addEdge(g, 0, 1); // 0 - 1 edge
//	addEdge(g, 0, 3); // 0 - 3
//
//	addEdge(g, 1, 0);
//	addEdge(g, 1, 2);
//	addEdge(g, 1, 3);
//
//	addEdge(g, 2, 1);
//	addEdge(g, 2, 3);
//
//	addEdge(g, 3, 0);
//	addEdge(g, 3, 1);
//	addEdge(g, 3, 2);
//	addEdge(g, 3, 4);
//
//	addEdge(g, 4, 3);
//
//	printGraph(g);
//
//	uninitGraph(g);
//
//	return 0;
//}

//using namespace std;
//
//struct Node
//{
//	int data;
//	Node* link;
//};
//
//Node* AllocNode(int data)
//{
//	Node* p = new Node;
//	p->data = data;
//	p->link = NULL;
//	return p;
//}
//
//void AddNode(Node*& head, int data)
//{
//	if (head == NULL)
//		head = AllocNode(data);
//	else
//	{
//		Node* thisNode = head;
//
//		while (true)
//		{
//			if (thisNode->link == NULL)
//			{
//				thisNode->link = AllocNode(data);
//				break;
//			}
//			else
//			{
//				thisNode = thisNode->link;
//			}
//		}
//
//		/*
//			Node* tail;
//			for (tail = head; tail->link != NULL; tail = tail->link);
//
//			tail->link = AllocNode(data);
//		*/
//	}
//}
//
//void printNode(Node* head)
//{
//	for (Node* p = head; p != NULL; p = p->link)
//	{
//		cout << p->data << endl;
//	}
//}
//
//int main()
//{
//	Node* head = NULL;
//	AddNode(head, 10);
//	AddNode(head, 20);
//	AddNode(head, 30);
//	AddNode(head, 40);
//
//	printNode(head);
//
//	return 0;
//}