#include <bits/stdc++.h>
using namespace std;
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

void solve()
{
    int n; cin >> n;
    bool odd = 0, even = 0;
    for (int i = 0; i<n; i++)
    {
        int x; cin >> x;
        if (x%2) odd = 1;
        else even = 1;
    }
    if (even & odd)
        cout << "NO\n";
    else cout << "YES\n";
}
int32_t main()
{
    usecppio
    int t; cin >> t;
    while(t--)
    {
        solve();
    }
}
