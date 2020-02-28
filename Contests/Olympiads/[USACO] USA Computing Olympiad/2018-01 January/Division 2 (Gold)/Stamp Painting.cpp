#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
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
const int mod = 1000000007;
int n, m, k;
int sdp[1010101];
int ans = 1;

int32_t main()
{
    cin >> n >> m >> k;
    for (int i = 1; i<=n; i++)
    {
        sdp[i] = m*sdp[i-1];
        sdp[i] %= mod;
        int u = i>=k?(m-1)*sdp[i-k]:-m;
        u %= mod;
        sdp[i] -= u; 
        sdp[i] += mod; 
        sdp[i] %= mod;
    }
    for(int i = 1; i<=n; i++)
        ans = (m*ans)%mod;

    cout << (sdp[n-1]-sdp[n]+ans+mod)%mod << '\n';
}