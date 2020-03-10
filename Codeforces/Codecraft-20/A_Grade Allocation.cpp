#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
#define eps 1e-7
#define int ll
using pii = pair <int, int>;

vector <int> v;
void solve()
{
    v.clear();
    int n, m;
    cin >> n >> m;
    int s = 0;
    for (int i = 0; i<n; i++)
    {
        int a; cin >> a; v.push_back(a);
        s += a;
    }
    cout << min(s, m) << '\n';
}

int32_t main()
{
    usecppio
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}