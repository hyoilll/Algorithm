#include <iostream>

using namespace std;

void printTable(int** arr, int row, int col)
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int ss(const char* str1, const char* str2)
{//7x5
	int row = strlen(str1) + 1;
	int col = strlen(str2) + 1;

	int** table = new int* [row];
	
	for (int i = 0; i < row; ++i)
		table[i] = new int[col];
	///////////////////////////////

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			table[i][j] = 0;
		}
	}

	for (int i = 1; i < row; ++i)
	{
		for (int j = 1; j < col; ++j)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				table[i][j] = table[i - 1][j - 1] + 1;
			}
			else
			{
				table[i][j] = max(table[i - 1][j], table[i][j - 1]);
			}
		}
	}
	
	printTable(table, row, col);

	int result = table[row - 1][col - 1];

	///////////////////////////////
	for (int i = 0; i < row; ++i)
		delete[] table[i];

	delete[] table;

	return result;
}

int main()
{
	cout << "subSequence : " << ss("FINISH", "FISH") << endl;

	cout << "subSequence : " << ss("ABCDEF", "AFCDE") << endl;

	cout << "subSequence : " << ss("ABCDEF", "FGDC") << endl;
	return 0;
}