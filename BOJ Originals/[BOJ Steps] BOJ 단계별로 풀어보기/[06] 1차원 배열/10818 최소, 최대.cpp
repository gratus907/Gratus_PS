#include <cstdio>
#include <string>
#pragma warning(disable:4996), _CRT_SECURE_NO_WARNINGS
using namespace std;


int main()
{
	int N;
	int a;
	int min, max;
	scanf("%d", &N);
	scanf("%d", &a);
	min = a;
	max = a;
	for (int i = 0; i < N - 1; i++)
	{
		scanf("%d", &a);
		if (max < a)
		{
			max = a;
		}
		if (min > a)
		{
			min = a;
		}
	}
	printf("%d %d", min, max);
}