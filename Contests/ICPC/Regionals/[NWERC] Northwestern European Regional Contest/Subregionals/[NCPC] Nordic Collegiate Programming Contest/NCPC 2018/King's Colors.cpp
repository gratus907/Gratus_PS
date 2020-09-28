#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int mod = 1000000007;
int ans = 0;
const int MAX_N = 2520;
int modpow(int x, int y, int p = mod)
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

int fact[MAX_N+5];
int invfact[MAX_N+5];

int binom(int n, int r)
{
    int t = (fact[n]*(invfact[r]))%mod;
    return (t*invfact[n-r])%mod;
}

void precompute()
{
    fact[0] = 1; invfact[0] = 1;
    for (int i = 1; i<=MAX_N; i++)
    {
        fact[i] = fact[i-1]*i;
        fact[i] %= mod;
    }
    invfact[MAX_N] = modpow(fact[MAX_N],mod-2);
    for (int i = MAX_N-1; i>=1; i--)
    {
        invfact[i] = invfact[i+1]*(i+1);
        invfact[i] %= mod;
    }
}
inline int add(int a, int b)
{
    return (a + b)%mod;
}
inline int sub(int a, int b)
{
    return (mod + a - b)%mod;
}
inline int mul(int a, int b)
{
    return ((a%mod)*(b%mod))%mod;
}
int32_t main()
{
    usecppio
    precompute();
    int n, k; cin >> n >> k;
    int sgn = 0;
    for (int i = k; i>=2; i--)
    {
        int cur = mul(binom(k, i), mul(i, modpow(i-1,n-1)));
        if (sgn)
            ans = sub(ans, cur);
        else ans = add(ans, cur);
        sgn = 1 - sgn;
    }
    cout << ans << '\n';
}