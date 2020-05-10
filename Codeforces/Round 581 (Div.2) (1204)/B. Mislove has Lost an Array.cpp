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
int n, l, r;
vector <int> maxarr;
vector <int> minarr;
int minsum, maxsum;
int32_t main()
{
	cin >> n >> l >> r;
	for (int i = 0; i<l; i++)
	{
		minarr.push_back((1LL<<i));
	}
	for (int i = l; i<n; i++)
	{
		minarr.push_back((1LL));
	}
	for (int i = 0; i<r; i++)
	{
		maxarr.push_back((1LL<<i));
	}
	for (int i = r; i<n; i++)
	{
		maxarr.push_back((1LL<<(r-1)));
	}
	for (auto it:minarr)
		minsum += it;
	for (auto it:maxarr)
		maxsum += it;
	cout << minsum << ' ' << maxsum;
}
