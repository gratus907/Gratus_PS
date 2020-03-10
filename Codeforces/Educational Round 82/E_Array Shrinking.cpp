#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx,avx2,fma")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int ll
#define all(x) ((x).begin()),((x).end())
#define eps 1e-7
const int mod = 998244353;
int n;
int arr[550];
int dp[550][550];
int il[550][550];
int32_t main()
{
    usecppio
    cin >> n;
    for (int i = 1; i<=n; i++)
    {
        cin >> arr[i];
        dp[i][i] = arr[i];
    }
    for (int i = 1; i<=n; i++)
        for (int j = 1; j<=n; j++)
            il[i][j] = abs(i-j)+1;
    for (int i = n-1; i>=1; i--)
    {
        for (int j = i+1; j<=n; j++)
        {
            for (int k = i+1; k<=j; k++)
            {
                if (dp[i][k-1]==dp[k][j] && dp[i][k-1]>0)
                {
                    dp[i][j] = max(dp[i][j], dp[i][k-1]+1);
                    il[i][j] = min(il[i][j], il[i][k-1]+il[k][j]-1);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i<=n; i++)
        for (int j = 1; j<=n; j++)
            ans = max(ans, dp[i][j]);
    for (int i = n-1; i>=1; i--)
        for (int j = i; j<=n; j++)
            for (int k = i+1; k<=j; k++)
                il[i][j] = min(il[i][j], il[i][k-1]+il[k][j]);
    int mlen = n;
    for (int i = 1; i<=n; i++)
        for (int j = 1; j<=n; j++)
            mlen = min(mlen, -abs(i-j)-1+n+il[i][j]);
    cout << mlen << '\n';
}