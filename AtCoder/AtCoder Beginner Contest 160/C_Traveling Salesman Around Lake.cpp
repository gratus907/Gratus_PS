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
const int mod = 998244353;

int k, n;
vector <int> v;
int ans = 0;
int32_t main()
{
    usecppio
    cin >> k >> n;
    for (int i = 0; i<n; i++)
    {
        int x; cin >> x; v.push_back(x);
    }
    v.push_back(v[0]+k);
    for (int i = 1; i<=n; i++)
        ans = max(ans, v[i]-v[i-1]);
    cout << k-ans << '\n';
}
