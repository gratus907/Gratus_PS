#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <functional>
#pragma warning(disable:4996), _CRT_SECURE_NO_WARNINGS
#define lli long long int
using namespace std;

priority_queue<int> pq;

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		if (x == 0)
		{
			if (pq.size() == 0)
				printf("0\n");
			else
			{
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
		else
			pq.push(x);
	}
}