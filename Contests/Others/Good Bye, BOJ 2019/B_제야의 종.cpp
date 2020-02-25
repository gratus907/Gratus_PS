#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
using pii = pair <int, int>;

int able[1010][103];
int n, m;
int graph[1010][1010];
bool visited[1010];
vector <int> sorted;

void dfs(int root)
{
	visited[root] = 1;
	for (int i = 0; i<n; i++)
		if (!visited[i] && graph[root][i])
			dfs(i);
	sorted.push_back(root);
}

int32_t main()
{
	cin >> n >> m;
	for (int i = 0; i<n; i++)
		for (int j = 0; j<m; j++)
			cin >> able[i][j];
	for (int i = 0; i<m; i++)
	{
		for (int j = 0; j<n; j++)
		{
			for (int k = 0; k<n; k++)
			{
				if (able[j][i] && !able[k][i])
					graph[j][k] = true;
				else if (!able[j][i] && able[k][i])
					graph[k][j] = true;
			}
		}
	}
//	for (int j = 0; j<n; j++)
//	{
//		for (int k = 0; k<n; k++)
//		{
//			printf("%d ",graph[j][k]);
//		}
//		printf("\n");
//	}
	for (int i = 0; i<n; i++)
		if (!visited[i])
			dfs(i);
	reverse(sorted.begin(),sorted.end());
//	for (auto it:sorted)
//	{
//		printf("%d ",it);
//	}
//	printf("\n");
	for (int i = 0; i<n; i++)
	{
		for (int j = i+1; j<n; j++)
		{
			if (graph[sorted[j]][sorted[i]])
			{
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << "YES\n";
}
