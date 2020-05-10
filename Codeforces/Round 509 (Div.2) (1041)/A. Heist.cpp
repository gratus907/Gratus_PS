#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <functional>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#pragma warning(disable:4996), _CRT_SECURE_NO_WARNINGS
#define lli long long int
using namespace std;

int maxq, minq;

int main()
{
	int n;
	scanf("%d", &n);
	minq = (int)1e9;
	for (int i = 0; i < n; i++)
	{
		int u;
		scanf("%d", &u);
		if (maxq < u)
			maxq = u;
		if (minq > u)
			minq = u;
	}
	printf("%d", maxq - minq + 1 - n);
}