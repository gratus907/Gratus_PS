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

void solve()
{
    int n, k;
    cin >> n >> k;
    int u = (k-1)/(n-1);
    int v = (n-1)*u;
    int x = u*n+1;
    cout << x + (k-v-1) << '\n';
}

int32_t main()
{
    usecppio
    int t;
    cin >> t;
    while(t--)
        solve();
}