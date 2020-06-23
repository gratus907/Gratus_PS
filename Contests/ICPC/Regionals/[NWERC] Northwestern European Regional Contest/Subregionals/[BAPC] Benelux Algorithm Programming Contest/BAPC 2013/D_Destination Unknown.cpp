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

const int INF = 987654321;
const int MX = 2020;
struct Edge
{
    int dest, w;
    bool operator<(const Edge &p) const
    {
        return w > p.w;
    }
};
vector <vector<Edge>> G;

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

void dijkstra(int dist[], int start, vector<vector<Edge>>& graph)
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
int n, m, t, s, g, h;
int dist[3][MX];
void solve()
{
    cin >> n >> m >> t >> s >> g >> h;
    int L = 0;
    G.clear();
    G.resize(n+5);
    memset(dist, 0, sizeof(dist));
    for (int i = 0; i<m; i++)
    {
        int a, b, d; cin >> a >> b >> d;
        if (a == g && b == h) L = d;
        if (a == h && b == g) L = d;
        G[a].push_back({b, d});
        G[b].push_back({a, d});
    }
    dijkstra(dist[0],s,G);
    dijkstra(dist[1],g,G);
    dijkstra(dist[2],h,G);
    vector <int> possible;
    for (int i = 0; i<t; i++)
    {
        int x;
        cin >> x;
        int st = dist[0][x];
        int c1 = dist[0][g]+L+dist[2][x];
        int c2 = dist[0][h]+L+dist[1][x];
        if (c1 == st || c2 == st)
            possible.push_back(x);
    }
    sort(all(possible));
    for (auto it:possible)
        cout << it << ' ';
    cout << '\n';
}

int main()
{
    usecppio
    int T; cin >> T;
    while(T--)
        solve();
}