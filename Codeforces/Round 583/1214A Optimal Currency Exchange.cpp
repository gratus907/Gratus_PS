#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main()
{
    int n, e, d;
    cin >> n >> d >> e;
    e *= 5;
    int ans = 987654321;
    for (int i = 0; i<=(n/d); i++)
    {
        int u = n - (i*d);
        int v = u/e;
        u -= v*e;
        ans = min(u, ans);
    }
    cout << ans << '\n';
}