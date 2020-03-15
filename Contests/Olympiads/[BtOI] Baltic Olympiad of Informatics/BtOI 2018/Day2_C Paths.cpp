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
#define INF 0x7f7f7f7f7f7f7f7f
const bool debug = false;

int n, m, k;
int memo[303030][32];
vector <int> G[303030];
int color[303030];

int dfs(int r, int use)
{
    if (memo[r][use]!=-1)
        return memo[r][use];
    if (use & (1<<color[r]))
        return memo[r][use] = 0;
    int cur = use;
    use |= (1<<color[r]);
    int res = 1;
    for (auto it:G[r])
    {
        res += dfs(it, use);
    }
    memo[r][cur] = res;
    return memo[r][cur];
}
int32_t main()
{
    usecppio
    memset(memo,-1,sizeof(memo));
    cin >> n >> m >> k;
    for (int i = 1; i<=n; i++)
    {
        cin >> color[i];
        color[i]--;
    }
    for (int i = 0; i<m; i++)
    {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int ans = 0;
    for (int i = 1; i<=n; i++)
        ans += dfs(i, 0);
    cout << ans-n<< '\n';
}