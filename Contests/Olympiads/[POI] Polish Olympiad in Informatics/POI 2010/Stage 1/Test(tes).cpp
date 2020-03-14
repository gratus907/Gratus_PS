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
#define eps 1e-7

int m, t;
vector <int> v;
vector <int> occ[1010101];
bool solve()
{
    vector <int> dq;
    int n; cin >> n;
    dq.resize(n);
    for (int i = 0; i<n; i++)
        cin >> dq[i];
    int pos = -1;
    for (auto it:dq)
    {
        auto u = upper_bound(all(occ[it]), pos);
        if (u == occ[it].end())
            return false;
        pos = *u;
    }
    return true;
}
int32_t main()
{
    usecppio
    cin >> m; v.resize(m);
    for (int i = 0; i<m; i++)
    {
        cin >> v[i];
        occ[v[i]].push_back(i);
    }
    cin >> t;
    while(t--)
        cout << (solve()?"TAK\n":"NIE\n");
}