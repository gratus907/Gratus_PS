#include <bits/stdc++.h>
#pragma warning(disable:4996), _CRT_SECURE_NO_WARNINGS
#define lli long long int
using namespace std;

lli sum;
lli slime[500010];

int main()
{
	int n;
	scanf("%d", &n);
	int state = 0;
	if (n == 1)
	{
		lli x;
		scanf("%lld", &x);
		printf("%lld", x);
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		lli x;
		scanf("%lld", &x);
		slime[i] = x;
		if (x < 0 && (state == 0 || state == 10))
			state += 1;
		if (x >= 0 && state < 10)
			state += 10;
	}
	if (state == 11)
	{
		for (int i = 0; i < n; i++)
			sum += (lli)abs(slime[i]);
	}
	else if (state == 1)
	{
		lli max = -1006000000;
		for (int i = 0; i < n; i++)
		{
			sum += (lli)abs(slime[i]);
			if (slime[i] > max)
				max = slime[i];
		}
		sum += 2 * max;
	}
	else
	{
		lli min = 1006000000;
		for (int i = 0; i < n; i++)
		{
			sum += slime[i];
			if (slime[i] < min)
				min = slime[i];
		}
		sum -= 2 * min;
	}
	printf("%lld", sum);
}
