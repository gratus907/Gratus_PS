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
 
vector <pii> v;
int32_t main()
{
    usecppio
    int n;
    cin >> n;
    if (n%2 ==1)
    {
        cout << "NO\n"; return 0;
    }
    for (int i = 0; i<n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    v.push_back(v[0]);
    for (int i = 1; i<=n/2; i++)
    {
        pii vt1 = {abs(v[i].first-v[i-1].first), abs(v[i].second-v[i-1].second)};
        pii vt2 = {abs(v[i+n/2].first-v[i+n/2-1].first), abs(v[i+n/2].second-v[i+n/2-1].second)};
        if (vt1 != vt2)
        {
            cout << "NO\n"; return 0;
        }
    }
    cout << "YES\n";
}
