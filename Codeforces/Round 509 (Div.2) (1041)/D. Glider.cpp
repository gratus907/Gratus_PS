#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <functional>
#include <bitset>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#pragma warning(disable:4996), _CRT_SECURE_NO_WARNINGS
#define lli long long int
using namespace std;


int startp[200100];
int endp[200100];
int ind;
int n;
int toind;
int len[200100];
int gap[200100];
int maxd;
int cur[200100][3]; // 거리0, 마지막으로 밟은 점1

void run(int h, int i) // start at startp[i]
{
	int th = h;
	cur[i][1] = cur[i - 1][1];
	while (h > gap[cur[i][1]] - gap[i])
	{
		cur[i][1]++;
		if (cur[i][1] == n)
			break;
	}
	cur[i][1]--;
	if (i == 0)
		cur[i][0] = len[cur[i][1]] + h;
	else
		cur[i][0] = len[cur[i][1]] + h - len[i - 1];
	if (cur[i][0] > maxd)
	{
		maxd = cur[i][0];
		ind = i;
		toind = cur[i][1];
	}
}

int main()
{
	int h;
	scanf("%d %d", &n, &h);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		startp[i] = a;
		endp[i] = b;
		len[i] = b - a;
		if (i > 0)
		{
			gap[i] = gap[i - 1] + a - endp[i - 1];
			len[i] = len[i - 1] + b - a;
		}
	}
	for (int i = 0; i < n; i++)
		run(h, i);
//	printf("start from %d\nstep on %d\nmaxdist %d", ind, toind, maxd);
	printf("%d", maxd);
}
