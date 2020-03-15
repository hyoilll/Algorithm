#include <cstdio>
#include <cstdlib>

class Stack
{  
private:
	int* stack;
	int length;
	int top;

public:
	Stack(int length)
	{
		top = 0;
		this->length = length;

		stack = new int[this->length];
	}
	Stack(const Stack& st)
	{
		top = st.top;
		length = st.length;

		stack = new int[length];
		
		for (unsigned int i = 0; i < length; ++i)
			stack[i] = st.stack[i];
	}
	~Stack()
	{
		delete[] stack;
	}

	Stack& operator=(const Stack& st)
	{
		if (stack != nullptr)
			delete[] stack;

		top = st.top;
		length = st.length;

		stack = new int[length];

		for (unsigned int i = 0; i < length; ++i)
			stack[i] = st.stack[i];
		
		return *this;
	}

	void push(int data)
	{
		stack[top] = data;
		top++;
	}
	int pop()
	{
		return stack[--top];
	}

};

int main()
{
	Stack stack(100);
	
	stack.push(1);
	stack.push(2);
	stack.push(3);

	//복사생성자
	Stack s = stack;

	Stack s2(10);
	Stack s3(0);

	//대입연산자
	s3 = s2 = s;

	printf("%d\n", stack.pop());
	printf("%d\n", stack.pop());
	printf("%d\n\n", stack.pop());

	//복사생성자
	printf("%d\n", s.pop());
	printf("%d\n", s.pop());
	printf("%d\n\n", s.pop());

	//대입연산자
	printf("%d\n", s2.pop());
	printf("%d\n", s2.pop());
	printf("%d\n\n", s2.pop());

	printf("%d\n", s3.pop());
	printf("%d\n", s3.pop());
	printf("%d\n", s3.pop());

	return 0;
}

//-------------------------------------------------------------------------------

/*class Stack
{
private:
	int* stack;
	int top;

public:
	Stack(int length)
	{
		top = 0;

		stack = new int[length];
	}
	~Stack()
	{
		delete[] stack;
	}

	void push(int data)
	{
		stack[top] = data;
		top++;
	}
	int pop()
	{
		return stack[--top];
	}

};

int main()
{
	Stack stack(100);

	stack.push(1);
	stack.push(2);
	stack.push(3);

	printf("%d\n", stack.pop());
	printf("%d\n", stack.pop());
	printf("%d\n", stack.pop());

	return 0;
}*/

//----------------------------------------------------------------------------

/*class Stack
{
private:
	int* stack;
	int top;

public:
	void InitStack(int length)
	{
		top = 0;

		stack = new int[length];
	}

	void UninitStack()
	{
		delete[] stack;
	}

	void push(int data)
	{
		stack[top] = data;
		top++;
	}
	int pop()
	{
		return stack[--top];
	}

};

int main()
{
	Stack stack;

	stack.InitStack(100); //초기화

	stack.push(1);
	stack.push(2);
	stack.push(3);

	printf("%d\n", stack.pop());
	printf("%d\n", stack.pop());
	printf("%d\n", stack.pop());

	stack.UninitStack();

	return 0;
}*/

//---------------------------------------------------------------------

/*struct Stack
{
	int* stack;
	int top;
};

void push(Stack& stack, int data)
{
	stack.stack[stack.top] = data;
	stack.top++;
}
int pop(Stack& stack)
{ 
	return stack.stack[--(stack.top)];
}

void InitStack(Stack& stack, int length)
{
	stack.top = 0;

	stack.stack = new int[length];
}

void UninitStack(Stack& stack)
{
	delete[] stack.stack;
}

int main()
{
	Stack stack;

	InitStack(stack, 100); //초기화

	push(stack, 1);
	push(stack, 2);
	push(stack, 3);

	printf("%d\n", pop(stack));
	printf("%d\n", pop(stack));
	printf("%d\n", pop(stack));

	UninitStack(stack);

	return 0;
}*/

//-----------------------------------------------------------------------

/*struct Stack
{
	int* stack;
	int top;
};

void push(Stack& stack, int data)
{
	stack.stack[stack.top] = data;
	stack.top++;
}
int pop(Stack& stack)
{
	return stack.stack[--(stack.top)];
}

void InitStack(Stack& stack)
{
	stack.top = 0;

	stack.stack = new int[5];
}

void UninitStack(Stack& stack)
{
	delete[] stack.stack;
}

int main()
{
	Stack stack;

	InitStack(stack); //초기화

	push(stack, 1);
	push(stack, 2);
	push(stack, 3);

	printf("%d\n", pop(stack));
	printf("%d\n", pop(stack));
	printf("%d\n", pop(stack));

	UninitStack(stack);

	return 0;
}*/

//-------------------------------------------------------------------------------

/*struct Stack
{
	int stack[5];
	int top;
};

void push(Stack& stack, int data)
{
	stack.stack[stack.top] = data;
	stack.top++;
}
int pop(Stack& stack)
{
	return stack.stack[--(stack.top)];
}

void InitStack(Stack& stack)
{
	stack.top = 0;
}

void UninitStack(Stack& stack)
{

}

int main()
{
	Stack stack;
	
	InitStack(stack); //초기화

	push(stack, 1);
	push(stack, 2);
	push(stack, 3);
	
	printf("%d\n", pop(stack));
	printf("%d\n", pop(stack));
	printf("%d\n", pop(stack));

	UninitStack(stack);

	return 0;
}*/

//------------------------------------------------------------------

/*
struct Stack
{
	int stack[5];
	int top = 0;
};

void push(Stack& stack, int data)
{
	stack.stack[stack.top] = data;
	stack.top++;
}
int pop(Stack& stack)
{
	return stack.stack[--(stack.top)];
}

int main()
{
	Stack stack;
	Stack stack2;

	push(stack, 1);
	push(stack, 2);
	push(stack, 3);
	push(stack2, 100);
	push(stack2, 200);
	
	printf("%d\n", pop(stack));
	printf("%d\n", pop(stack));
	printf("%d\n", pop(stack));
	printf("%d\n", pop(stack2));
	printf("%d\n", pop(stack2));
	
	return 0;
}*/

//--------------------------------------------------------------------

/*void push(int* stack, int& top, int data)
{
	stack[top] = data;
	top++;
}
int pop(int* stack, int& top)
{
	return stack[--top];
}

int main()
{
	int stack[5];
	int top = 0; //저장 될 위치를 가르키고 있음

	int stack2[5];
	int top2 = 0; //저장 될 위치를 가르키고 있음

	push(stack, top, 1);
	push(stack, top, 2);
	push(stack, top, 3);
	push(stack2, top2, 100);
	push(stack2, top2, 200);

	printf("%d\n", pop(stack, top));
	printf("%d\n", pop(stack, top));
	printf("%d\n", pop(stack, top));
	printf("%d\n", pop(stack2, top2));
	printf("%d\n", pop(stack2, top2));

	return 0;
}*/

//---------------------------------------------------------------------------------

/*
int stack[5];
int top = 0; //저장 될 위치를 가르키고 있음

void push(int data)
{
	stack[top] = data;
	top++;
}
int pop()
{
	return stack[--top];
}

int main()
{
	push(1);
	push(2);
	push(3);

	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());

	return 0;
}*/

//---------------------------------------------------------------------------------

/*int main()
{
	printf("hello\n");
	system("pause");
	return 0;
}*/