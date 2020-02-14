#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
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
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

ordered_set l, r;
vector <int> v;
int32_t main()
{
    int n; cin >> n;
    v.resize(n);
    for (int i = 0; i<n; i++)
    {
        cin >> v[i];
        r.insert(v[i]);
    }
    int cnt = 0;
    for (int i = 0; i<n; i++)
    {
        r.erase(r.lower_bound(v[i]));
        int li = l.size()-l.order_of_key(v[i]);
        int ri = r.size()-r.order_of_key(v[i]);
        //printf("%lld %lld\n",li,ri);
        l.insert(v[i]);
        if (min(li, ri)*2<max(li,ri))
            cnt++;
    }
    cout << cnt << '\n';
}