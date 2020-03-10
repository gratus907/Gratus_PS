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

int n, k;
int ans = 987654321987654321;
deque <int> v;
int dp[10][101];
int32_t main()
{
    cin >> n >> k;
    v.resize(n);
    for (int i = 0; i<n; i++)
        cin >> v[i];
    for (int i = 0; i<n; i++)
    {
        memset(dp, 0x7f, sizeof(dp));
        dp[0][n] = 0;
        for (int j = 1; j<=k; j++)
        {
            for (int u = 0; u<n; u++)
            {
                int x = 0;
                for (int s = u; s<n; s++)
                {
                    x += v[s]*(s-u);
                    dp[j][u] = min(dp[j][u], dp[j-1][s+1]+x);
                }
            }
        }
        ans = min(ans, dp[k][0]);
        v.push_back(v[0]);
        v.pop_front();
    }
    cout << ans << '\n';
}