#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
using pii = pair<int, int>;
#define INF 0x7f7f7f7f
const bool debug = false;
const int MX = 20020;
struct Edge
{
    int dest, w;
    bool operator<(const Edge &p) const
    {
        return w > p.w;
    }
};
bool inQ[MX];
void spfa(int dist[], int start, vector<Edge> graph[])
{
    fill(dist, dist + MX, INF);
    deque <int> q;
    dist[start] = 0;
    inQ[start] = true;
    q.push_back(start);
    while (!q.empty())
    {
        int here = q.front();
        q.pop_front();
        inQ[here] = false;
        for (int i = 0; i < graph[here].size(); i++)
        {
            int next = graph[here][i].dest;
            int cost = graph[here][i].w;
            if(dist[next] > dist[here] + cost)
            {
                dist[next] = dist[here] + cost;
                if (!inQ[next])
                {
                    q.push_back(next);
                    inQ[next] = true;
                    if (dist[q.back()]<dist[q.front()])
                    {
                        q.push_front(q.back());
                        q.pop_back();
                    }
                }
            }
        }
    }
}
vector <Edge> edgelist[MX];
int V, E, start;
int dist[MX];

int32_t main()
{
    scanf("%d %d %d",&V,&E,&start);
    for (int i = 0; i<E; i++)
    {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        edgelist[u].push_back({v,w});
    }
    spfa(dist,start,edgelist);
    for (int i = 1; i<=V; i++)
    {
        if (dist[i] == INF)
            printf("INF\n");
        else
            printf("%d\n",dist[i]);
    }
}