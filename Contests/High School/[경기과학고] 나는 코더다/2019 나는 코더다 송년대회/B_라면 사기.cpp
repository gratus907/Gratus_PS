#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define sz(v) ((int)(v).size())
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;
#define int ll
int ramen[1010101][3];
int b, c, n;
int cost, total;
int32_t main()
{
    usecppio
    cin >> n >> b >> c;
    for (int i = 1; i<=n; i++)
    {
        cin >> ramen[i][0];
        total += ramen[i][0];
        int u = min(ramen[i-1][0], ramen[i][0]);
        ramen[i][1] = u;
        ramen[i-1][0] -= u;
        ramen[i][0] -= u;
        int v = min(ramen[i-1][1], ramen[i][0]);
        ramen[i][2] = v;
        ramen[i-1][1] -= v;
        ramen[i][0] -= v;
    }
    for (int i = 1; i<=n; i++)
    {
        cost += ramen[i][0]*b;
        cost += ramen[i][1]*(b+c);
        cost += ramen[i][2]*(b+2*c);
    }
    cout << min(cost, total*b) << '\n';
}
