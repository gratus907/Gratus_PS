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
 
void solve()
{
    int n, sum = 0, zero = 0;
    cin >> n;
    for (int i = 0; i<n; i++)
    {
        int x;
        cin >> x;
        sum += x;
        zero += (x==0);
    }
    cout << zero+(sum+zero==0?1:0) << '\n';
}
 
int32_t main()
{
    int t;
    cin >> t;
    while(t--) solve();
}