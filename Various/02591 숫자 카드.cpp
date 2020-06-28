#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
using pii = pair <int, int>;

int arr[45];
int dp[45];
int32_t main()
{
    string s;
    cin >> s;
    for (int i = 1; i<=s.length(); i++)
        arr[i] = s[i-1]-'0';
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i<=s.length(); i++)
    {
        if (arr[i] == 0)
        {
            if (arr[i-1] > 0 && arr[i-1] < 4)
                dp[i] = dp[i-2];
            else
                dp[i] = 0;
        }
        else
        {
            dp[i] = dp[i-1];
            if (arr[i] + arr[i-1]*10 <= 34 && arr[i-1]!=0)
                dp[i] += dp[i-2];
        }

        //printf("DP %lld = %lld\n",i,dp[i]);
    }

    cout << dp[s.length()];
}