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
using pii = pair<int, int>;
#define INF 0x7f7f7f7f7f7f7f7f
const bool debug = false;
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

bool is_composite[15151515];
vector <int> primes;
int ans = 1;
int32_t main()
{
    int n, m; cin >> n >> m;
    int u = min(n, m);
    primes.push_back(2);
    for (int i = 4; i <= 15050000; i+=2)
        is_composite[i] = true;
    for (int i = 3; i <= 15050000; i+=2)
    {
        if (!is_composite[i])
        {
            primes.push_back(i);
            for (int j = i * 2; j <= 15050000; j += i)
                is_composite[j] = true;
        }
    }
    for (auto it:primes)
    {
        if (it > u) break;
        int sum = 0;
        for (int x = it; x<=u; x *= it)
            sum += (n/x)*(m/x);
        ans *= (modpow(it, sum));
        ans %= mod;
    }
    cout << ans%mod << '\n';
}