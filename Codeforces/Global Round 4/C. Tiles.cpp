#include <bits/stdc++.h>
#define int ll
#define ll long long
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

using pii = pair<int, int>;

const int mod = 998244353;
int32_t main()
{
    int w, h;
    cin >> w >> h;
    int ans = 1;
    for (int i = 0; i<(w+h); i++)
    {
        ans *= 2;
        ans %= mod;
    }
    cout << ans%mod;
}
