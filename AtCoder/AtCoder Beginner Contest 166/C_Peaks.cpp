#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
#define int ll
using pii = pair <int, int>;
#define INF 0x7f7f7f7f7f7f7f7f
const bool debug = 0;
const int mod = 1000000007;

vector <int> G[101010];
int H[101010];
int n, m, ans;
int32_t main()
{
    usecppio
    cin >> n >> m;
    for (int i = 1; i<=n; i++) cin >> H[i];
    for (int i = 0; i<m; i++)
    {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i<=n; i++)
    {
        bool good = true;
        for (auto it:G[i])
        {
            if (H[i] <= H[it])
                good = false;
        }
        ans += good;
    }
    cout << ans;
}
