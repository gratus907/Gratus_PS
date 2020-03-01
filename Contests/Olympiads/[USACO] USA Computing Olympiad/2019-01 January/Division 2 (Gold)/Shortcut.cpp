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
int dt[10101], parent[10101], n, m, t;
int ctpass[10101];
int cowcount[10101];
const int INF = 987654321;
const int MX = 10005;

struct Edge
{
    int dest, w;
    Edge(int a = -1, int b = 0)
    {
        dest = a, w = b;
    }
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
        parent[v] = u;
    }
    else if (dist[v] == dist[u] + w && (dist[u]!=INF) && u<parent[v])
    {
        parent[v] = u; flag = true;
    }
    return flag;
}

vector <Edge> gph[10101];
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

void backtrack(int st)
{
    int cur = st;
    while(cur != 1)
    {
        ctpass[cur] += cowcount[st];
        cur = parent[cur];
    }
    ctpass[cur] += cowcount[st];
    return;
}
int32_t main()
{
    usecppio
    cin >> n >> m >> t;
    for (int i = 1; i<=n; i++)
        cin >> cowcount[i];
    while(m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        gph[u].push_back({v, w});
        gph[v].push_back({u, w});
    }
    int maxred = 0;
    dijkstra(dt, 1, gph);
    for (int i = 1; i<=n; i++)
        backtrack(i);
    for (int i = 2; i<=n; i++)
        maxred = max(maxred, ctpass[i]*(dt[i]-t));
    cout << maxred << '\n';
}