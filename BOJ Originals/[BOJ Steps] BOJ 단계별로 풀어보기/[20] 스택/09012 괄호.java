#include <cstdio>
#pragma warning (disable:4996)
using namespace std;

int stack[100000];

int main()
{
	int n;
	scanf("%d", &n);

	int ptr = 0;
	long long int sum = 0; 
	while (n--)
	{
		int x;
		scanf("%d", &x);
		if (x != 0)
		{
			stack[ptr] = x;
			ptr++;
		}
		else
		{
			ptr--;
		}
	}
	for (int i = 0; i < ptr; i++)
	{
		sum += stack[i];
	}
	printf("%lld", sum);
}