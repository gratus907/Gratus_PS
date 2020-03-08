#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
#define eps 1e-7
#pragma GCC optimize ("unroll-loops")

string s;
int transition[10][10101], n, p;
ll ans;
int dp[2][10101];
ll modpow(ll x, ll y)
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
    cin >> n >> p >> s;
    int inv = modpow(10, p-2);
    if (p < 10)
    {
        for (int j = 0; j<10; j++)
            for (int i = 0; i<p; i++)
                transition[j][i] = ((i*10)+j)%p;
        int r = 0;
        for (int i = 0; i<n; i++)
        {
            int u = s[i]-'0';
            r = 1-r;
            memset(dp[r],0,sizeof(dp[r]));
            for (int j = 0; j<p; j++)
            {
                int k = transition[u][j];
                dp[r][k] += dp[1-r][j];
            }
            dp[r][transition[u][0]]++;
            ans += dp[r][0];
        }
        cout << ans << '\n';
    }
    else
    {
        for (int j = 0; j<10; j++)
            for (int i = 0; i<p; i++)
                transition[j][i] = (((i-j+p)%p)*(inv))%p;
        int r = 0;
        for (int i = 0; i<n; i++)
        {
            register int u = s[i]-'0';
            r = 1-r;
            for (int j = 0; j<p; j++)
            {
                int k = transition[u][j];
                dp[r][j] = dp[1-r][k];
            }
            dp[r][u]++;
            ans += dp[r][0];
        }
        cout << ans << '\n';
    }
}
