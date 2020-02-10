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
#define int ll
 
void solve()
{
    int a, b;
    cin >> a >> b;
    int t = 10;
    int ans = 0;
    while(t-1 <= b)
    {
        t *= 10;
        ans++;
    }
    cout << ans * a << '\n';
}
int32_t main()
{
    int t; cin >> t; while(t--) solve();
}