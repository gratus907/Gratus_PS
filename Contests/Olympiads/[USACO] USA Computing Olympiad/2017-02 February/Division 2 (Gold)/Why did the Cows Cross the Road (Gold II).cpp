#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
using pii = pair <int, int>;

#define int ll
int n;
int l[1010], r[1010];
int dp[1010][1010];
int connect[1010][1010];
int32_t main()
{
    cin >> n;
    for (int i = 1; i<=n; i++)
        cin >> l[i];
    for (int i = 1; i<=n; i++)
        cin >> r[i];
    for (int i = 1; i<=n; i++)
        for (int j = 1; j<=n; j++)
            connect[i][j] = abs(l[i]-r[j])<=4?1:0;
    for (int i = 1; i<=n; i++)
    {
        for (int j = 1; j<=n; j++)
        {
            int u = max(dp[i-1][j],dp[i][j-1]);
            int v = dp[i-1][j-1] + connect[i][j];
            dp[i][j] = max(u, v);
        }
    }
    cout << dp[n][n] << '\n';
}