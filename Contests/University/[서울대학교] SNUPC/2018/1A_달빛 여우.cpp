#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;
#define int ll
const int INF = 987654321987654321;
struct Edge
{
	int dest, w;
	Edge(pii a)
	{
		dest = a.first;
		w = a.second;
	}
	Edge()
	{
		Edge({0,0});
	}
	bool operator<(const Edge &p) const
	{
		return w > p.w;
	}
};

int n, m;
vector <Edge> fox[4040];
vector <Edge> wolf[8080];
int foxdistance[4040];
int tmpwolf[8080];

inline void foxedge(int a, int b, int c)
{
	fox[a].push_back(Edge({b,c}));
	fox[b].push_back(Edge({a,c}));
}

inline void wolfedge(int a, int b, int c)
{
	wolf[a*2].push_back(Edge({b*2+1,c/2}));
	wolf[a*2+1].push_back(Edge({b*2,c*2}));
	wolf[b*2].push_back(Edge({a*2+1,c/2}));
	wolf[b*2+1].push_back(Edge({a*2,c*2}));
}

bool foxrelax(Edge edge, int u)
{
	bool flag = 0;
	int v = edge.dest, w = edge.w;
	if (foxdistance[v] > foxdistance[u] + w && (foxdistance[u]!=INF))
	{
		flag = true;
		foxdistance[v] = foxdistance[u]+w;
	}
	return flag;
}

void foxpath()
{
	fill(foxdistance,foxdistance+4040,INF);
	foxdistance[1] = 0;
	priority_queue<Edge> pq;
	pq.push(Edge({1,0}));
	while(!pq.empty())
	{
		Edge x = pq.top();
		int v = x.dest, w = x.w;
		pq.pop();
		if (w>foxdistance[v])
			continue;
		for (auto ed : fox[v])
			if (foxrelax(ed,v))
				pq.push(Edge({ed.dest,foxdistance[ed.dest]}));
	}
}

bool wolfrelax(Edge edge, int u)
{
	bool flag = 0;
	int v = edge.dest, w = edge.w;
	if (tmpwolf[v] > tmpwolf[u] + w && (tmpwolf[u]!=INF))
	{
		flag = true;
		tmpwolf[v] = tmpwolf[u]+w;
	}
	return flag;
}

void wolfpath()
{
	fill(tmpwolf,tmpwolf+8080,INF);
	tmpwolf[2] = 0;
	priority_queue<Edge> pq;
	pq.push(Edge({2,0}));
	while(!pq.empty())
	{
		Edge x = pq.top();
		int v = x.dest, w = x.w;
		pq.pop();
		if (w>tmpwolf[v])
			continue;
		for (auto ed : wolf[v])
			if (wolfrelax(ed,v))
				pq.push(Edge({ed.dest,tmpwolf[ed.dest]}));
	}
}


int32_t main()
{
	usecppio
	cin >> n >> m;
	for (int i = 0; i<m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		c = 2*c;
		foxedge(a,b,c);
		wolfedge(a,b,c);
	}
	foxpath();
	wolfpath();
	int ct = 0;
	for (int i = 1; i<=n; i++)
	{
		ct += foxdistance[i] < min(tmpwolf[i*2],tmpwolf[i*2+1]);
		//printf("%d %d\n",foxdistance[i],min(tmpwolf[i*2],tmpwolf[i*2+1]));
	}
	cout << ct;
}