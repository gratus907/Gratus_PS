#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
#define eps 1e-7
#define int ll
using pii = pair <int, int>;
int a, b, G;
pii getbest(int x) // g
{
    int nb = (b/x)+1-(b%x==0?1:0);
    nb *= x;
    int n = nb-b;
    if (n == 0)
        n += x;
    return {lcm(a+n, b+n),n};
}
int32_t main()
{
    cin >> a >> b;
    if (b > a) swap(a, b);
    G = abs(a-b);
    vector <int> v;
    for (int i = 1; i*i<=G; i++)
    {
        if (G%i == 0)
        {
            v.push_back(i);
            v.push_back(G/i);
        }
    }
    int best_lcm = LLONG_MAX, best_n = 1;
    for (auto it:v)
    {
        auto u = getbest(it);
        if (u.second==0)
            continue;
        if (u < pair{best_lcm, best_n})
        {
            best_lcm = u.first;
            best_n = u.second;
        }
    }
    cout << best_n << '\n';
}