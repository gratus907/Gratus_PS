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
const int mod = 1000000007;
const int MAX_N = 1000020;
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

int32_t main()
{
    usecppio
    int n; cin >> n;
    int nfact = 1;
    for (int i = 1; i<=n; i++)
        nfact = (nfact * i) % mod;
    int inval = modpow(2, n-1, mod);
    cout << (nfact - inval + mod) % mod << '\n';
}