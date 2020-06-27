#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define int ll
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;
int n;
bool visited[101010];
int par[101010][21];
int d[101010];
int dt[101010];
vector <pii> graph[101010]; // {destination, weight}
void dfs(int here,int depth)
{
    visited[here] = true;
    d[here] = depth;
    for (auto there : graph[here])
    {
        if (visited[there.first])
            continue;
        dfs(there.first, depth + 1);
        par[there.first][0] = here;
    }
}

void precomputation()
{
    for (int i = 1; i<21; i++)
        for (int j = 1; j<=n; j++)
            par[j][i] = par[par[j][i-1]][i-1];
}

int lca(int x, int y)
{
    if (d[x]>d[y])
        swap(x,y);
    for (int i = 20; i>=0; i--)
        if (d[y]-d[x] >= (1<<i))
            y = par[y][i];
    if (x==y)
        return x;
    for (int i = 20; i>=0; i--)
    {
        if (par[x][i] != par[y][i])
        {
            x = par[x][i];
            y = par[y][i];
        }
    }
    return par[x][0];
}

void lca_construction()
{
    dfs(1,0);
    precomputation();
}

int32_t main()
{
    usecppio
    cin >> n;
    for (int i = 1; i<n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    lca_construction();
    memset(visited, 0, sizeof(visited));
    queue<int> queue;
    queue.push(1);
    dt[1] = 0;
    visited[1] = true;
    while(!queue.empty())
    {
        int x = queue.front();
        queue.pop();
        for (auto it:graph[x])
        {
            if (!visited[it.first])
            {
                dt[it.first] = dt[x] + it.second;
                queue.push(it.first);
                visited[it.first] = true;
            }
        }
    }
    int Q; cin >> Q;
    while(Q--)
    {
        int q; cin >> q;
        if (q == 1)
        {
            int u, v; cin >> u >> v;
            int z = dt[u] + dt[v] - 2*dt[lca(u, v)];
            cout << z << '\n';
        }
        else
        {
            int u, v, k; cin >> u >> v >> k;
            int L = lca(u, v);
            int deep = d[u]-d[L];
            if (deep + 1 >= k)
            {
                k--;
                for (int t = 0; t<20; t++)
                    if (k & (1<<t))
                        u = par[u][t];
                cout << u << '\n';
            }
            else
            {
                k = d[v] - d[lca(u, v)] + 1 + deep - k;
                int t = 0;
                while (k)
                {
                    if (k & 1) v = par[v][t];
                    k /= 2;
                    t++;
                }
                cout << v << '\n';
            }
        }
    }
}