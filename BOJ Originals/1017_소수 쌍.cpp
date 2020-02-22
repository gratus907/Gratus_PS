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
#define PI acos(-1.0)
using pii = pair<int, int>;

// Dinic Library Code. Original Author JaehyunP(Stanford U, Facebook)
struct Edge
{
    int u, v;
    ll cap, flow;
    Edge() {}
    Edge(int u, int v, ll cap): u(u), v(v), cap(cap), flow(0) {}
};

struct Dinic
{
    int N;
    vector<Edge> E;
    vector<vector<int>> g;
    vector<int> d, pt;

    Dinic(int N): N(N), E(0), g(N), d(N), pt(N) {}

    void AddEdge(int u, int v, ll cap)
    {
        if (u != v)
        {
            E.push_back(Edge(u, v, cap));
            g[u].push_back(E.size() - 1);
            E.push_back(Edge(v, u, 0));
            g[v].push_back(E.size() - 1);
        }
    }
    bool BFS(int S, int T)
    {
        queue<int> q({S});
        fill(d.begin(), d.end(), N + 1);
        d[S] = 0;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            if (u == T) break;
            for (int k: g[u])
            {
                Edge &e = E[k];
                if (e.flow < e.cap && d[e.v] > d[e.u] + 1)
                {
                    d[e.v] = d[e.u] + 1;
                    q.push(e.v);
                }
            }
        }
        return d[T] != N + 1;
    }

    ll DFS(int u, int T, ll flow = -1)
    {
        if (u == T || flow == 0) return flow;
        for (int &i = pt[u]; i < g[u].size(); i++)
        {
            Edge &e = E[g[u][i]];
            Edge &oe = E[g[u][i]^1];
            if (d[e.v] == d[e.u] + 1)
            {
                ll amt = e.cap - e.flow;
                if (flow != -1 && amt > flow) amt = flow;
                if (ll pushed = DFS(e.v, T, amt))
                {
                    e.flow += pushed;
                    oe.flow -= pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }

    ll MaxFlow(int S, int T)
    {
        ll total = 0;
        while (BFS(S, T))
        {
            fill(pt.begin(), pt.end(), 0);
            while (ll flow = DFS(S, T))
                total += flow;
        }
        return total;
    }
};
// Dinic Library Code
Dinic D = Dinic(60);
bool iscomp[2020];
void sieve()
{
    for (int i = 4; i<=2000; i+=2)
        iscomp[i] = true;
    for (int i = 3; i<=2000; i+=2)
        if (!iscomp[i])
            for (int j = 2*i; j<=2000; j+=i)
                iscomp[j] = true;
}
int n;
int arr[55];

inline bool is_prime(int x)
{
    return !iscomp[x];
}

Dinic make_dinic(int removed)
{
    Dinic newdinic = Dinic(120);
    bool seen[120][2];
    memset(seen, 0,sizeof(seen));
    for (int i = 1; i<n; i++)
    {
        newdinic.AddEdge(0, i, 1);
        newdinic.AddEdge(n+i,115,1);
        if (i==removed) continue;
        for (int j = i+1; j<n; j++)
        {
            if (j==removed)
                continue;
            if (is_prime(arr[i]+arr[j]))
            {
                newdinic.AddEdge(i,j+n,1);
                newdinic.AddEdge(j,i+n,1);
            }
        }
    }
    return newdinic;
}

int32_t main()
{
    usecppio
    sieve();
    cin >> n;
    for (int i = 0; i<n; i++) cin >> arr[i];
    vector <int> v;
    for (int i = 1; i<n; i++)
    {
        if (is_prime(arr[0]+arr[i]))
        {
            D = make_dinic(i);
            int k = D.MaxFlow(0,115);
            if (k>=n-2)
            {
                v.push_back(arr[i]);
            }
        }
    }
    sort(all(v));
    if (v.empty())
    {
        cout << -1 << '\n'; return 0;
    }
    for (auto it:v)
    {
        cout << it << ' ';
    }
    cout << '\n';
}