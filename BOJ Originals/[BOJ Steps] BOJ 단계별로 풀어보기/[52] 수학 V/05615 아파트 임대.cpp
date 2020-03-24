#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define all(x) ((x).begin()),((x).end())
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimization ("unroll-loops")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using pii = pair<int, int>;

#define int ll
vector<int> alist ={2, 7, 61};
inline int mulmod(int x, int y, int m)
{
	return (x * y % m);
}

int powmod(int x, int y, int m)
{
	x %= m;
	int r = 1;
	while (y > 0)
	{
		if (y % 2 == 1)
			r = mulmod(r, x, m);
		x = mulmod(x, x, m);
		y /= 2;
	}
	return r;
}
inline bool miller_rabin(int n, int a)
{
	int d = n - 1;
	while (d % 2 == 0)
	{
		if (powmod(a, d, n) == n-1)
			return true;
		d /= 2;
	}
	int tmp = powmod(a, d, n);
	return tmp == n-1 || tmp == 1;
}

bool is_prime(int n)
{
	if (n <= 1)
		return false;
	if (n <= 100000LL)
	{
		for (int i = 2; i*i <= n; i++)
			if (n % i == 0)
				return false;
		return true;
	}
	for (int a : alist)
		if (!miller_rabin(n, a))
			return false;
	return true;
}
ll t, c=0;
int32_t main()
{
	usecppio
	cin >> t;
	while(t--)
	{
		ll s;
		cin >> s;
		int u = 2*s+1;
		if (is_prime(u)) c++;
	}
	cout << c;
}