#include <bits/stdc++.h>
#define lli long long int
#define bignum (int)1e9
using namespace std;

vector<vector<int>> child;
vector<vector<int>> connect;
int parent[100100];
int sons[100100];

void maketree(int current, int par)
{
	parent[current] = par;
	int s = connect[current].size();
	for (int i = 1; i < s; i++)
	{
		if (par == connect[current][i])
		{
		}
		else
		{
			child[current].push_back(connect[current][i]);
			maketree(connect[current][i], current);
		}
	}
}

int main()
{
	connect.assign(100010, vector<int>(1, 0));
	child.assign(100010, vector<int>(1, 0));
	int n;
	scanf("%d", &n);
	int pt = 0;
	for (int i= 1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		connect[a].push_back(b);
		connect[b].push_back(a);
	}
	maketree(1, -1);
	for (int i = 2; i<= n; i++)
		printf("%d\n", parent[i]);
}