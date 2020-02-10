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
 
inline int divv(int a, int b)
{
    return (a/b)+1 - (a%b==0?1:0);
}
bool solve()
{
    int n, d;
    cin >> n >> d;
    int u = sqrt(d);
    int st = max(u-100,0ll);
    int opt = INT_MAX;
    int ed = min(u+100,d);
    for (int i = st; i<=ed; i++)
        opt = min(opt, i + divv(d,i+1));
    return (opt <= n);
}
int32_t main()
{
    int t;
    cin >> t;
    while(t--)
        cout << (solve()?"YES\n":"NO\n");
}