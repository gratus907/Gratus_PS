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
const int mod = 123456789;
int dp[1010101];
int psum;
int L, S;
int32_t main()
{
    usecppio
    cin >> L >> S;
    dp[0] = 1;
    psum = 1;
    for (int i = 1; i<S; i++)
    {
        dp[i] = psum;
        dp[i] %= mod;
        psum += dp[i];
        psum %= mod;
    }
    for (int i = S; i<L; i++)
    {
        dp[i] = psum;
        dp[i] %= mod;
        psum += dp[i];
        psum -= dp[i-S];
        psum %= mod;
        psum += mod; psum %= mod;
    }
    int ans = 0;
    for (int i = 1; i<=S; i++)
    {
        ans += (dp[L-i]*i)%mod;
        ans %= mod;
    }
    cout << ans << '\n';
}