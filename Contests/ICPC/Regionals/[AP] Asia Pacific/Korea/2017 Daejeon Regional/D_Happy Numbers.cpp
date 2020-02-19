#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <functional>
#include <vector>
#pragma warning(disable:4996), _CRT_SECURE_NO_WARNINGS
#define lli long long int
using namespace std;
#define MAX 1000000000;

int happy[800];

int check_happy(int n)
{
	int x = 0;
	int t = n;
	while (t >= 10)
	{
		x += (t % 10)*(t % 10);
		t = t/10;
	}
	x += (t) * (t);
	return x;
}

int main()
{
	int n;
	for (int i = 1; i <= 729; i++)
	{
		int u = i;
		for (int k = 0; k<3000; k++)
		{
			if (u == 1)
			{
				happy[i] = 1;
				break;
			}
			else if (u == 4)
			{
				happy[i] = 0;
				break;
			}
			else
				u = check_happy(u);
		}
	}
	scanf("%d", &n);
	n = check_happy(n);
	if (happy[n] == 1)
		printf("HAPPY");
	else
		printf("UNHAPPY");
}