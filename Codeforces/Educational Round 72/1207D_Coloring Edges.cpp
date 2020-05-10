#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 987654321
using namespace std;
using pii = pair<int, int>;

vector <int> toposort;
int node_ind[5050];
bool visit[5050];
vector <int> graph[5050];
void topo(int r)
{
	visit[r] = true;
	for (auto it:graph[r])
	{
		if (!visit[it])
			topo(it);
	}
	toposort.push_back(r);
}
vector <pii> edges;
vector <int> res;
int main()
{
	usecppio
	int n, m;
	cin >> n >> m;
	for (int i = 0; i<m; i++)
	{
		int u, v;
		cin >> u >> v;
		edges.push_back({u,v});
		graph[u].push_back(v);
	}
	for (int i = 1; i<=n; i++)
	{
		if (!visit[i])
			topo(i);
	}
	reverse(all(toposort));
	for (int i = 0; i<n; i++)
	{
		node_ind[toposort[i]] = i+1;
	}
	bool two = 0;
	for (auto it:edges)
	{
		if (node_ind[it.first] < node_ind[it.second])
			res.push_back(1);
		else
		{
			res.push_back(2);
			two = true;
		}
	}
	cout << (two + 1) << '\n';
	for (auto it:res)
	{
		cout << it  << ' ';
	}
}
