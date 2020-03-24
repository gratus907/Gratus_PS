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
const int INF = 987654321;
const int MX = 10505;
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
vector <Edge> G[10505];
int dist[11000];
int32_t main()
{
    usecppio
    int n; cin >> n;
    for (int i = 1; i<n; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    dijkstra(dist, 1, G);
    int far = 0, fardist = 0;
    for (int i = 1; i<=n; i++)
    {
        if (fardist < dist[i])
        {
            far = i;
            fardist = dist[i];
        }
    }
    dijkstra(dist, far, G);
    int farfar = 0;
    fardist = 0;
    for (int i = 1; i<=n; i++)
    {
        if (fardist < dist[i])
        {
            farfar = i;
            fardist = dist[i];
        }
    }
    cout << dist[farfar] << '\n';
}