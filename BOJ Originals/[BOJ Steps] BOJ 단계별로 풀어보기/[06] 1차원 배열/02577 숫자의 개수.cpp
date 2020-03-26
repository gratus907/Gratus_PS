#include <cstdio>
#include <string>
#pragma warning(disable:4996), _CRT_SECURE_NO_WARNINGS
using namespace std;


int main() 
{
	int a, b, c;
	int mul;
	char arr[1000];
	char count[10] = { 0, };
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);

	mul = a * b * c;
	sprintf(arr, "%d", mul);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (arr[i] == 48 + j)
			{
				count[j]++;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", count[i]);
	}
	return 0;
}