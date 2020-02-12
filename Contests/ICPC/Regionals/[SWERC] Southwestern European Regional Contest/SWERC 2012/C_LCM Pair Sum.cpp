#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-9
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;
#define int ll
#define MOD 1000000007
ll modpow(ll x, ll y, ll p = MOD)
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


void solve()
{
    int c;
    cin >> c;
    vector <pii> v;
    int divsum_contribution[20];
    int divsum[33333];
    int countdiv[33333];
    int partial[33333];
    memset(divsum_contribution, 0, sizeof(divsum_contribution));
    for (int i = 0; i<c; i++)
    {
        int p, a;
        cin >> p >> a;
        v.push_back({p, a});
        divsum_contribution[i] = (modpow(p,a)-1)*(modpow(p-1,MOD-2));
        divsum_contribution[i] %= MOD;
    }
    for (int i = 0; i<(1<<c); i++)
    {
        int u = 1;
        int tmp = 1, tmp2 = 1;
        for (int j = 0; j<c; j++)
        {
            if (i&(1<<j))
            {
                u *= modpow(v[j].first,v[j].second);
                u %= MOD;
                tmp *= (v[j].second+1);
                tmp %= MOD;
                tmp2 *= divsum_contribution[j];
                tmp2 %= MOD;
            }
        }
        partial[i] = u;
        countdiv[i] = tmp;
        divsum[i] = tmp2;
    }
    int ans = 0;
    for (int i = 0; i<(1<<c); i++)
    {
        ans += ((countdiv[i]*divsum[(1<<c)-i-1]%MOD)*partial[i])%MOD;
        ans %= MOD;
    }
    cout << (ans+partial[(1<<c)-1])%MOD << '\n';
}
int32_t main()
{
    usecppio
    int TC;
    cin >> TC;
    while (TC--)
        solve();
}