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

int32_t main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int st = (n/(a+b));
    int left = n-(st*(a+b));
    int blue = st*a;
    cout << blue+(min(left, a));
}
