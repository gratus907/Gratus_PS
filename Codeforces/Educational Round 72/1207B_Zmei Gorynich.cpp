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
int32_t main()
{
	usecppio
	int t;
	cin >> t;
	while(t--)
	{
		int n, x;
		cin >> n >> x;
		vector <pii> blow;
		int md = 0;
		int mnd = -INF;
		for (int i = 0; i<n; i++)
		{
			int dd, hh;
			cin >> dd >> hh;
			md = max(md, dd);
			mnd = max(mnd, dd-hh);
			blow.push_back({dd,hh});
		}
		if (md >= x)
		{
			cout << 1 << '\n';
			continue;
		}
		if (mnd <= 0)
		{
			cout << -1 << '\n';
			continue;
		}
		int u = 0;
		u += (x-md)/(mnd) + 1 - ((x-md)%mnd==0);
		cout << u+1 << '\n';
	}
}