#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimine("O3")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int, int> pii;
int n, m;
int neighbor[101010];
vector <pii> edges;
vector <int> graph[101010];
int incount[101010];
int ans[101010];
bool visit[101010];
queue <int> q;
int main()
{
	usecppio
	cin >> n >> m;
	for (int i = 0; i<m; i++)
	{
		int u, v;
		cin >> u >> v;
		neighbor[u]++;
		neighbor[v]++;
		edges.push_back({u,v});
	}
	for (auto it:edges)
	{
		int u, v;
		if (neighbor[it.first] > neighbor[it.second])
		{
			u = it.first;
			v = it.second;
		}
		else if (neighbor[it.first] < neighbor[it.second])
		{
			v = it.first;
			u = it.second;
		}
		else
			continue;
		graph[u].push_back(v);
		incount[v]++;
	}
	for (int i = 0; i<n; i++)
	{
		if (incount[i] == 0)
		{
			q.push(i);
			visit[i] = 1;
		}
	}
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		for (auto it:graph[x])
		{
			ans[it] = max(ans[it], ans[x] + 1);
			incount[it]--;
			if (incount[it] == 0 && !visit[it])
			{
				q.push(it);
				visit[it] = 1;
			}
		}
	}
	int res = 0;
	for (int i = 0; i<n; i++)
	{
		res = max(res, ans[i]);
	}
	cout << res+1 << '\n';
}
