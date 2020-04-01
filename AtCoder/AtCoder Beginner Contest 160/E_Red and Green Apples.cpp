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
using pii = pair <int, int>;
#define INF 0x7f7f7f7f7f7f7f7f
const bool debug = 0;
const int mod = 998244353;

priority_queue<int, vector <int>, greater<int>> pq;
int x, y, a, b, c;
vector <int> red, green, colorless;
int32_t main()
{
    usecppio
    cin >> x >> y >> a >> b >> c;
    for (int i = 0; i<a; i++)
    {
        int u; cin >> u; red.push_back(u);
    }
    for (int i = 0; i<b; i++)
    {
        int u; cin >> u; green.push_back(u);
    }
    for (int i = 0; i<c; i++)
    {
        int u; cin >> u; colorless.push_back(u);
    }
    sort(all(red),greater<int>());
    sort(all(green),greater<int>());
    sort(all(colorless),greater<int>());
    for (int i = 0; i<x; i++)
        pq.push(red[i]);
    for (int i = 0; i<y; i++)
        pq.push(green[i]);
    for (auto it:colorless)
    {
        if (pq.top() < it)
        {
            pq.pop();
            pq.push(it);
        }
    }
    int ans = 0;
    while(!pq.empty())
    {
        ans += pq.top();
        pq.pop();
    }
    cout << ans << '\n';
}
