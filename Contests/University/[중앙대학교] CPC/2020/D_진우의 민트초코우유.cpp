#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;

int dp[14][1<<14][150];
int xc[14], yc[14], dt[14][14];
int n, m, h, cnt = 1, res;
int bitDP(int cur, int done, int curHP)
{
    if (dp[cur][done][curHP] >= 0) return dp[cur][done][curHP];
    if (curHP >= dt[cur][0])
    {
        dp[cur][done][curHP] = max(dp[cur][done][curHP], __builtin_popcount(done) - 1);
        res = max(res, dp[cur][done][curHP]);
    }
    int dpval = dp[cur][done][curHP];
    for (int i = 1; i < cnt; i++)
    {
        if (!(done & (1 << i)))
        {
            if (curHP >= dt[cur][i])
                dpval = max(dpval, bitDP(i, done | (1 << i), curHP - dt[cur][i] + h));
            else continue;
        }
        else continue;
    }
    return (dp[cur][done][curHP] = dpval);
}
int32_t main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n >> m >> h;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int t; cin >> t;
            if (t == 0) continue;
            if (t == 2)
                xc[cnt] = i, yc[cnt++] = j;
            if (t == 1)
                xc[0] = i, yc[0] = j;
        }
    }
    for (int i = 0; i < cnt; i++)
        for (int j = 0; j < cnt; j++)
            dt[i][j] = abs(xc[i] - xc[j]) + abs(yc[i] - yc[j]);
    bitDP(0, 1, m);
    cout << res << '\n';
}