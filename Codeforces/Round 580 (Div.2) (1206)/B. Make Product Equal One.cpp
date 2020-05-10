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
int zeros;
int need;
vector <int> pos, neg;
int32_t main()
{
	usecppio
	int n;
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		int x;
		cin >> x;
		if (x > 0)
			pos.push_back(x);
		else if (x < 0)
			neg.push_back(x);
		else zeros++;
	}
	for (auto it:pos)
	{
		need += (it-1);
	}
	for (auto it:neg)
	{
		need += (-1-it);
	}
	if (zeros)
		need += zeros;
	else
	{
		if (neg.size() % 2 == 1)
		{
			need += 2;
		}
	}
	cout << need;
}
