#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define int ll
using pii = pair<int, int>;
const int mod = 1000000009;
vector <int> primes;
bool is_composite[50505];
int ypow[101010];
void prime_sieve()
{
    is_composite[1] = true;
    is_composite[2] = false;
    primes.push_back(2);
    for (int i = 4; i<50000; i+=2) is_composite[i] = true;
    for (int i = 3; i<50000; i+=2)
    {
        if (!is_composite[i])
        {
            primes.push_back(i);
            for (int j = 2*i; j<50000; j+=i)
                is_composite[j] = true;
        }
    }
}
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

ll modinv(ll x, ll p = mod)
{
    return modpow(x,p-2,p);
}


vector <int> pfact;
vector <int> adds, oad;
vector <int> subs, osb;
int n, y;
int ory;
int32_t main()
{
    usecppio
    cin >> n >> y;
    ypow[0] = 1;
    for (int i = 1; i<=100000; i++)
        ypow[i] = (ypow[i-1]*y)%mod;
    ory = y;
    prime_sieve();
    int final_divisor = ypow[n];
    for (auto it:primes)
    {
        if (y%it==0)
        {
            while(y%it==0)
                y/=it;
            pfact.push_back(it);
        }
    }
    if (y!=1)
        pfact.push_back(y);
    int u = (1<<(pfact.size()));
    for (int i = 1; i<u; i++)
    {
        int sgn = __builtin_popcountll(i)%2==0?-1:1;
        int cur = 1;
        for (int j = 0; j<pfact.size(); j++)
            if ((1<<j)&i)
                cur *= pfact[j];
        if (sgn == -1)
            subs.push_back(ory/cur);
        else
            adds.push_back(ory/cur);
    }
    osb = subs;
    oad = adds;
    int ans = 0;
    for (int len = 1; len <= n; len++)
    {
        int ct = n-len+1;
        int t = 0;
        for (int j = 0; j<adds.size(); j++)
        {
            t += adds[j];
            adds[j] *= oad[j];
            adds[j] %= mod;
            t %= mod;
        }
        for (int j = 0; j<subs.size(); j++)
        {
            t += (mod-subs[j]);
            subs[j] *= osb[j];
            subs[j] %= mod;
            t %= mod;
        }
        int aa = ypow[len];
        t = (mod+aa-t)*modinv(aa)%mod;
        t *= ct;
        t %= mod;
        ans += t;
        ans %= mod;
    }
    cout << (ans*final_divisor)%mod;
}