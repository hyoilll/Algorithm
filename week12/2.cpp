#include <iostream>

using namespace std;

struct Fruit
{
	const char* name;
	int price;
	int size;
};

void printFruit(Fruit* f, int cnt)
{
	for (int i = 0; i < cnt; ++i)
	{
		cout << f[i].name << " " << f[i].price << " " << f[i].size << endl;
	}
}

int chooseFruits(Fruit* f, int cnt, int backPackSize)
{
	int max = 0;
	int idx = -1;

	for (int i = 0; i < cnt; ++i)
	{
		if (f[i].size <= backPackSize)
		{
			if (max < f[i].price)
			{
				max = f[i].price;
				idx = i;		
			}
		}
	}

	return idx;
}

int main()
{
	Fruit f[4] = { {"��", 2500, 5}, {"�ٳ���", 1500, 3}, {"���", 1500, 2}, {"����", 2000, 1} };

	int backpackSize = 5;

	int idx = chooseFruits(f, 4, backpackSize);//���濡 ���� �� �ִ� ���� ��� ������ ���õ�

	if (idx >= 0)
		cout << f[idx].name << " " << f[idx].price << " " << f[idx].size << endl;

//	printFruit(f, 4);

	int a[3][2] = { 1,2,3,4,5,6 };
	cout << a[2][1] << endl;

	return 0;
}

//struct Fruit
//{
//	const char* name;
//	int price;
//	int size;
//};
//
//void printFruit(Fruit* f, int cnt)
//{
//	for (int i = 0; i < cnt; ++i)
//	{
//		cout << f[i].name << " " << f[i].price << " " << f[i].size << endl;
//	}
//}
//
//int main()
//{
//	Fruit f[4] = { {"��", 2500, 5}, {"�ٳ���", 1500, 3}, {"���", 1500, 2}, {"����", 2000, 1} };
//
//	printFruit(f, 4);
//
//	return 0;
//}