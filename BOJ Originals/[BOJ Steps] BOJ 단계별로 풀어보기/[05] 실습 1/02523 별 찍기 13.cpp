#include <cstdio>
#include <cstring>
#pragma warning(disable:4996), _CRT_SECURE_NO_WARNINGS
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (int k = n - 1; k > 0; k--)
	{
		for (int j = 0; j < k; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}