#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <functional>
#pragma warning(disable:4996), _CRT_SECURE_NO_WARNINGS
#define lli long long int
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int h, w, n;
		scanf("%d%d%d", &h, &w, &n);
		int a, b;
		a = n%h;
		b = n / h + 1;
		if (!a)
		{
			b--;
			a = h;
		}

		printf("%d\n", 100 * a + b);
	}
}