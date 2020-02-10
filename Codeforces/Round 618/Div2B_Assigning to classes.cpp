
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
 
void solve()
{
    int n;
    vector <int> v;
    cin >> n;
    for (int i = 0; i<2*n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(all(v));
    cout << v[n]-v[n-1] << '\n';
}
 
int32_t main()
{
    int t;
    cin >> t;
    while(t--) solve();
}