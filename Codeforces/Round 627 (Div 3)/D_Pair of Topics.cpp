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

vector <int> v;
int teach[202020];
int student[202020];
int32_t main()
{
    usecppio
    int n; cin >> n;
    for (int i = 0; i<n; i++)
        cin >> teach[i];
    for (int i = 0; i<n; i++)
    {
        cin >> student[i];
        v.push_back(teach[i]-student[i]);
    }
    sort(all(v));
    int ans = 0;
    for (auto it:v)
    {
        auto t = upper_bound(all(v),-it);
        int u = v.size()-(t-v.begin());
        if (it>0)
            ans += (u-1);
        else ans += u;
    }
    cout << ans/2 << '\n';
}
