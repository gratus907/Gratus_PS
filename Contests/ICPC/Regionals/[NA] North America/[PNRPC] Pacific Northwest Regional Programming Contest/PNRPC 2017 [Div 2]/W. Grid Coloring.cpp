#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define int long long
int mini[40];
int maxi[40];
int dp[40][40];
char board[40][40];
int n, m;
int32_t main()
{
    scanf("%lld %lld",&n, &m);
    for (int i = 1; i<=n; i++)
    {
        scanf("%s",board[i]+1);
    }
    for (int i = n; i>=1; i--)
    {
        int rr = m+1;
        for (int j = 1; j<=m; j++)
        {
            if (board[i][j]=='R')
            {
                rr = j;
                break;
            }
        }
        maxi[i] = rr-1;
    }
    for (int i = 2; i<=n; i++)
    {
        maxi[i] = min(maxi[i],maxi[i-1]);
    }
    for (int i = 1; i<=n; i++)
    {
        int lb = 0;
        for (int j = 1; j<=m; j++)
        {
            if (board[i][j] == 'B')
            {
                lb = j;
            }
        }
        mini[i] = lb;
    }
    for (int i = n-1; i>=1; i--)
    {
        mini[i] = max(mini[i],mini[i+1]);
    }
    for (int i = mini[n]; i<=maxi[n]; i++)
        dp[n][i] = 1;
    for (int i = n-1; i>=1; i--)
    {
        for (int j = mini[i]; j<=maxi[i]; j++)
        {
            int tmp = 0;
            for (int k = 0; k<=j; k++)
            {
                tmp += dp[i+1][k];
            }
            dp[i][j] = tmp;
        }
    }
    int res = 0;
    for (int i = 0; i<=m; i++)
    {
        res += dp[1][i];
    }
    printf("%lld",res);
}
