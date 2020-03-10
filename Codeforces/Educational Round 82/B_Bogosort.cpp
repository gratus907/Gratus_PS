#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx,avx2,fma")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
#define eps 1e-7

void solve()
{
    vector <int> v;
    int n; cin >> n; v.resize(n);
    for (int i = 0; i<n; i++)
        cin >> v[i];
    sort(all(v),greater<int>());
    for (auto it:v)
    {
        cout << it << ' ';
    }
    cout << '\n';
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