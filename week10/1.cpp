#include <iostream>
#include <queue>

using namespace std;

struct Edge
{
	int ver; //도착 정점
	int cost; //비용

	Edge(int v, int c) :ver(v), cost(c) {}

	//비교순위를 위한 operator 함수
	bool operator<(const Edge& arg) const
	{
		return cost > arg.cost;
	}
};

struct Node
{
	int ver; //인접 정점
	int cost; //가중치
	Node* link;
};

Node* AllocNode(int ver, int cost)
{
	Node* p = new Node;

	p->ver = ver;
	p->cost = cost;
	p->link = NULL;

	return p;
}

void AddNode(Node*& head, int ver, int cost)
{
	if (head == NULL)
		head = AllocNode(ver, cost);
	else
	{
		Node* thisNode = head;

		while (true)
		{
			if (thisNode->link == NULL)
			{
				thisNode->link = AllocNode(ver, cost);
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
	int verSize; //정점의 개수
};

void addEdge(Graph& g, int start, int end, int cost)
{
	AddNode(g.head[start], end, cost);
}

void printGraph(Graph& g)
{
	for (int i = 0; i < g.verSize; ++i)
	{
		cout << "vertex : " << i << " edge : ";

		for (Node* p = g.head[i]; p != NULL; p = p->link)
		{
			cout << "( " << i << ", " << p->ver << " ) -> ";
			cout << p->cost << " ";
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

void dijkstra(Graph& g, int ver) //start vertex
{
	int* distance = new int[g.verSize]; //가중치 정점 배열

	int* startingPoint = new int[g.verSize]; //경로

	const int infinite = 1'000'000;

	for (int i = 0; i < g.verSize; ++i)
	{
		distance[i] = infinite;
	}

	distance[ver] = 0; //start vertex
	startingPoint[ver] = 0;

	priority_queue<Edge> q; //우선순위 큐

	for (Node* n = g.head[ver]; n != NULL; n = n->link)
	{
		distance[n->ver] = n->cost;

		startingPoint[n->ver] = ver;

		q.push(Edge(n->ver, n->cost));
	}

	while (!q.empty())
	{
		Edge min = q.top();
		q.pop();

		for (Node* n = g.head[min.ver]; n != NULL; n = n->link)
		{
			if (distance[min.ver] + n->cost < distance[n->ver])
			{
				distance[n->ver] = distance[min.ver] + n->cost;

				startingPoint[n->ver] = min.ver;

				q.push(Edge(n->ver, distance[n->ver]));
			}
		}
	}

	for (int i = 0; i < g.verSize; ++i)
	{
		cout << startingPoint[i] << " -> " << i << " : " << distance[i] << endl;
	}

	delete[] distance;
	delete[] startingPoint;
}

int main()
{
	Graph g;

	//9개의 정점을 갖는 그래프를 생성
	initGraph(g, 9);

	addEdge(g, 0, 1, 8); // 0 - 1 edge / 가중치 8
	addEdge(g, 0, 2, 15); // 0 - 3
	addEdge(g, 0, 3, 20);

	addEdge(g, 1, 4, 5);

	addEdge(g, 2, 3, 3);
	addEdge(g, 2, 5, 20);
	addEdge(g, 2, 6, 15);
	addEdge(g, 2, 8, 37);

	addEdge(g, 3, 8, 30);

	addEdge(g, 4, 5, 14);
	addEdge(g, 4, 7, 10);

	addEdge(g, 5, 8, 20);

	printGraph(g);

	dijkstra(g, 0);

	uninitGraph(g);

	return 0;
}

//struct Edge
//{
//	int ver; //도착 정점
//	int cost; //비용
//
//	Edge(int v, int c) :ver(v), cost(c) {}
//
//	//비교순위를 위한 operator 함수
//	bool operator<(const Edge& arg) const
//	{
//		return cost > arg.cost;
//	}
//};
//
//struct Node
//{
//	int ver; //인접 정점
//	int cost; //가중치
//	Node* link;
//};
//
//Node* AllocNode(int ver, int cost)
//{
//	Node* p = new Node;
//
//	p->ver = ver;
//	p->cost = cost;
//	p->link = NULL;
//
//	return p;
//}
//
//void AddNode(Node*& head, int ver, int cost)
//{
//	if (head == NULL)
//		head = AllocNode(ver, cost);
//	else
//	{
//		Node* thisNode = head;
//
//		while (true)
//		{
//			if (thisNode->link == NULL)
//			{
//				thisNode->link = AllocNode(ver, cost);
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
//	int verSize; //정점의 개수
//};
//
//void addEdge(Graph& g, int start, int end, int cost)
//{
//	AddNode(g.head[start], end, cost);
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
//			cout << "( " << i << ", " << p->ver << " ) -> ";
//			cout << p->cost << " ";
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
//void dijkstra(Graph& g, int ver) //start vertex
//{
//	int* distance = new int[g.verSize]; //가중치 정점 배열
//	
//	const int infinite = 1000000;
//
//	for (int i = 0; i < g.verSize; ++i)
//	{
//		distance[i] = infinite;
//	}
//
//	distance[ver] = 0; //start vertex
//
//	priority_queue<Edge> q; //우선순위 큐
//
//	for (Node* n = g.head[ver]; n != NULL; n = n->link)
//	{
//		distance[n->ver] = n->cost;
//
//		q.push(Edge(n->ver, n->cost));
//	}
//
//	while (!q.empty())
//	{
//		Edge min = q.top();
//		q.pop();
//
//		for (Node* n = g.head[min.ver]; n != NULL; n = n->link)
//		{
//			if (distance[min.ver] + n->cost < distance[n->ver])
//			{
//				distance[n->ver] = distance[min.ver] + n->cost;
//
//				q.push(Edge(n->ver, distance[n->ver]));
//			}
//		}
//	}
//
//	for (int i = 0; i < g.verSize; ++i)
//	{
//		cout << distance[i] << " ";
//	}
//
//	delete[] distance;
//}
//
//int main()
//{
//	Graph g;
//
//	//9개의 정점을 갖는 그래프를 생성
//	initGraph(g, 9);
//
//	addEdge(g, 0, 1, 8); // 0 - 1 edge / 가중치 8
//	addEdge(g, 0, 2, 15); // 0 - 3
//	addEdge(g, 0, 3, 20);
//
//	addEdge(g, 1, 4, 5);
//
//	addEdge(g, 2, 3, 3);
//	addEdge(g, 2, 5, 20);
//	addEdge(g, 2, 6, 15);
//	addEdge(g, 2, 8, 37);
//
//	addEdge(g, 3, 8, 30);
//
//	addEdge(g, 4, 5, 14);
//	addEdge(g, 4, 7, 10);
//
//	addEdge(g, 5, 8, 20);
//
//	printGraph(g);
//
//	dijkstra(g, 0);
//
//	uninitGraph(g);
//
//	return 0;
//}

//struct Edge
//{
//	int ver; //도착 정점
//	int cost; //비용
//
//	Edge(int v, int c) :ver(v), cost(c) {}
//
//	//비교순위를 위한 operator 함수
//	bool operator<(const Edge& arg) const
//	{
//		return cost > arg.cost;
//	}
//};
//
//int main()
//{
//	priority_queue<Edge> q;
//
//	q.push(Edge(1, 20));
//	q.push(Edge(2, 15));
//	q.push(Edge(3, 8));
//	
//	cout << q.top().cost << endl;
//	q.pop();
//
//	cout << q.top().cost << endl;
//	q.pop();
//	cout << q.top().cost << endl;
//	q.pop();
//
//	return 0;
//}

//int main()
//{
//	priority_queue<int> q;
//
//	q.push(50);
//	q.push(40);
//	q.push(10);
//	q.push(80);
//	q.push(30);
//
//	cout << q.top() << endl;
//	q.pop();
//
//	cout << q.top() << endl;
//	q.pop();
//	cout << q.top() << endl;
//	q.pop();
//	cout << q.top() << endl;
//	q.pop();
//	cout << q.top() << endl;
//	q.pop();
//
//	return 0;
//}

//struct Node
//{
//	int ver; //인접 정점
//	int cost; //가중치
//	Node* link;
//};
//
//Node* AllocNode(int ver, int cost)
//{
//	Node* p = new Node;
//
//	p->ver = ver;
//	p->cost = cost;
//	p->link = NULL;
//
//	return p;
//}
//
//void AddNode(Node*& head, int ver, int cost)
//{
//	if (head == NULL)
//		head = AllocNode(ver, cost);
//	else
//	{
//		Node* thisNode = head;
//
//		while (true)
//		{
//			if (thisNode->link == NULL)
//			{
//				thisNode->link = AllocNode(ver, cost);
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
//	int verSize; //정점의 개수
//};
//
//void addEdge(Graph& g, int start, int end, int cost)
//{
//	AddNode(g.head[start], end, cost);
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
//			cout << "( " << i << ", " << p->ver << " ) -> ";
//			cout << p->cost << " ";
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
//	//9개의 정점을 갖는 그래프를 생성
//	initGraph(g, 9);
//
//	addEdge(g, 0, 1, 8); // 0 - 1 edge / 가중치 8
//	addEdge(g, 0, 2, 15); // 0 - 3
//	addEdge(g, 0, 3, 20);
//
//	addEdge(g, 1, 4, 5);
//
//	addEdge(g, 2, 3, 3);
//	addEdge(g, 2, 5, 20);
//	addEdge(g, 2, 6, 15);
//	addEdge(g, 2, 8, 37);
//
//	addEdge(g, 3, 8, 30);
//
//	addEdge(g, 4, 5, 14);
//	addEdge(g, 4, 7, 10);
//
//	addEdge(g, 5, 8, 20);
//
//	printGraph(g);
//
//	uninitGraph(g);
//
//	return 0;
//}

//struct Node
//{
//	int ver; //인접 정점
//	int cost; //가중치
//	Node* link;
//};
//
//Node* AllocNode(int ver, int cost)
//{
//	Node* p = new Node;
//	
//	p->ver = ver;
//	p->cost = cost;
//	p->link = NULL;
//
//	return p;
//}
//
//void AddNode(Node*& head, int ver, int cost)
//{
//	if (head == NULL)
//		head = AllocNode(ver, cost);
//	else
//	{
//		Node* thisNode = head;
//
//		while (true)
//		{
//			if (thisNode->link == NULL)
//			{
//				thisNode->link = AllocNode(ver, cost);
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
//	int verSize; //정점의 개수
//};
//
//void addEdge(Graph& g, int start, int end, int cost)
//{
//	AddNode(g.head[start], end, cost);
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
//			cout << "( " << i << ", " << p->ver << " ) -> ";
//			cout << p->cost << " ";
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
//	//9개의 정점을 갖는 그래프를 생성
//	initGraph(g, 9);
//
//	addEdge(g, 0, 1, 8); // 0 - 1 edge / 가중치 8
//	addEdge(g, 0, 2, 15); // 0 - 3
//	addEdge(g, 0, 3, 20);
//
//	addEdge(g, 1, 4, 5);
//
//	addEdge(g, 2, 3, 3);
//	addEdge(g, 2, 5, 20);
//	addEdge(g, 2, 6, 15);
//	addEdge(g, 2, 8, 37);
//
//	addEdge(g, 3, 8, 30);
//
//	addEdge(g, 4, 5, 14);
//	addEdge(g, 4, 7, 10);
//
//	addEdge(g, 5, 8, 20);
//
//	printGraph(g);
//
//	uninitGraph(g);
//
//	return 0;
//}