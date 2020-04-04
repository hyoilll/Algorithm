#include <iostream>
using namespace std;

void fibo(int n, int& result)
{
	if (n == 1)
		result = 1;
	else if (n == 2)
		result = 1;
	else
	{
		int result2 = 0;
		fibo(n - 1, result);
		fibo(n - 2, result2);

		result = result + result2;
	}
}

int main()
{
	int result = 0;
	fibo(5, result);
	cout << result << endl;

	return 0;
}

//---------------------------------------------------------

/*
int fibo(int n)
{
	if (n == 1)
		return 1;
	else if (n == 2)
		return 1;
	else
		return fibo(n - 1) + fibo(n - 2);

}

int main()
{
	cout << fibo(6) << endl;
	return 0;
}
*/

//-----------------------------------------------------------------

/*
void fac(int n, int& result)
{
	if (n > 1)
		fac(n - 1, result);

	if (n == 0)			//Á¾·á
		result = 0;
	else if (n == 1)	//¼ö·Å
		result = 1;
	else
		result =  n * result;
}

int main()
{
	int result = 0;
	fac(1, result);
	cout << result << endl;
}
*/

//----------------------------------------------------------

/*
int fac(int n)
{
	if (n == 0)			//Á¾·á
		return 0;
	else if (n == 1)	//¼ö·Å
		return 1;
	else
		return n * fac(n - 1);
}

int main()
{
	cout << fac(4) << endl;
}
*/

/*void print(int n)
{
	cout << "+" << n << endl;
	if (n > 0)			//Á¾·á Á¶°Ç
	{
		print(n - 1);	//¼ö·Å
		print(n - 1);
	}
	cout << "-" << n << endl;
}

int main()
{
	print(3);
	return 0;
}
*/

//-----------------------------------------------------------

/*
void print(int n)
{
	cout << n << endl;
	if (n > 0)			//Á¾·á Á¶°Ç
		print(n - 1);	//¼ö·Å
}

int main()
{
	print(3);
	return 0;
}
*/

//-------------------------------------------------------

/*
void print(int n)
{
	cout << n << endl;
	if (n > 0)			//Á¾·á Á¶°Ç
		print(n - 1);	//¼ö·Å
}

int main()
{
	print(3);
	return 0;
}
*/

//----------------------------------------------------------------

/*
void print(int n)
{
	cout << n << endl;
	print(n);
}

int main()
{
	print(3);
	return 0;
}
*/

//--------------------------------------------------------------

/*
void print(int n)
{
	cout << n << endl;
}

int main()
{
	print(3);
	return 0;
}
*/