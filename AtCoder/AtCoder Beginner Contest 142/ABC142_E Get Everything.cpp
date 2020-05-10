#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int n, m;
int cost[1010];
int open[1010];
int dp[1010][4100];
const int INF = 0x3f3f3f3f;
int main()
{
    usecppio
    cin >> n >> m;
    memset(dp,0x3f,sizeof(dp));
    int allkey = 0; 
    for (int i = 1; i<=m; i++)
    {
        int a, b;
        cin >> a >> b;
        cost[i] = a;
        for (int j = 0; j<b; j++)
        {
            int c;
            cin >> c;
            open[i] |= (1<<(c-1));
        }
        allkey |= open[i];
    }
    int nos = (1<<n);
    if (allkey!=nos-1)
    {
        cout << -1 << '\n'; return 0;
    }
    dp[0][0] = 0;
    for (int i = 1; i<=m; i++)
    {
        memcpy(dp[i], dp[i-1], sizeof(dp[i]));
        for (int k = 0; k<nos; k++)
        {
            int nk = k|open[i];
            dp[i][nk] = min(dp[i][nk], dp[i-1][k]+cost[i]);
        }
    }
    if (dp[m][nos-1] >= INF)
    {
        cout << -1 << '\n'; return 0;
    }
    cout << dp[m][nos-1] << '\n';
}