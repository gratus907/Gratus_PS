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
int n, k;
char mv;
int arr[101010];
int dp[101010][25][3];
int main()
{
    usecppio
    cin >> n >> k;
    for (int i = 1; i<=n; i++)
    {
        cin >> mv;
        if (mv == 'H') arr[i] = 2;
        else if (mv == 'P') arr[i] = 0;
        else arr[i] = 1;
    }
    arr[0] = -1;
    for (int i = 1; i<=n+1; i++)
    {
        for (int j = 1; j<=k+1; j++)
        {
            for (int m = 0; m<3; m++)
            {
                int c1 = dp[i-1][j][m];
                int c2 = dp[i-1][j-1][(m+1)%3];
                int c3 = dp[i-1][j-1][(m+2)%3];
                dp[i][j][m] = max({c1,c2,c3})+(arr[i-1] == m);
            }
        }
    }
    cout << max({dp[n+1][k+1][0],dp[n+1][k+1][1],dp[n+1][k+1][2]});
}