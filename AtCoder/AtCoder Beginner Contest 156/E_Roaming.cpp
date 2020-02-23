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
int fact[402020], revfact[402020];
int ncr(int n, int r)
{
    return ((fact[n]*revfact[r])%mod)*revfact[n-r]%mod;
}

int nhr(int n, int r)
{
    return ncr(n+r-1, r)%mod;
}

int32_t main()
{
    fact[0] = 1; revfact[0] = 1;
    for (int i = 1; i<=400000; i++)
    {
        fact[i] = fact[i-1]*i;
        fact[i] %= mod;
    }
    for (int i = 1; i<=400000; i++)
        revfact[i] = modpow(fact[i],mod-2);
    int n, k;
    cin >> n >> k;
    if (k >= n-1)
    {
        cout << nhr(n, n) << '\n';
        return 0;
    }
    int free = min(n, k);
    if (free <= n)
    {
        int ans = 0;
        for (int i = n; i>=max(n-free, 1ll); i--)
        {
            int use_room = i;
            //printf("Useroom %lld\n",use_room);
            int u = nhr(i, n-i);
            //printf("Personchooseroom %lld\n",u);
            int v = ncr(n, i);
            //printf("Chooseroom %lld\n",v);
            u *= v;
            u %= mod;
            ans += u%mod;
            ans %= mod;
        }
        cout << ans << '\n';
    }
}
