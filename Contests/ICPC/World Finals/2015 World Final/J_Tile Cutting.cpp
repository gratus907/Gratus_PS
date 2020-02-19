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
#define PI acos(-1.0)
using pii = pair<int, int>;

#define sz(v) ((int)(v).size())
typedef complex<double> base;
typedef vector <int> vi;
typedef vector <base> vb;
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
    for (int len = 2; len <= n; len <<= 1)
    {
        double ang = 2*PI/len*(invert?-1:1);
        base wlen (cos(ang),sin(ang));
        for (int i = 0; i<n; i+= len)
        {
            base w(1);
            for (int j = 0; j<len/2; j++)
            {
                base u = a[i+j], v = a[i+j+len/2]*w;
                a[i+j] = u+v;
                a[i+j+len/2] = u-v;
                w *= wlen;
            }
        }
    }
    if (invert)
    {
        for (int i = 0; i<n; i++)
            a[i] /= n;
    }
}

void multiply(const vi &a, const vi &b, vi &res)
{
    vector <base> fa(all(a)), fb(all(b));
    int n = 1;
    while(n < max(sz(a),sz(b)))
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
vector <int> v(5005050,0), v2;
vector <int> res;

int32_t main()
{
    for (int i = 1; i<505050; i++)
        for (int j = i; j<505050; j+=i)
            v[j]++;
    v2 = v;
    multiply(v,v2,res);
    int n;
    cin >> n;
    while(n--)
    {
        int lo, hi;
        cin >> lo >> hi;
        int maxind = max_element(res.begin()+lo, res.begin()+hi+1)-res.begin();
        cout << maxind << ' ' << res[maxind] << '\n';
    }
}#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define int ll
#define PI acos(-1.0)
using pii = pair<int, int>;

#define sz(v) ((int)(v).size())
typedef complex<double> base;
typedef vector <int> vi;
typedef vector <base> vb;
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
    for (int len = 2; len <= n; len <<= 1)
    {
        double ang = 2*PI/len*(invert?-1:1);
        base wlen (cos(ang),sin(ang));
        for (int i = 0; i<n; i+= len)
        {
            base w(1);
            for (int j = 0; j<len/2; j++)
            {
                base u = a[i+j], v = a[i+j+len/2]*w;
                a[i+j] = u+v;
                a[i+j+len/2] = u-v;
                w *= wlen;
            }
        }
    }
    if (invert)
    {
        for (int i = 0; i<n; i++)
            a[i] /= n;
    }
}

void multiply(const vi &a, const vi &b, vi &res)
{
    vector <base> fa(all(a)), fb(all(b));
    int n = 1;
    while(n < max(sz(a),sz(b)))
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
vector <int> v(1005050,0), v2;
vector <int> res;

int32_t main()
{
    for (int i = 1; i<505050; i++)
        for (int j = i; j<505050; j+=i)
            v[j]++;
    v2 = v;
    multiply(v,v2,res);
    int n;
    cin >> n;
    while(n--)
    {
        int lo, hi;
        cin >> lo >> hi;
        int maxind = max_element(res.begin()+lo, res.begin()+hi+1)-res.begin();
        cout << maxind << ' ' << res[maxind] << '\n';
    }
}