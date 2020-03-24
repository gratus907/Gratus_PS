#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int ll
const bool debug = 0;
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
    n <<= 2;
    fa.resize(n); fb.resize(n);
    fft(fa,0), fft(fb,0);
    for (int i = 0; i<n; i++)
        fa[i] *= fb[i];
    fft(fa,1);
    res.resize(n);
    for (int i = 0; i<n; i++)
        res[i] = int64_t(fa[i].real()+(fa[i].real()>0?0.5:-0.5));
}

vector <int> na, nb, nc;
vector <string> v;
string sa, sb;
deque <char> dq;
int cut = 5;
int val = 1e5;
string build(int x)
{
    string s = to_string(x);
    while(s.length()<cut)
        s = "0"+s;
    return s;
}
int32_t main(int argc, char *argv[])
{
    usecppio
    if (debug)
    {
        sa = string(argv[1]);
        sb = string(argv[2]);
    }
    else 
    {
        cin >> sa >> sb;
    }
    int n = sz(sa), m = sz(sb);
    for (int i = 0; i<n; i++)
    {
        if ((n-i)%5==0 || na.empty())
            na.push_back(sa[i]-'0');
        else 
        {
            na.back()*=10;
            na.back()+=(sa[i]-'0');
        }
    }
    for (int i = 0; i<m; i++)
    {
        if ((m-i)%5==0 || nb.empty())
            nb.push_back(sb[i]-'0');
        else 
        {
            nb.back()*=10;
            nb.back()+=(sb[i]-'0');
        }
    }
    reverse(all(na));
    reverse(all(nb));
    if (debug)
    {
        printf("Print na\n");
        for (auto it:na)
            printf("%lld ",it);
        printf("\nPrint nb\n");
        for (auto it:nb)
            printf("%lld ",it);
        printf("\nPrint nc\n");
    }
    multiply(na, nb, nc);
    for (int i = 0; i<nc.size()-1; i++)
    {
        nc[i+1] += nc[i]/val;
        nc[i] %= val;
    }
    if (nc.back()>=val)
    {
        int t = nc.back()/val;
        nc.back()%=val;
        nc.push_back(val);
    }
    if (debug)
    {
        for (auto it:nc)
            printf("%lld ",it);
        printf("\n");
    }
    for (auto it:nc)
        v.push_back(build(it));
    reverse(all(v));
    for (auto it:v)
        for (auto itt:it)
            dq.push_back(itt);
    while(dq.size()>1 && dq.front()=='0')
        dq.pop_front();
    for (auto it:dq)
        cout << it;
    cout << '\n';
}