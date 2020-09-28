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
    int n; cin >> n;
    for (int i = 1; i<=n; i++)
    {
        cout << i << ' ';
    }
    cout << '\n';
}

int32_t main()
{
    usecppio
    int t;
    cin >> t;
    while(t--) solve();
}