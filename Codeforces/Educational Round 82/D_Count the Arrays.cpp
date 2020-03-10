#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx,avx2,fma")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int ll
#define all(x) ((x).begin()),((x).end())
#define eps 1e-7
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

int fact[201010];
int invfact[201010];

int binom(int n, int r)
{
    int t = (fact[n]*(invfact[r]))%mod;
    return (t*invfact[n-r])%mod;
}
int32_t main()
{
    int n, m; cin >> n >> m;
    if (m<(n-1))
    {
        cout << 0 << '\n'; return 0;
    }
    fact[0] = 1; invfact[0] = 1;
    for (int i = 1; i<=200000; i++)
    {
        fact[i] = fact[i-1]*i;
        fact[i] %= mod;
        invfact[i] = modpow(fact[i],mod-2);
    }
    int a = binom(m, n-1);
    int b = (n-2);
    int c = modpow(2, n-3);
    cout << ((a*b%mod)*c)%mod << '\n';
}