#include <cstdio>
using namespace std;
#pragma warning(disable:4996), _CRT_SECURE_NO_WARNINGS
int main()
{
	while (1) 
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if (a == 0 && b == 0)
		{
			break;
		}
		else 
		{
			printf("%d\n", a + b);
		}
	}
}