#include <bits/stdc++.h>
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const bool debug = 0;
#define INF 0x7f7f7f7f
using pii = pair<int, int>;
typedef long double D;
const int MX = 222;
struct MCMF
{
    vector <int> G[MX];
    int cap[MX][MX] = {0};
    int cost[MX][MX] = {0};
    int flow[MX][MX] = {0};
    void addEdge(int s, int e)
    {
        G[s].push_back(e);
        G[e].push_back(s);
    }
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
            int curmaxflow = INF;
            for(int i=sink; i!=source; i=prev[i])
                curmaxflow = min(curmaxflow, cap[prev[i]][i] - flow[prev[i]][i]);
            for(int i=sink; i!=source; i=prev[i])
            {
                mincost += curmaxflow * cost[prev[i]][i];
                flow[prev[i]][i] += curmaxflow;
                flow[i][prev[i]] -= curmaxflow;
            }
            maxflow += curmaxflow;
        }
        return {maxflow, mincost};
    }
};

MCMF MCMF;
int arr[105][105];
int32_t main()
{
    usecppio
    int n, m;
    cin >> n >> m;
    int S = 204, E = 205;
    for (int i = 1; i<=n; i++)
    {
        cin >> MCMF.cap[i+100][E];
        MCMF.addEdge(i+100, E);
    }
    for (int i = 1; i<=m; i++)
    {
        cin >> MCMF.cap[S][i];
        MCMF.addEdge(S, i);
    }
    for (int i = 1; i<=m; i++)
    {
        for (int j = 1; j<=n; j++)
        {
            cin >> MCMF.cap[i][j+100];
            MCMF.addEdge(i, j+100);
        }
    }
    for (int i = 1; i<=m; i++)
    {
        for (int j = 1; j<=n; j++)
        {
            cin >> MCMF.cost[i][j+100];
            MCMF.cost[j+100][i] = -MCMF.cost[i][j+100];
        }
    }
    auto P = MCMF.MinCostMaxFlow(S, E);
    cout << P.first << '\n';
    cout << P.second << '\n';
}