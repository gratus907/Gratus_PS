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
int t, n;
int s = 0;
map<string, int> D;
vector <pii> v;
int32_t main()
{
    usecppio
    cin >> t >> n;
    D["Mon"] = 0;
    D["Tue"] = 1;
    D["Wed"] = 2;
    D["Thu"] = 3;
    D["Fri"] = 4;
    for (int i = 0; i<n; i++)
    {
        string d1, d2;
        int h1, h2;
        cin >> d1 >> h1 >> d2 >> h2;
        int start_sleep = D[d1]*24+h1;
        int end_sleep = D[d2]*24+h2;
        s += (end_sleep-start_sleep);
    }
    if (s >= t)
    {
        cout << 0 << '\n';
        return 0;
    }
    else if (s + 48 < t)
    {
        cout << -1 << '\n';
        return 0;
    }
    cout << t-s << '\n';
    return 0;
}