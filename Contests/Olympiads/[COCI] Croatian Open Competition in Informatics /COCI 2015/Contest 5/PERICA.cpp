#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int ll
int factorial[101010];
int inverse_factorial[101010];
int ans = 0;
vector <int> v;
map<int, int> mp;
const int mod = 1000000007;
ll modpow(ll x, ll y, ll p = mod)
{
    ll res = 1;
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
inline int count(int a, int b)
{
    printf("%lld %lld : %lld\n",a,b,a>b?((factorial[a]*inverse_factorial[b])%mod*inverse_factorial[a-b])%mod:(a==b?1:0));
    return a>b?((factorial[a]*inverse_factorial[b])%mod*inverse_factorial[a-b])%mod:(a==b?1:0);
}
int32_t main()
{
    factorial[0] = 1;
    for (int i = 1; i<=100000; i++)
        factorial[i] = (factorial[i-1]*i)%mod;
    for (int i = 0; i<=100000; i++)
        inverse_factorial[i] = modpow(factorial[i],mod-2);
    int n, k; cin >> n >> k;
    for (int i = 0; i<n; i++)
    {
        int x; cin >> x; v.push_back(x);
        mp[x]++;
    }
    int bef = 0;
    for (auto it:mp)
    {
        for (int i = 1; i<=min(it.second,k); i++)
        {
            printf("%lld : pick (%lld out of %lld)*(%lld out of %lld)\n",it.first,k-i,bef,i,it.second);
            ans += ((count(bef,k-i)*count(it.second,i))%mod)*it.first%mod;
            ans %= mod;
        }
        bef += it.second;
    }
    cout << ans%mod << '\n';
}

//2 2 3 중 택 2 + 4
//2_1 2_2 4, 2_1 3 4, 2_2 3 4