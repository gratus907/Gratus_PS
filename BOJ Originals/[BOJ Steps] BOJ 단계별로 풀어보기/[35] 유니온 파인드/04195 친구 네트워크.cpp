#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 700000000
using namespace std;
using pii = pair<int, int>;
// Original Author : Ashishgup
#define V 101010
map <string, int> m;
struct Disjoint_Set_Union
{
	int connected;
	int parent[V], size[V];
	Disjoint_Set_Union()
	{
		init(V);
	}
	void init(int n)
	{
		for(int i=1;i<=n;i++)
		{
			parent[i]=i;
			size[i]=1;
		}
		connected=n;
	}
	int Find(int k)
	{
		while(k!=parent[k])
		{
			parent[k]=parent[parent[k]];
			k=parent[k];
		}
		return k;
	}
	int getSize(int k)
	{
		return size[Find(k)];
	}
	void unite(int x, int y)
	{
		int u=Find(x), v=Find(y);
		if(u==v)
			return;
		if(size[u]>size[v])
			swap(u, v);
		size[v]+=size[u];
		size[u] = 0;
		parent[u] = parent[v];
	}
};
Disjoint_Set_Union dsu;
int main()
{
	usecppio
	int Tc;
	cin >> Tc;
	while(Tc--)
	{
		m.clear();
		dsu = Disjoint_Set_Union();
		int n;
		cin >> n;
		int x = 1;
		for (int i = 0; i<n; i++)
		{
			string a, b;
			cin >> a >> b;
			if (m[a]==0)
				m[a] = x, x++;
			if (m[b]==0)
				m[b] = x, x++;
			int ma = m[a], mb = m[b];
			dsu.unite(ma,mb);
			cout << dsu.getSize(ma) << '\n';
		}
	}
}
