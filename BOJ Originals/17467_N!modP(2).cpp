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
int P;
int n, sqn;
ll modpow(ll x, ll y, ll p = P)
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
inline int add(int a, int b)
{
    return (a+b)%P;
}
inline int sub(int a, int b)
{
    return (P+a-b)%P;
}
inline int mul(int a, int b)
{
    return (a*b)%P;
}
inline int dv(int a, int b)
{
    return (mul(a,modpow(b,P-2)))%P;
}
int fact[1010100], inv_fact[1010100];
int overone[1010100];
/* FFT Library : Originally Written by Myungwoo *
 * https://blog.myungwoo.kr/54                  *
 * Nonrecursive, Bit-Flipping Trick             *
 * Several Modifications                        */
#define sz(v) ((int)(v).size())
typedef complex<double> base;
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
    double ang = 2*acos(-1)/n*(invert?-1:1);
    for(int i=0;i<n/2;i++)root[i]=base(cos(ang*i), sin(ang*i));
    for (int len = 2; len <= n; len <<= 1)
    {
        int step = n / len;
        for (int i = 0; i<n; i+= len)
        {
            for (int j = 0; j<len/2; j++)
            {
                base u = a[i+j], v = a[i+j+len/2]*root[step*j];
                a[i+j] = u+v;
                a[i+j+len/2] = u-v;
            }
        }
    }
    if (invert)
    {
        for (int i = 0; i<n; i++)
            a[i] /= n;
    }
}

/* FFT polynomial Multiplication with higher precision */
void multiply(const vi &a, const vi &b, vi &res)
{
    vector <base> fa_big, fb_big;
    vector <base> fa_small, fb_small;
    int cut_val = sqrt(P);
    int n = 1;
    while(n < max(sz(a),sz(b)))
        n <<= 1;
    fa_big.resize(n);
    fa_small.resize(n);
    fb_big.resize(n);
    fb_small.resize(n);
    for (int i = 0; i<sz(a); i++)
    {
        fa_big[i] = a[i]/cut_val;
        fa_small[i] = a[i]%cut_val;
    }
    for (int i = 0; i<sz(b); i++)
    {
        fb_big[i] = b[i]/cut_val;
        fb_small[i] = b[i]%cut_val;
    }
    fft(fa_big,0), fft(fb_big,0);
    fft(fa_small, 0), fft(fb_small, 0);
    vector <base> fa_big_2(all(fa_big));
    vector <base> fa_small_2(all(fa_small));
    for (int i = 0; i<n; i++)
    {
        fa_big_2[i] *= fb_big[i];
        fa_big[i] *= fb_small[i];
        fa_small[i] *= fb_small[i];
        fa_small_2[i] *= fb_big[i];
    }
    fft(fa_small,1);
    fft(fa_small_2, 1);
    fft(fa_big, 1);
    fft(fa_big_2, 1);
    res.resize(n);
    for (int i = 0; i<n; i++)
    {
        int ss = (int64_t)round(fa_small[i].real());
        int sb = (int64_t)round(fa_small_2[i].real());
        int bs = (int64_t)round(fa_big[i].real());
        int bb = (int64_t)round(fa_big_2[i].real());
        res[i] = ss;
        res[i] += (((((sb+bs)%P)*cut_val)%P)+P)%P;
        res[i] += (((((bb*cut_val)%P)*cut_val)%P)+P)%P;
        res[i] %= P;
    }
}
vector <int> lagrange_polynomial(vector <int> vals)
{
    int md = vals.size()-1;
    vector <int> pol;
    pol.resize(md+1);
    fill(all(pol), 0);
    for(int i = 0; i<=md; i++)
        pol[i] = mul(vals[i], mul(inv_fact[md-i], inv_fact[i]));
    if (vals.size()%2==0)
        for (int i = 0; i<=md; i+=2)
            pol[i] = sub(0, pol[i]);
    else
        for (int i = 1; i<=md; i+=2)
            pol[i] = sub(0, pol[i]);
    vector<int> inv;
    inv.resize(4*md+2, 0);
    for(int i = 1; i<4*md+2; i++)
        inv[i] = overone[i];
    vector <int> FFTRes;
    multiply(pol,inv,FFTRes);
    vector <int> second;
    second.resize(4*md+2, 0);
    second[md+1] = fact[md+1];
    for(int i = md+2; i<4*md+2; i++)
        second[i] = mul(second[i-1], mul(i, inv[i-md-1]));
    vals.resize(4*md+2);
    for(int i = md+1; i<4*md+2; i++)
        vals[i] = mul(second[i], FFTRes[i]);
    return vals;
}

int32_t main()
{
    auto start = std::chrono::high_resolution_clock::now();
    cin >> n >> P;
    sqn = (int)sqrt(n)-1;
    fact[0] = 1;
    inv_fact[0] = 1;
    for (int i = 1; i<=1010000; i++)
    {
        fact[i] = mul(fact[i-1],i);
    }
    inv_fact[1010000] = modpow(fact[1010000],P-2);
    for (int i = 1010000; i>0; i--)
    {
        overone[i] = mul(fact[i-1],inv_fact[i]);
        inv_fact[i-1] = mul(inv_fact[i], i);
    }
    if (n < 1000000)
    {
        cout << fact[n] << '\n';
        return 0;
    }
    vector<int> poly_bucket = {1, 2};
    while(poly_bucket.size() < sqn)
    {
        vector<int> lag = lagrange_polynomial(poly_bucket);
        vector<int> ret;
        for(int i = 0; (i+1)<lag.size(); i+=2)
            ret.push_back( mul(lag[i], lag[i+1]));
        poly_bucket = ret;
    }
    sqn = poly_bucket.size()-1;
    int cov = n / sqn;
    int ans = 1;
    for(int i = 0; i<cov; i++)
        ans = mul(ans, poly_bucket[i]);
    for(int i = cov*sqn+1; i<=n; i++)
        ans = mul(ans, i);
    cout << ans << '\n';
    auto end = high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( end - start ).count();
}