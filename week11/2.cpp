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
				table[i][j] = 0;
			}
		}
	}

	printTable(table, row, col);

	int result = 0;

	for (int i = 1; i < row ; ++i)
	{
		for (int j = 1; j < col; ++j)
		{
			if (result < table[i][j])
			{
				result = table[i][j];
			}
		}
	}

	///////////////////////////////
	for (int i = 0; i < row; ++i)
		delete[] table[i];

	delete[] table;

	return result;
}

int main()
{
	cout << "substring : " << ss("FINISH", "FINK") << endl;
	cout << "substring : " << ss("ABCDEF", "KBCDE") << endl;
	cout << "substring : " << ss("ABCDEF", "AKCKE") << endl;
	return 0;
}