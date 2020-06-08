#include <iostream>

using namespace std;

void refund(int* moneyType, const int& change, int* CntMoneyType)
{
	int ch = change; //�Ž�����

	for (int i = 0; i < 5; ++i)
	{
		int cnt = 0;

		while (ch / moneyType[i] != 0)
		{
			cnt++;

			ch = ch - moneyType[i]; //660 - 500
		}

		CntMoneyType[i] = cnt;
	}
}

int main()
{
	int moneyType[5] = { 500, 100, 50, 10, 1 };
	int cntMoneyType[5] = { 0, };
	int change = 1200; // 1000 - 330

	refund(moneyType, change, cntMoneyType);

	cout << "������ ���� ��뷮" << endl;
	for (int i = 0; i < 5; ++i)
	{
		cout << moneyType[i] << "�� -> " << cntMoneyType[i] << "��" << endl;
	}

	return 0;
}

//void refund(int* moneyType, const int& change, int* CntMoneyType)
//{
//	int ch = change; //�Ž�����
//
//	for (int i = 0; i < 5; ++i)
//	{
//		int cnt = 0;
//
//		while (ch / moneyType[i] != 0)
//		{
//			cnt++;
//
//			cout << moneyType[i] << "�� : " << cnt << "��" << endl;
//
//			ch = ch - moneyType[i]; //660 - 500
//
//			cout << "���� " << ch << endl;
//		}
//
//		CntMoneyType[i] = cnt;
//
//		cout << endl;
//	}
//}
//
//int main()
//{
//	int moneyType[5] = { 500, 100, 50, 10, 1 };
//	int cntMoneyType[5] = { 0, };
//	int change = 670; // 1000 - 330
//
//	refund(moneyType, change, cntMoneyType);
//
//	cout << "������ ���� ��뷮" << endl;
//	for (int i = 0; i < 5; ++i)
//	{
//		cout << moneyType[i] << "�� -> " << cntMoneyType[i] << "��" << endl;
//	}
//
//	return 0;
//}

//void refund(int* moneyType, const int& change)
//{
//	int ch = change; //�Ž�����
//
//	
//
//	for (int i = 0; i < 5; ++i)
//	{
//		int cnt = 0;
//
//		while (ch / moneyType[i] != 0)
//		{
//			cnt++;
//
//			cout << moneyType[i] << "�� : " << cnt << "��" << endl;
//			 
//			ch = ch - moneyType[i]; //660 - 500
//
//			cout << "���� " << ch << endl;
//		}
//
//		cout << endl;
//	}
//}
//
//int main()
//{
//	int moneyType[5] = { 500, 100, 50, 10, 1 };
//	int change = 670; // 1000 - 330
//
//	refund(moneyType, change);
//
//	return 0;
//}