#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define ll long long
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx,avx2,fma")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int ll
#define all(x) ((x).begin()),((x).end())
#define eps 1e-6
using pii = pair<int, int>;

int dp[2020][2020];
int n, h, l, r;
vector <int> v;
int32_t main()
{
    usecppio
    cin >> n >> h >> l >> r;
    v.resize(n);
    for (int i = 0; i<=2010; i++)
        for (int j = 0; j<=2010; j++)
            dp[i][j] = -1e9;
    for (int i = 0; i<n; i++) cin >> v[i];
    dp[0][0] = 0;
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<h; j++)
        {
            int u = (j+v[i])%h;
            if (l <= u && u <= r)
                dp[i+1][u] = max(dp[i+1][u], dp[i][j]+1);
            else
                dp[i+1][u] = max(dp[i+1][u], dp[i][j]);
            int up = (j+v[i]-1+h)%h;
            if (l <= up && up <= r)
                dp[i+1][up] = max(dp[i+1][up], dp[i][j]+1);
            else
                dp[i+1][up] = max(dp[i+1][up], dp[i][j]);
        }
    }
    int ans = 0;
    for (int i = 0; i<h; i++)
        ans = max(dp[n][i], ans);
    cout << ans << '\n';
}
