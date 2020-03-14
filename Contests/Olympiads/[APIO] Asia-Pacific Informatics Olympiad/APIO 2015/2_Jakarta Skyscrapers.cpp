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
#define INF 0x7f7f7f7f
const bool debug = false;
const int MX = 30202;

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
struct doge
{
    int start, power, index;
};
int n, m;
vector <int> bi(30303, 0), pi(30303, 0);
vector <Edge> G[30303];
bitset <30303> mark[30303];
vector <doge> alldoge[30303];
vector <doge> dogeinfo;
int distances[30303];
bool visit[30303];
bool dogevisit[30303];

void dfs(doge curdoge)
{
    dogevisit[curdoge.index] = true;
    for (auto it:alldoge[curdoge.start])
        if (!dogevisit[it.index])
            dfs(it);
    for (int i = 1; ;i++)
    {
        int u = curdoge.start+i*curdoge.power;
        if (u >= n)
            break;
        bool check = false;
        for (auto it:alldoge[u])
        {
            if (it.power == curdoge.power)
                check = true;
            if (!dogevisit[it.index])
                dfs(it);
        }
        G[curdoge.start].push_back({u,i});
        if (check)
            break;
    }
    for (int i = -1; ;i--)
    {
        int u = curdoge.start+i*curdoge.power;
        if (u < 0)
            break;
        bool check = false;
        for (auto it:alldoge[u])
        {
            if (it.power == curdoge.power)
                check = true;
            if (!dogevisit[it.index])
                dfs(it);
        }
        G[curdoge.start].push_back({u,-i});
        if (check) break;
    }
}
int32_t main()
{
    usecppio
    cin >> n >> m;
    for (int i = 0; i<m; i++)
    {
        cin >> bi[i] >> pi[i];
        if (!mark[bi[i]][pi[i]] && i!=1)
        {
            mark[bi[i]][pi[i]] = true;
            alldoge[bi[i]].push_back({bi[i], pi[i], i});
        }
        dogeinfo.push_back({bi[i], pi[i], i});
    }
    dogevisit[0] = true;
    visit[dogeinfo[0].start] = 1;
    dfs(dogeinfo[0]);
    dijkstra(distances,bi[0],G);
    if (distances[bi[1]] >= 10000000)
    {
        printf("-1");
    }
    else printf("%d\n",distances[bi[1]]);
}