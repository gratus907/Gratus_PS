#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define int ll
using pii = pair<int, int>;

string str;
int32_t main()
{
    usecppio
    int n, m, q; cin >> n >> m >> q;
    for (int i = 0; i<m; i++)
    {
        int u = i%(2*n);
        str.push_back('a'+(u/2));
    }
    while(q--)
    {
        int a, b; cin >> a >> b;
    }
    cout << str << '\n';
}