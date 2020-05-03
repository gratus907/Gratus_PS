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

map<int, int> mp;
int h[202020];
int ans = 0;
int32_t main()
{
    usecppio
    int n; cin >> n;
    for (int i = 1; i<=n; i++)
        cin >> h[i];
    for (int i = 1; i<=n; i++)
        mp[i-h[i]]++;
    for (int i = 1; i<=n; i++)
        ans += mp[i+h[i]];
    cout << ans<< '\n';
}
