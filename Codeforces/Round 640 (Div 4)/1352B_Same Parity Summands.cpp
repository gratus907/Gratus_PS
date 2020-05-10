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
    if (n%2==1 && k%2==0)
    {
        cout << "NO\n";
        return;
    }
    if (n%2==k%2)
    {
        if (n<k)
        {
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
        for (int i = 1; i<k; i++)
            cout << 1 << ' ';
        cout << n-k+1 << '\n';
    }
    else
    {
        if (n<2*k)
        {
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
        for (int i = 1; i<k; i++)
            cout << 2 << ' ';
        cout << n-k*2+2 << '\n';
    }
}

int32_t main()
{
    usecppio
    int t;
    cin >> t;
    while(t--)
        solve();
}