#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;
#define int ll

vector <int> v;
int count_divisor(int x)
{
	int ct = 0;
	for (int i = 1; i*i<=x; i++)
		if (x%i==0)
			ct += (2-(i*i==x));
	return ct;
}

int32_t main()
{
	usecppio
	int n;
	cin >> n;
	v.resize(n);
	cin >> v[0];
	int g = v[0];
	for (int i = 1; i<n; i++)
	{
		cin >> v[i];
		g = __gcd(v[i],g);
	}
	cout << count_divisor(g);
}
