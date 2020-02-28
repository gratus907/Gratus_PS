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

int dp[120][120];
int n;
int arr[120];

int main()
{
    cin >> n;
    for (int i = 1; i<=n; i++)
        cin >> arr[i];
    for (int i = 1; i<=110; i++)
        for (int j = 1; j<=110; j++)
            dp[i][j] = 100;
    dp[0][1] = 0;
    for (int i = 1; i<=n; i++)
        dp[i][1] = dp[i-1][1] + (arr[i]!=(i-1) ? 1 : 0);
    for (int i = 2; i<=n; i++)
        dp[i][i] = dp[i-1][i-1] + (arr[i]!=0?1:0);
    for (int i = 3; i<=n; i++)
    {
        for (int j = 2; j<i; j++)
        {
            for (int k = 1; k<i; k++)
            {
                int ct = 0;
                for (int p = k+1; p<=i; p++)
                    if (arr[p]!=p-k-1)
                        ct++;
                dp[i][j] = min(dp[i][j], dp[k][j-1]+ct);
            }
        }
    }
    for (int i = 1; i<=n; i++)
        cout << dp[n][i] << '\n';
}