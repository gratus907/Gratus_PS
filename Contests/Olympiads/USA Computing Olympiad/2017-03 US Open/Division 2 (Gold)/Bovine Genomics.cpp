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
int n, m;
set <string> sa, sb;
vector <string> spot, plain;
bool check_one(int x, int st)
{
    sa.clear(); sb.clear();
    set<string> intersect;
    for (auto it:spot)
        sa.insert(it.substr(st,x));
    for (auto it:plain)
        sb.insert(it.substr(st,x));
    set_intersection(all(sa),all(sb),inserter(intersect,intersect.begin()));
    return intersect.empty();
}
bool check_all(int x)
{
    for (int i = 0; i<=m-x; i++)
    {
        bool u = check_one(x,i);
        if (u)
            return true;
    }
    return false;
}
int32_t main()
{
    cin >> n >> m;
    for (int i = 0; i<n; i++)
    {
        string t; cin >> t; spot.push_back(t);
    }
    for (int i = 0; i<n; i++)
    {
        string t; cin >> t; plain.push_back(t);
    }
    int lo = 0, hi = m;
    while(lo + 1 < hi)
    {
        int mid = (lo+hi)/2;
        if (check_all(mid))
            hi = mid;
        else
            lo = mid;
    }
    cout << hi << '\n';
}
