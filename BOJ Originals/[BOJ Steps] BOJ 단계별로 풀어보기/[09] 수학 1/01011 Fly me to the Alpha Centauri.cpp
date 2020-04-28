#include <cstdio>
#include <algorithm>
#include <cmath>
#pragma warning(disable:4996), _CRT_SECURE_NO_WARNINGS
using namespace std;
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int p, q;
		scanf("%d %d", &p, &q);
		int x = q - p;
		int t = floor(sqrt(x));
		if (t*t < x)
		{
			if (t*t + t < x)
				printf("%d\n", 2 * t + 1);
			else
				printf("%d\n", 2 * t);
		}
		else if (t*t == x)
			printf("%d\n", 2 * t - 1);
	}
}