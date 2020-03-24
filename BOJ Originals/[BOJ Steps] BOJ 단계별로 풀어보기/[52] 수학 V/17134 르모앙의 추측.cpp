#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;

#define crit 1010101
bool is_composite[crit];
vector <int> primes;
void prime_sieve()
{
    is_composite[1] = true;
    is_composite[2] = false;
    for (int i = 4; i<crit; i+=2)
        is_composite[i] = true;
    for (int i = 3; i<crit; i+=2)
    {
        if (!is_composite[i])
        {
            primes.push_back(i);
            for (int j = 2*i; j<crit; j+=i)
                is_composite[j] = true;
        }
    }
}

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

/* FFT polynomial Multiplication with less precision */
void multiply(const vi &a, const vi &b, vi &res)
{
    vector <base> fa(all(a)), fb(all(b));
    int n = 1;
    while(n < max(sz(a),sz(b)))
        n <<= 1;
    n <<= 1;
    fa.resize(n); fb.resize(n);
    fft(fa,0), fft(fb,0);
    for (int i = 0; i<n; i++)
        fa[i] *= fb[i];
    fft(fa,1);
    res.resize(n);
    for (int i = 0; i<n; i++)
        res[i] = int64_t(fa[i].real()+(fa[i].real()>0?0.5:-0.5));
}

vi v1(1000001, 0), v2(1000001,0), res;
int32_t main()
{
    usecppio
    int T;
    cin >> T;
    prime_sieve();
    for (auto it:primes)
    {
        if (it <= 1000000)
            v1[it] = 1;
        if (it*2 <= 1000000)
            v2[it*2] = 1;
    }
    v2[4] = 1;
    multiply(v1, v2, res);
    while(T--)
    {
        int u;
        cin >> u;
        cout << res[u] << '\n';
    }
}