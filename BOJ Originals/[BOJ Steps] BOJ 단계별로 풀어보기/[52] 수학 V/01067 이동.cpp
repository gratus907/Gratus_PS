#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC target("popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define sz(x) (int)((x).size())
#define gcd(a, b) (__gcd((a), (b)))
#define lcm(a, b) ((a) / __gcd((a), (b)) * (b))
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;


//FFT Library : NO TOUCH UNLESS EXTREMELY SURE!
#define _USE_MATH_DEFINES
#include <complex>
typedef complex<double> base;
typedef vector <int> vi;
typedef vector <base> vb;
const double PI = 3.1415926535;
void fft(vb &a, bool invert)
{
	int n = sz(a);
	for (int i=1,j=0;i<n;i++)
	{
		int bit = n >> 1;
		for (;j>=bit;bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap(a[i],a[j]);
	}
	for (int len=2;len<=n;len<<=1)
	{
		double ang = 2*PI/len*(invert?-1:1);
		base wlen(cos(ang),sin(ang));
		for (int i=0;i<n;i+=len)
		{
			base w(1);
			for (int j=0;j<len/2;j++)
			{
				base u = a[i+j], v = a[i+j+len/2]*w;
				a[i+j] = u+v;
				a[i+j+len/2] = u-v;
				w *= wlen;
			}
		}
	}
	if (invert)
		for (int i=0;i<n;i++)
			a[i] /= n;

}

void multiply(const vi &a,const vi &b, vi &res)
{
	vb fa(all(a)), fb(all(b));
	int n = 1;
	while (n < max(sz(a),sz(b)))
		n <<= 1;
	fa.resize(n); fb.resize(n);
	fft(fa,false); fft(fb,false);
	for (int i=0;i<n;i++)
		fa[i] *= fb[i];
	fft(fa,true);
	res.resize(n);
	for (int i=0;i<n;i++)
		res[i] = int(fa[i].real()+
					 (fa[i].real()>0?0.5:-0.5));
}


vi x, y, res;

int main()
{
	usecppio
	int n;
	cin >> n;
	x.resize(2*n);
	y.resize(2*n);
	for (int i = 0; i<n; i++)
	{
		int u;
		cin >> u;
		x[i] = u;
		x[i+n] = u;
	}
	for (int i = 0; i<n; i++)
		cin >> y[n-1-i];
	multiply(x, y, res);
	int ans = 0;
	for (int i = n-1; i<2*n; i++)
	{
		ans = max(ans, res[i]);
	}
	printf("\n");
	cout << ans << '\n';
}