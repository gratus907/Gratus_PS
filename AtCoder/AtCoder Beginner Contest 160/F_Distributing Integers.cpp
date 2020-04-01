#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
#define int ll
using pii = pair <int, int>;
#define INF 0x7f7f7f7f7f7f7f7f
const bool debug = 0;
const int mod = 1000000007;
ll modpow(ll x, ll y, ll p = mod)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

int n;
map<pii, int> mp;
vector <int> G[202020];
int child[202020];
int res[202020];
int inv[202020];
int dfs(int r, int p)
{
    int u = 1;
    if (G[r].size() == 1 && G[r][0] == p)
    {
        mp[{p, r}] = 1;
        mp[{r, p}] = n-1;
        return child[r] = 1;
    }
    for (auto it:G[r])
    {
        if (child[it]==-1 && it != p)
        {
            int k = dfs(it, r);
            mp[{r, it}] = k;
            mp[{it, r}] = n-k;
            u += k;
        }
    }
    return child[r] = u;
}

inline int mul(int a, int b)
{
    return (a*b)%mod;
}
inline int moddiv(int a, int b)
{
    return (a*inv[b])%mod;
}
void calc(int r, int p, int bef)
{
    int down = mp[{p, r}];
    int up = mp[{r, p}];
    int comp = mul(bef, down);
    comp = moddiv(comp, up);
    //printf("%lld : reverse (%lld, %lld). Multiply %lld, Divide %lld = %lld\n",r,p,r,up,down,comp);
    res[r] = comp;
    for (auto it:G[r])
        if (it!=p)
            calc(it, r, res[r]);
}
int32_t main()
{
    usecppio
    memset(child, -1, sizeof(child));
    cin >> n;
    for (int i = 1; i<=200000; i++)
        inv[i] = modpow(i, mod-2);
    for (int i = 1; i<n; i++)
    {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    int ans = 1;
    for (int i = 1; i<=n; i++)
        ans = mul(ans, i);
    for (int i = 1; i<=n; i++)
        ans = moddiv(ans, child[i]);
    res[1] = ans;
    for (auto it:G[1])
        calc(it, 1, ans);
    for (int i = 1; i<=n; i++)
        cout << res[i] << '\n';
}
