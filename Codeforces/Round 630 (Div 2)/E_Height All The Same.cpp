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
const int mod = 998244353;
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

int solve(int n, int m, int p, int q)
{
    int u = (p+q)%mod;
    int v = (q-p+mod)%mod;
    int uu = modpow(u, n*m);
    int vv = modpow(v, n*m);
    int w = (uu+vv)%mod;
    int ww = w * (modpow(2, mod-2));
    ww %= mod;
    return ww;
}

int32_t main()
{
    usecppio
    int n, m, L, R, p, q;
    cin >> n >> m >> L >> R;
    int dt = (R-L+1);
    p = q = dt/2;
    if (dt%2==1)
    {
        if (L%2==1)
            p++;
        else q++;
    }
    int a1 = solve(n,m,p,q)%mod;
    int a2 = solve(n,m,q,p)%mod;
    int ans;
    if (n*m%2==1)
        ans = (a1+a2)%mod;
    else ans = a1;
    cout << ans << '\n';
}