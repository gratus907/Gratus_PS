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

const int MX = 1000;
struct Edge
{
	int dest, w;
	bool operator<(const Edge &p) const
	{
		return w > p.w;
	}
};

bool relax(Edge edge, int u, int dist[])
{
	bool flag = 0;
	int v = edge.dest, w = edge.w;
	if (dist[v] > dist[u] + w && (dist[u]<INF))
	{
		flag = true;
		dist[v] = dist[u]+w;
	}
	return flag;
}

void dijkstra(int dist[], int start, vector<Edge> graph[])
{
	fill(dist,dist+MX,INF);
	dist[start] = 0;
	priority_queue<Edge> pq;
	pq.push({start,0});
	while(!pq.empty())
	{
		Edge x = pq.top();
		int v = x.dest, w = x.w;
		pq.pop();
		if (w>dist[v])
			continue;
		for (auto ed : graph[v])
			if (relax(ed, v, dist))
				pq.push({ed.dest,dist[ed.dest]});
	}
}

vector <Edge> graph[1010];
int dist_1[1010];
int dist_v1[1010];
int dist_v2[1010];
int main()
{
	usecppio
	int n, e, v1, v2;
	cin >> n >> e;
	for (int i = 0; i<e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({b,c});
		graph[b].push_back({a,c});
	}
	cin >> v1 >> v2;
	dijkstra(dist_1,1,graph);
	dijkstra(dist_v1,v1,graph);
	dijkstra(dist_v2,v2,graph);
	int u = min(dist_1[v1]+dist_v1[v2]+dist_v2[n], dist_1[v2]+dist_v2[v1]+dist_v1[n]);
	cout << (u>=INF?-1:u);
}