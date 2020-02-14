#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-9
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define int ll
using pii = pair<int, int>;
const int mod = 1000000007;
int ans = 1, n, k;
vector <int> tree[101010];
vector <pii> ed;
int color[101010];
bool checked[101010];
bool possible_color[101010][4];
int memo[101010][4];
int CALLS;
int dfs(int r, int par, int parc)
{
    CALLS++;
    if (memo[r][parc]!=-1)
        return memo[r][parc];
    int res = 0;
    for (int i = 1; i<=3; i++)
    {
        if (possible_color[r][i] && i != parc)
        {
            int u = 1;
            for (auto it:tree[r])
            {
                if (it!=par)
                {
                    u *= dfs(it,r,i);
                    u %= mod;
                }
            }
            res += u;
        }
    }
    memo[r][parc] = (res%mod);
    return (memo[r][parc]);
}
int32_t main()
{
    usecppio
    cin >> n >> k;
    memset(memo,-1,sizeof(memo));
    for (int i = 1; i<n; i++)
    {
        int u, v;
        cin >> u >> v;
        ed.push_back({u, v});
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    memset(possible_color,true, sizeof(possible_color));
    for (int i = 0; i<k; i++)
    {
        int r, c;
        cin >> r >> c;
        color[r] = c;
        for (int cc = 1; cc<=3; cc++)
            possible_color[r][cc] = (cc==c);
        checked[r] = true;
        for (auto it:tree[r])
            possible_color[it][c] = false;
    }
    for (auto it:ed)
    {
        if (color[it.first]==color[it.second] && color[it.first]!=0)
        {
            cout << 0 << '\n'; return 0;
        }
    }
    cout << dfs(1, 0, 0)%mod << '\n';
}