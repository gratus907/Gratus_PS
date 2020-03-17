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
const int MX = 222;
struct MCMF
{
    vector <int> G[MX];
    int cap[MX][MX] = {0};
    int cost[MX][MX] = {0};
    int flow[MX][MX] = {0};
    pair<int, int> MinCostMaxFlow(int source, int sink) // Maxflow, mincost of flow
    {
        int maxflow = 0, mincost = 0;
        while(true)
        {
            int dist[MX], prev[MX];
            bool inQ[MX];
            fill(inQ, inQ+MX, 0);
            fill(dist, dist + MX, INF);
            fill(prev, prev + MX, -1);
            deque <int> q;
            dist[source] = 0;
            inQ[source] = true;
            q.push_back(source);
            while (!q.empty())
            {
                int here = q.front();
                q.pop_front();
                inQ[here] = false;
                for (int i = 0; i < G[here].size(); i++)
                {
                    int nxt = G[here][i];
                    int cst = cost[here][nxt];
                    if(cap[here][nxt]-flow[here][nxt] > 0 && dist[nxt] > dist[here] + cst)
                    {
                        dist[nxt] = dist[here] + cst;
                        prev[nxt] = here;
                        if (!inQ[nxt])
                        {
                            q.push_back(nxt);
                            inQ[nxt] = true;
                            if (dist[q.back()]<dist[q.front()])
                            {
                                q.push_front(q.back());
                                q.pop_back();
                            }
                        }
                    }
                }
            }
            if(prev[sink] == -1)
                break;
            maxflow = INF;
            for(int i=sink; i!=source; i=prev[i])
                maxflow = min(maxflow, cap[prev[i]][i] - flow[prev[i]][i]);
            for(int i=sink; i!=source; i=prev[i])
            {
                mincost += maxflow * cost[prev[i]][i];
                flow[prev[i]][i] += maxflow;
                flow[i][prev[i]] -= maxflow;
            }
        }
        return {maxflow, mincost};
    }
};

MCMF MCMF;
int32_t main()
{
    int n, m;
    cin >> n >> m;
    int S = 204, E = 205;
    for (int i = 1; i<=n; i++)
    {
        cin >> MCMF.cap[i][E];
        MCMF.G[E].push_back(i);
        MCMF.G[i].push_back(E);
    }
    for (int i = 1; i<=m; i++)
    {
        cin >> MCMF.cap[S][i+100];
        MCMF.G[S].push_back(i+100);
        MCMF.G[i+100].push_back(S);
    }
    for (int i = 1; i<=m; i++)
    {
        for (int j = 1; j<=n; j++)
        {
            cin >> MCMF.cost[i+100][j];
            MCMF.cost[j][i+100] = -MCMF.cost[i+100][j];
            MCMF.cap[i+100][j] = INF;
            MCMF.G[i+100].push_back(j);
            MCMF.G[j].push_back(i+100);
        }
    }
    auto P = MCMF.MinCostMaxFlow(S, E);
    cout << P.second << '\n';
}