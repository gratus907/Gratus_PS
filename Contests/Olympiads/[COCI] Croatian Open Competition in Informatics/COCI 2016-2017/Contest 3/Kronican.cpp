#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC target("popcnt,abm,mmx,avx,tune=native")
#define ll long long
#define int ll
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;
int n, k;
int C[25][25];
int ans = 0x7f7f7f7f7f7f7f7f;
int dp[1050505];
int32_t main()
{
    usecppio
    cin >> n >> k;
    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++)
            cin >> C[i][j];
    memset(dp, 0x7f, sizeof(dp));
    dp[0] = 0;
    for (int fs = 0; fs<(1<<n); fs++)
    {
        for (int i = 0; i<n; i++)
        {
            if (fs & (1<<i)) continue;
            for (int j = 0; j<n; j++)
                if ((fs & (1<<j)) == 0 && (i != j))
                    dp[fs | (1<<i)] =  min(dp[fs | (1<<i)], dp[fs] + C[i][j]);
        }
        if (__builtin_popcountll(fs)<n-k) continue;
        ans = min(ans, dp[fs]);
    }
    cout << ans << '\n';
}