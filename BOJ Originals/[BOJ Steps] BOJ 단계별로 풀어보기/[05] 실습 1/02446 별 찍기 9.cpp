#include <cstdio>
#pragma warning(disable:4996), _CRT_SECURE_NO_WARNINGS
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	for (int p = n; p > 0; p--)
	{
		for (int k = 0; k < n - p; k++)
			printf(" ");
		for (int j = 1; j < 2 * p; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (int i = 2; i <= n; i++)
	{
		for (int k = 0; k < n-i; k++)
			printf(" ");
		for (int j = 1; j < 2 * i; j++)
		{
				printf("*");
		}
		printf("\n");
	}
	
}