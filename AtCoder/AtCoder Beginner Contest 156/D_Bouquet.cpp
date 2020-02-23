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

int ncr(int n, int r)
{
    int a = 1, b = 1;
    for (int i = 1; i<=r; i++)
    {
        a *= i;
        a %= mod;
    }
    for (int i = n; i>=n-r+1; i--)
    {
        b *= i; b %= mod;
    }
    a = modpow(a, mod-2);
    return (b*a)%mod;
}

int32_t main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int u = modpow(2,n);
    int v = ncr(n,a);
    int v2 = ncr(n, b);
    cout << (u + mod - v - v2 + mod*10 - 1 + mod)%mod;
}
