#include<bits/stdc++.h>
using namespace std;

const int INF = (int)2e9+(int)1e8;
int n;
int dp[5020][5020][2];
int arr[5020];

int reducetime (int p, int v)
{
    if (arr[p]<=v)
        return 0;
    else
        return arr[p]-v;
}
int main()
{
    scanf("%d",&n);
    for (int i = 1; i<=n; i++)
        scanf("%d",arr+i);
    for (int i = 0; i<5020; i++)
    {
        for (int j = 0; j<5020; j++)
        {
            for (int k = 0; k<2; k++)
            {
                dp[i][j][k] = 2100000000;
            }
        }
    }
    dp[1][0][0] = 0;
    dp[1][1][1] = 0;
    for (int i = 1; i<=n; i++)
    {
        for (int j = 0; j<=(n/2 + (n%2)); j++)
        {
            for (int k = 0; k<2; k++)
            {
                int val = dp[i][j][k];
                if (k==0)
                {
                    dp[i+1][j+1][1] = min(dp[i+1][j+1][1],val+reducetime(i,arr[i+1]-1));
                    dp[i+1][j][0] = min(dp[i+1][j][0],val);
                }
                else
                {
                    dp[i+2][j+1][1] = min(dp[i+2][j+1][1],val+reducetime(i+1,min(arr[i],arr[i+2])-1));
                    dp[i+1][j][0] = min(dp[i+1][j][0],val+reducetime(i+1,arr[i]-1));
                }
            }
        }
    }
    for (int i = 1; i<=(n/2 + (n%2)); i++)
    {
        printf("%d ",min(dp[n][i][0],dp[n][i][1]));
    }
}
