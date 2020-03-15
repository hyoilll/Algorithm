/*
	1 ~ 10 까지의 합
*/
#include <iostream>

 /*
int main()
{
	int sum = 0;

	for (unsigned int i = 1; i < 11; ++i)
		sum += i;

	std::cout << sum << std::endl;

	return 0;
}*/

//------------------------------------------------------------------------------

/*
int Sum()
{
	int sum = 0;

	for (unsigned int i = 1; i < 11; ++i)
		sum += i;

	return sum;
}

int main()
{
	int sum = 0;

	sum = Sum();

	std::cout << sum << std::endl;

	return 0;
}*/

//-------------------------------------------------------------------------

int Sum(const int& from, const int& to)
{
	int sum = 0;

	for (unsigned int i = from; i <= to; ++i)
		sum += i;

	return sum;
}

int main()
{
	int sum = 0;

	sum = Sum(1, 10);

	std::cout << sum << std::endl;

	return 0;
}