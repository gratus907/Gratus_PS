#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
#define int ll
using pii = pair <int, int>;
int n, m, k;
const int INF = 987654321987654321;
const int MX = 50505;
int taste[50505];
struct Edge
{
    int dest, w;
    bool operator<(const Edge &p) const
    {
        return w > p.w;
    }
};
int dt[MX];
int dt2[MX];
vector<Edge> G[MX];
vector<pii> hay;
bool relax(Edge edge, int u, int dist[])
{
    bool flag = 0;
    int v = edge.dest, w = edge.w;
    if (dist[v] > dist[u] + w && (dist[u]!=INF))
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
int32_t main()
{
    cin >> n >> m >> k;
    for (int i = 0; i<m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    for (int i = 0; i<k; i++)
    {
        int a, b;
        cin >> a >> b;
        taste[a] = b;
        hay.push_back({a, b});
    }
    dijkstra(dt,n,G);
    for (auto it:hay)
    {
        int u = dt[it.first];
        int v = it.second;
        G[0].push_back({it.first,u-v});
    }
    dijkstra(dt2,0,G);
    for (int i = 1; i<n; i++)
        cout << ((dt[i]>=dt2[i])?1:0) << '\n';
}