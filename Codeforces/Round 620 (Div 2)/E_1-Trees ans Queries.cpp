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
const bool debug = 1;
int n, m;
bool visited[101010];
int par[101010][21];
int d[101010];
int dist[101010];
vector <pii> graph[101010]; // {destination, weight}
void dfs(int here,int depth) // run dfs(root,0)
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
 
    int lca_point = par[x][0];
    return lca_point;
}
 
void tobedone()
{
    dfs(1,0);
    precomputation();
}
 
int distr[101010];
 
inline int treedist(int a, int b)
{
    return distr[a]+distr[b] - 2*(distr[lca(a,b)]);
}
 
bool check(int req_hang, int clen)
{
    if (req_hang%2==0) return true;
    if (clen%2==1)
    {
        if (req_hang>=clen)
            return true;
    }
    return false;
}
 
int32_t main()
{
    usecppio
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back({v, 1});
        graph[v].push_back({u, 1});
    }
    tobedone();
    memset(distr, -1, sizeof(distr));
    queue<int> q;
    q.push(1);
    distr[1] = 1;
    while (!q.empty())
    {
        int x;
        x = q.front();
        q.pop();
        for (auto it:graph[x])
        {
            if (distr[it.first] == -1)
            {
                q.push(it.first);
                distr[it.first] = distr[x] + it.second;
            }
        }
    }
    int query;
    cin >> query;
    while(query--)
    {
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        int ormindist = treedist(a, b);
        int cycle_len = treedist(x, y)+1;
        bool able = false;
        if (k>=ormindist)
        {
            if ((k-ormindist)%2==0)
                able = true;
        }
        int newmindist = INT_MAX;
        newmindist = min(newmindist, treedist(a, x)+1+treedist(y, b));
        newmindist = min(newmindist, treedist(a, y)+1+treedist(x, b));
        if (k >= newmindist)
        {
            if ((k-newmindist)%2==0)
                able = true;
            if ((k-cycle_len-newmindist)>=0)
            {
                if ((k-cycle_len-newmindist)%2==0)
                {
                    able = true;
                }
            }
        }
        cout << (able?"YES\n":"NO\n");
    }
 
}