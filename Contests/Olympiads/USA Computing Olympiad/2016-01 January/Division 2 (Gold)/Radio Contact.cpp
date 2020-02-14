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

int n, m;
int fr[1010], fc[1010], br[1010], bc[1010];
string s, t;
int dt[1010][1010];
int dp[1010][1010];

int32_t main()
{
    usecppio
    cin >> n >> m;
    cin >> fr[0] >> fc[0] >> br[0] >> bc[0];
    cin >> s >> t;
    for (int i = 1; i<=n; i++)
    {
        fr[i] = fr[i-1]; fc[i] = fc[i-1];
        if (s[i-1]=='N')
            fc[i]++;
        else if (s[i-1]=='E')
            fr[i]++;
        else if (s[i-1] == 'W')
            fr[i]--;
        else if (s[i-1] == 'S')
            fc[i]--;
    }
    for (int i = 1; i<=m; i++)
    {
        br[i] = br[i-1]; bc[i] = bc[i-1];
        if (t[i-1]=='N')
            bc[i]++;
        else if (t[i-1]=='E')
            br[i]++;
        else if (t[i-1] == 'W')
            br[i]--;
        else if (t[i-1] == 'S')
            bc[i]--;
    }
    for (int i = 0; i<=1000; i++)
        for (int j = 0; j<=1000; j++)
            dt[i][j] = abs(fr[i]-br[j])*abs(fr[i]-br[j])+abs(fc[i]-bc[j])*abs(fc[i]-bc[j]);
    memset(dp,0x7f,sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i<=m; i++)
        dp[0][i] = dp[0][i-1] + dt[0][i];
    for (int i = 1; i<=n; i++)
        dp[i][0] = dp[i-1][0] + dt[i][0];
    for (int i = 1; i<=n; i++)
    {
        for (int j = 1; j<=m; j++)
        {
            dp[i][j] = min(min(dp[i][j],dp[i-1][j-1]+dt[i][j]),min(dp[i-1][j]+dt[i][j], dp[i][j-1]+dt[i][j]));
        }
    }
    cout << dp[n][m] << '\n';
}