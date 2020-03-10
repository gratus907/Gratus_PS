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

vector <int> a, b;
int32_t main()
{
    usecppio
    int n, m, p;
    cin >> n >> m >> p;
    a.resize(n);
    b.resize(m);
    for (int i = 0; i<n; i++)
        cin >> a[i];
    for (int i = 0; i<m; i++)
        cin >> b[i];
    int npt = 0, mpt = 0;
    while(a[npt]%p==0) npt++;
    while(b[mpt]%p==0) mpt++;
    cout << npt+mpt << '\n';
}