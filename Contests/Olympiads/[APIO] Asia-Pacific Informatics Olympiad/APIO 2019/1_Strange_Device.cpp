#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
#define int ll
using pii = pair<int, int>;
#define INF 0x7f7f7f7f7f7f7f7f
const bool debug = false;

int n, a, b;
int period;
vector <pii> v;
vector <pii> range;
int32_t main()
{
    usecppio
    ll _n, _a, _b;
    cin >> _n >> _a >> _b;
    n = _n, a = _a, b = _b;
    period = (a/(__gcd(a, b+1)))*b;
    for (int i = 0; i<n; i++)
    {
        ll l, r; cin >> l >> r;
        v.push_back({l, r});
        if (r - l + 1 >= period)
        {
            cout << period << '\n';
            return 0;
        }
        if (l%period <= r%period)
        {
            range.push_back({l%period, r%period});
        }
        else
        {
            range.push_back({0, r%period});
            range.push_back({l%period, period-1});
        }
    }
    sort(all(range));
    int start = range[0].first;
    int end = range[0].second;
    int ans = 0;
    for (int i = 1; i<range.size(); i++)
    {
        if (range[i].first > end)
        {
            ans += end-start+1;
            start = range[i].first;
            end = range[i].second;
        }
        else
            end = max(end, range[i].second);
    }
    ans += end-start+1;
    cout << ans << '\n';
}