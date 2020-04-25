#include <cstdio>
#pragma warning(disable:4996), _CRT_SECURE_NO_WARNINGS
using namespace std;

int checker(int n)
{
	if ((n % 10 - (n / 10) % 10 == (n / 10) % 10 - (n - n % 100) / 100))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	if (n < 100)
	{
		printf("%d", n);
;	}
	if (n >= 100)
	{
		int c=99;
		for (int i = 100; i <= n; i++)
		{
			c += checker(i);
		}
		printf("%d", c);
	}
}
