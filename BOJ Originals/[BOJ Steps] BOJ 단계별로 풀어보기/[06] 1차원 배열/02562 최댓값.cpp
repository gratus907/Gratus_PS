#include <cstdio>
#pragma warning(disable:4996), _CRT_SECURE_NO_WARNINGS
using namespace std;

int main()
{
	int num[10];
	int max;
	int a;
	int p=1;
	scanf("%d", &a);
	num[1] = a;
	max = a;
	for (int i = 2; i < 10; i++)
	{
		int a;
		scanf("%d", &a);
		num[i] = a;
		if (a > max)
		{
			max = a;
			p = i;
		}
	}
	printf("%d\n%d", max, p);
}