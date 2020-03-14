#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
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
vector <int> mp;
int solve()
{
    string s; cin >> s;
    mp.clear();
    mp.push_back(0);
    for (int i = 0; i<s.length(); i++)
    {
        if (s[i] == 'R') mp.push_back(i+1);
    }
    mp.push_back(s.length()+1);
    int ans = 0;
    for (int i = 1; i<mp.size(); i++)
    {
        ans = max(ans, mp[i]-mp[i-1]);
    }
    return ans;
}
int32_t main()
{
    usecppio
    int t; cin >> t;
    while(t--)
    {
        cout << (solve()) << '\n';
    }
}
