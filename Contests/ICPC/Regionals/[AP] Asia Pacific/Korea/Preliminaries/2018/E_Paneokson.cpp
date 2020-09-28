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

int W, n;
int arr[505050], S[505050];
int dp[505050];
int dpsum[505050];
bool ok(int x)
{
    memset(dp, 0, sizeof(dp));
    memset(dpsum, 0, sizeof(dpsum));
    dp[0] = 1;
    dpsum[0] = 1;
    int l = 0, r = 0;
    for (int i = 1; i<=n; i++)
    {
        while(S[i] - S[l] > W) l++;
        while(S[i] - S[r] >= x) r++;
        dp[i] = ((r==0?0:dpsum[r-1]) - (l==0?0:dpsum[l-1]) > 0)?1:0;
        dpsum[i] = dpsum[i-1] + dp[i];
    }
    return dp[n];
}
int32_t main()
{
    usecppio
    cin >> W >> n;
    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        arr[i] = x;
        S[i] = S[i-1] + x;
    }
    int lo = 0, hi = W+1;
    while (lo + 1 < hi)
    {
        int mid = (lo + hi) / 2;
        if (ok(mid))
            lo = mid;
        else hi = mid;
    }
    cout << (W-lo)*(W-lo) << '\n';
}
