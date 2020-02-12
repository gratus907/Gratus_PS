#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
using pii = pair <int, int>;

int n, w;
int weight[255];
int talent[255];

double dp[1010];
bool ok(double x)
{
    fill(dp,dp+1010,-1e9);
    dp[0] = 0;
    for (int i = 0; i<n; i++)
    {
        double score = talent[i]-x*weight[i];
        for (int j = w; j>=0; j--)
        {
            if (dp[j]==-1e9)
                continue;
            dp[min(j+weight[i], w)] = max(dp[min(j+weight[i], w)],dp[j]+score);
        }
    }
    return dp[w]>=0;
}

int32_t main()
{
    cin >> n >> w;
    for (int i = 0; i<n; i++)
        cin >> weight[i] >> talent[i];
    double lo = 0, hi = 1e8;
    for (int i = 0; i<50; i++)
    {
        double mid = (lo+hi)/2;
        if (ok(mid))
            lo = mid;
        else hi = mid;
    }
    cout << (ll)(lo*1000) << '\n';
}