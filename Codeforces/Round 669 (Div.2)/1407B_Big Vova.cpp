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
    multiset<int> m;
    vector <int> arr;
    int n; cin >> n;
    arr.resize(n+5);
    for (int i = 1; i<=n; i++)
    {
        cin >> arr[i];
        m.insert(arr[i]);
    }
    int G = *m.rbegin();
    cout << G << ' ';
    m.erase(m.lower_bound(G));
    while(!m.empty())
    {
        int maxval = 0, res = 0;
        for (auto it:m)
        {
            int gnxt = G;
            gnxt = __gcd(G, it);
            if (maxval < gnxt)
            {
                maxval = gnxt;
                res = it;
            }
        }
        m.erase(m.lower_bound(res));
        cout << res << ' ';
        G = maxval;
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