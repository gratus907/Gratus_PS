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
        int u, v;
        cin >> u >> v;
        graph[u].push_back({v, 1});
        graph[v].push_back({u, 1});
    }
    lca_construction();
    int Q; cin >> Q;
    while(Q--)
    {
        int r, u, v;
        cin >> r >> u >> v;
        int a = lca(r, u);
        int b = lca(u, v);
        int c = lca(v, r);
        int ans;
        if (d[a] > d[b]) ans = a;
        else ans = b;
        if (d[c] > d[ans]) ans = c;
        cout << ans << '\n';
    }
}