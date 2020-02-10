#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int dp[10100];
int cow[10100];
int main()
{
    usecppio
    int n, k;
    cin >> n >> k;
    for (int i = 1; i<=n; i++)
        cin >> cow[i];
    for (int i = 1; i<=n; i++)
    {
        int u = cow[i];
        int curmax = 0;
        for (int j = 1; j<=min(k, i); j++)
        {  
            u = max(u,cow[i-j+1]);
            curmax = max(curmax,dp[i-j]+u*j);
        }
        dp[i] = curmax;
    }
    cout << dp[n] << '\n';
}