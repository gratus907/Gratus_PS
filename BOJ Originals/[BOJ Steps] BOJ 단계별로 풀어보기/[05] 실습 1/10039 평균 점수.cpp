#include <cstdio>
#pragma warning(disable:4996), _CRT_SECURE_NO_WARNINGS
using namespace std;


int main()
{
	int n;
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &n);
		if (n < 40)
		{
			sum += 40;
		}
		else
		{
			sum += n;
		}
	}
	printf("%d", sum / 5);
}