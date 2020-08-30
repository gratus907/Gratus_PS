#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define ll long long
#define int ll
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;
const bool debug = 0;

int n, m, C;
int dp[1010][1010];
int val[1010];
vector <int> G[1010];
int32_t main()
{
    memset(dp, 0xf7, sizeof(dp));
    usecppio
    cin >> n >> m >> C;
    for (int i = 1; i<=n; i++)
        cin >> val[i];
    for (int i = 0; i<m; i++)
    {
        int u, v; cin >> u >> v;
        G[v].push_back(u);
    }
    dp[1][0] = 0;
    for (int t = 1; t<=1000; t++)
    {
        for (int i = 1; i<=n; i++)
        {
            dp[i][t] = max(dp[i][t], dp[i][t-1]);
            for (int prev:G[i])
                dp[i][t] = max(dp[i][t], dp[prev][t-1]+val[i]);
        }
    }
    int M = 0;
    for (int i = 1; i<=1000; i++)
        M = max(M, dp[1][i] - C*i*i);
    cout << M << '\n';
}