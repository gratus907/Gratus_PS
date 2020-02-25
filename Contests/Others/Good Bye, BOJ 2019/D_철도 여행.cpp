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
#define int ll
const int mod = 1000000007;
vector <int> graph[201010];
int cc[202020];
int deg[202020];
int octs[202020];
int n, m;
bool vst[202020];
void dfs(int r, int ccp)
{
	vst[r] = true;
	cc[r] = ccp;
	for (auto it:graph[r])
	{
		if (!vst[it])
			dfs(it, ccp);
	}
}
int32_t main()
{
	usecppio
	cin >> n >> m;
	for (int i = 0; i<m; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
	int ct = 0;
	for (int i = 1; i<=n; i++)
	{
		if(!vst[i] && (deg[i]>0))
		{
			ct++;
			dfs(i, ct);
		}
	}
	for (int i = 1; i<=n; i++)
	{
		if (deg[i]%2)
			octs[cc[i]] ++;
	}
	int ans = 0;
	for (int i = 1; i<=ct; i++)
	{
		ans += (octs[i]==0?1:octs[i]/2);
	}
	cout << ans << '\n';
}