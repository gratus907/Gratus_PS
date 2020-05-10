#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 987654321
using namespace std;
using pii = pair<int, int>;
#define int ll

void solve()
{
	int n, a, b;
	string str;
	vector <pii> v;
	vector <int> gap;
	cin >> n >> a >> b;
	cin >> str;
	int cost = a*n + b*n + b;
	int l = 0, r = 0;
	for (int i = 0; i<n; i++)
	{
		if (str[i] == '0')
		{
			if (l != r)
				v.push_back({l, r-1});
			l = i+1, r = i+1;
		}
		else
			r++;
	}
	int vs = v.size();
	int bp = vs;
	for (int i = 1; i<vs; i++)
	{
		if (v[i].first-v[i-1].second>2)
			gap.push_back(v[i].first-v[i-1].second-2);
		else
			bp--;
	}
	for (auto it:gap)
	{
		if (it*b <= 2*a)
		{
			cost += (it*b);
			bp--;
		}
	}
	for (auto it:v)
		cost += ((b)*(it.second-it.first+2));
	cost += (a*2*(bp));
	cout << cost << '\n';
}
int32_t main()
{
	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
}
