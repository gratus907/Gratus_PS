#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
using pii = pair <int, int>;
int mod = 1000000003;
int dp[1010][1010];
int binom(int n, int r)
{
    return dp[n][r];
}
int32_t main()
{
    int n, k; cin >> n >> k;
    for (int i = 0; i<=1000; i++)
    {
        dp[i][0] = dp[0][i] = 1;
        dp[i][i] = 1;
    }
    for (int i = 1; i<=1000; i++)
        for (int j = 1; j<i; j++)
            dp[i][j] = (dp[i-1][j]+dp[i-1][j-1])%mod;
    if (k*2 > n)
    {
        cout << 0 << '\n';
        return 0;
    }
    int ans = (binom(n-k+1, k) + mod - binom(n-k-1, k-2))%mod;
    cout << ans;
}