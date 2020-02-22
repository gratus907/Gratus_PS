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
const int mod = 1000000007;

bool able(vector <int> &heights)
{
    int n = heights.size()-1;
    multiset <int> st_left, st_right;
    for (int i = 1; i<=n; i++)
        st_right.insert(heights[i]);
    for (int i = 1; i<n; i++)
    {
        st_left.insert(heights[i-1]);
        st_right.erase(st_right.lower_bound(heights[i]));
        auto u = st_left.lower_bound(heights[i]);
        if (u == st_left.end()) continue;
        int v = *st_right.rbegin();
        if (*u < v)
            return true;
    }
    return false;
}
vector <int> valids;
int32_t main()
{
    usecppio
    int n;
    cin >> n;
    for (int i = 1; i<=n; i++)
    {
        vector <int> v;
        int t; cin >> t;
        for (int j = 0; j<t; j++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        if (able(v))
        {
            valids.push_back(i);
        }
    }
    cout << valids.size() << '\n';
    for (auto it:valids)
    {
        cout << it << '\n';
    }
}