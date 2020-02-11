#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define int ll
using pii = pair<int, int>;

int n;
int arr[300];
int dp[300][300];
int32_t main()
{
    cin >> n;
    for (int i = 1; i<=n; i++)
    {
        cin >> arr[i];
        dp[i][i] = arr[i];
    }
    for (int i = n-1; i>=1; i--)
        for (int j = i+1; j<=n; j++)
            for (int k = i+1; k<=j; k++)
                if (dp[i][k-1]==dp[k][j])
                    dp[i][j] = max(dp[i][j], dp[i][k-1]+1);
    int ans = 0;
    for (int i = 1; i<=n; i++)
        for (int j = 1; j<=n; j++)
            ans = max(ans, dp[i][j]);

    cout << ans << '\n';
}