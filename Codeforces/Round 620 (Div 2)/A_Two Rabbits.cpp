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
 
void solve()
{
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    int d = y-x;
    int e = a+b;
    if (d%e)
    {
        cout << -1 << '\n';
        return;
    }
    else
    {
        cout << (d/e) << '\n';
        return;
    }
}
 
int32_t main()
{
    usecppio
    int t;
    cin >> t;
    while(t--) solve();
}