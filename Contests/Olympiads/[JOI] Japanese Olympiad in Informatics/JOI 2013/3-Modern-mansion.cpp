#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define int ll
using pii = pair<int, int>;

int m, n, k;
struct Edge {
    int dest, w;
    bool operator<(const Edge &p) const {
        return w > p.w;
    }
};
struct swt {
    int id, r, c;
};
swt all_swts[404040];
vector <swt> swts_row[101010];
vector <swt> swts_col[101010];
vector <Edge> G[404040];
int C = 200000;
int src = 402001, snk = 402005;
void add_swt(int id, int did, int r, int c) {
    swt s = {id, r, c};
    swt sd = {did, r, c};
    all_swts[id] = s;
    all_swts[did] = sd;
    swts_row[r].push_back(sd);
    swts_col[c].push_back(s);
    G[s.id].push_back({sd.id, 1});
    G[sd.id].push_back({s.id, 1});
}


const int INF = 987654321987654321;
const int MX = 404040;
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
int dist[404040];
bool sw_11 = false;
int32_t main() {
    usecppio
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        int r, c; cin >> c >> r;
        if (r == 1 and c == 1) {
            sw_11 = true;
            src = i;
        }
        add_swt(i, i+C, r, c);
    }
    add_swt(snk, snk+1, m, n);
    if(!sw_11)
        add_swt(src, src+1, 1, 1);
    for (int i = 1; i <= m; i++) {
        sort(all(swts_row[i]), [](swt &a, swt &b) -> bool {
            return a.c < b.c;
        });
        for (int j = 1; j < swts_row[i].size(); j++) {
            swt s = swts_row[i][j];
            swt sp = swts_row[i][j-1];
            if (!sw_11 and (s.id == src || sp.id == src || s.id == src + 1 || sp.id == src+1)) continue;
            G[s.id].push_back({sp.id, s.c - sp.c});
            G[sp.id].push_back({s.id, s.c - sp.c});
        }
    }
    for (int i = 1; i <= n; i++) {
        sort(all(swts_col[i]), [](swt &a, swt &b) -> bool {
            return a.r < b.r;
        });
        for (int j = 1; j < swts_col[i].size(); j++) {
            swt s = swts_col[i][j];
            swt sp = swts_col[i][j-1];
            G[s.id].push_back({sp.id, s.r - sp.r});
            G[sp.id].push_back({s.id, s.r - sp.r});
        }
    }
    dijkstra(dist, src, G);
    int ans = min(dist[snk], dist[snk+1]);
    cout << (ans <= 1e12? ans : -1) << '\n';
}