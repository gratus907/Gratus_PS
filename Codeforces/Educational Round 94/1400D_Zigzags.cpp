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

vector <int> ctpair[3030];
vector <pii> pairs;
ll dp[3030][3030];
void solve()
{
    vector <int> arr;
    pairs.clear();
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i<3030; i++)
        ctpair[i].clear();
    int n; cin >> n;
    for (int i = 0; i<n; i++)
    {
        int x; cin >> x;
        arr.push_back(x);
        ctpair[x].push_back(i+1);
    }
    for (int i = 1; i<=n; i++)
    {
        for (int at : ctpair[i])
        {
            for (int bt : ctpair[i])
            {
                if (at >= bt) continue;
                dp[at][bt]++;
                pairs.push_back({at, bt});
            }
        }
    }
    for (int i = 1; i<=n; i++)
        for (int j = n; j>=1; j--)
            dp[i][j] += dp[i][j+1];

    for (int i = 1; i<=n; i++)
    {
        for (int j = 1; j<=n; j++)
        {
            dp[i][j] += dp[i-1][j];
        }
    }
    ll ans = 0;
    for (pii p : pairs)
    {
        int li = p.first;
        int ri = p.second;
        ans += (dp[ri-1][ri+1] - dp[li][ri+1]);
    }
    cout << ans << '\n';
}

int32_t main()
{
    usecppio
    int t;
    cin >> t;
    while(t--) solve();
}