#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
using pii = pair <int, int>;
#define int ll
#define INF 0x7f7f7f7f7f7f7f7f
const bool debug = false;
int a[202020], b[202020];
int n;
vector <int> v;
vector <int> v2;
int32_t main()
{
    usecppio
    cin >> n;
    for (int i = 1; i<=n; i++)
    {
        cin >> a[i];
        cin >> b[i];
        if (a[i]>b[i])
            v.push_back(b[i]);
        else if (a[i]<b[i])
            v2.push_back(a[i]);
    }
    if (v.empty() && v2.empty())
        cout << 0 << '\n';
    else
    {
        int ans = 0;
        for (int i = 1; i<=n; i++)
            ans += b[i];
        sort(all(v));
        ans -= v.front();
        cout << ans << '\n';
    }
}
