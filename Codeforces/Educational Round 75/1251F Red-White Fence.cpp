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
const bool debug = 0;
using pii = pair<int, int>;
typedef long double D;
/* Library for solving Combinatorics */
const int MAX_N = 606060;
const int mod = 998244353;
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

int frac(int a, int b)
{
    return (a*(modpow(b,mod-2)))%mod;
}
/* Library for solving Combinatorics */

vector <int> one;
vector <int> many;
vector <int> res;
vector <int> white(303030, 0);
vector <int> red;

//NTT Polynomial Multiplication
#define sz(v) ((int)(v).size())
typedef int base;
typedef vector <int> vi;
typedef vector <base> vb;
const double PI = acos(-1);

void fft(vb &a, bool invert)
{
    int n = sz(a);
    for (int i = 1, j=0; i<n; i++)
    {
        int bit = n>>1;
        for (; j>=bit; bit>>=1)
        {
            j -= bit;
        }
        j += bit;
        if (i < j)
            swap(a[i],a[j]);
    }
    vector<base> root(n/2);
    int ang = modpow(3, (mod - 1) / n);
    if(invert) ang = modpow(ang, mod - 2);
    root[0] = 1;
    for(int i = 1; i<n/2; i++) root[i] = (root[i-1]*ang)%mod;
    for (int len = 2; len <= n; len <<= 1)
    {
        int step = n / len;
        for (int i = 0; i<n; i+= len)
        {
            for (int j = 0; j<len/2; j++)
            {
                base u = a[i+j], v = (a[i+j+len/2]*root[step*j])%mod;
                a[i+j] = (u+v)%mod;
                a[i+j+len/2] = (u-v)%mod;
            }
        }
    }
    if (invert)
    {
        for (int i = 0; i<n; i++)
            a[i] = frac(a[i],n);
    }
    for (int i = 0; i<n; i++)
        a[i] = (a[i]+10*mod)%mod;
}

void multiply(const vi &a, const vi &b, vi &res_)
{
    vector <base> fa(all(a)), fb(all(b));
    int n = 1;
    while(n < max(sz(a),sz(b)))
        n <<= 1;
    n <<= 1;
    fa.resize(n); fb.resize(n);
    fft(fa,0), fft(fb,0);
    for (int i = 0; i<n; i++)
        fa[i] = (fa[i]*fb[i]+mod)%mod;
    fft(fa,1);
    res_.resize(n);
    for (int i = 0; i<n; i++)
        res_[i] = (fa[i]+mod)%mod;
}

int ans[606060];


int32_t main()
{
    int n, k;
    precompute();
    usecppio
    cin >> n >> k;
    for (int i = 0; i<n; i++)
    {
        int x;
        cin >> x;
        white[x]++;
    }
    for (int i = 0; i<k; i++)
    {
        int r; cin >> r; red.push_back(r);
    }
    for (int rb:red)
    {
        one.clear(); many.clear();
        res.clear();
        one.resize(303030);
        many.resize(303030);
        int a = 0, b = 0;
        for (int i = 0; i<rb; i++)
        {
            if (!white[i]) continue;
            if (white[i]==1)
                a++;
            else b++;
        }
        for (int i = 0; i<=a; i++)
        {
            int u = binom(a, i);
            int v = modpow(2, i);
            one[i] = (u*v)%mod;
        }

        for (int i = 0; i<=2*b; i++)
            many[i] = binom(2*b, i);

        multiply(one, many, res);
        for (int i = 0; i<=n; i++)
        {
            ans[rb + i + 1] += res[i];
            ans[rb + i + 1] %= mod;
        }
    }
    int q; cin >> q;
    while(q--)
    {
        int Q; cin >> Q;
        cout << ans[Q/2] << '\n';
    }
}