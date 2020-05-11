#include <bits/stdc++.h>
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define int ll
const bool debug = 0;
using pii = pair<int, int>;
typedef long double D;

D dp[2020][2020];
int n, t;
D p;
int32_t main()
{
    usecppio
    cin >> n >> p >> t;
    dp[0][0] = 1.0;
    for (int i = 1; i<=t; i++)
    {
        for (int j = 0; j<=n+1; j++)
        {
            if (j)
                dp[i][j] += dp[i-1][j-1]*p;
            dp[i][j] += dp[i-1][j]*(1-p);
        }
        dp[i][n] += dp[i][n+1];
        dp[i][n+1] = 0;
    }
    D ans = 0;
    for (int i = 0; i<=n; i++)
        ans += dp[t][i]*i;
    cout << fixed << setprecision(20) << ans << '\n';
}