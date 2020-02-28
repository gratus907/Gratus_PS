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
int grass[105][105];
int dt[111111] , n, t;
const int INF = 987654321;
const int MX = 30303;

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
    }
    return flag;
}

vector <Edge> gph[50505];
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

int di[4] = {0, 0, -1, 1};
int dj[4] = {-1, 1, 0, 0};
inline int newpt(int ori, int orj, int mval)
{
    return 3*((ori-1)*n+orj-1)+mval;
}

void addedge(int s, int d, int w)
{
    gph[s].push_back(Edge(d, w));
}
int32_t main()
{
    cin >> n >> t;
    for (int i = 1; i<=n; i++)
        for (int j = 1; j<=n; j++)
            cin >> grass[i][j];
    memset(dt, 0x3f, sizeof(dt));
    for (int i = 1; i<=n; i++)
    {
        for (int j = 1; j<=n; j++)
        {
            for (int dd = 0; dd<4; dd++)
            {
                int ni = i+di[dd];
                int nj = j+dj[dd];
                if (ni <= 0 || nj <= 0 || ni > n || nj > n)
                    continue;
                addedge(newpt(i,j,0),newpt(ni,nj,1),t);
                addedge(newpt(i,j,1),newpt(ni,nj,2),t);
                addedge(newpt(i,j,2),newpt(ni,nj,0),t+grass[ni][nj]);
            }
        }
    }
    dijkstra(dt, newpt(1,1,0), gph);
    cout << min(min(dt[newpt(n,n,0)],dt[newpt(n,n,1)]),dt[newpt(n,n,2)]) << '\n';
}
