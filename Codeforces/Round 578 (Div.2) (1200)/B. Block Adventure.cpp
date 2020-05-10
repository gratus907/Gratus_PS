#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimization ("unroll-loops")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using namespace std::chrono;
using pii = pair<int, int>;
#define int ll
int n, m, k;
int h[120];
int32_t main()
{
	usecppio
	int tc;
	cin >> tc;
	while(tc--)
	{
		bool flag = true;
		cin >> n >> m >> k;
		memset(h,0,sizeof(h));
		for (int i = 1; i<=n; i++)
		{
			cin >> h[i];
		}
		for (int i = 1; i<n; i++)
		{
			int u = max(h[i+1]-k,0LL);
			if (u <= h[i])
			{
				m += (h[i]-u);
				h[i] = u;
			}
			else
			{
				if (h[i]+m >= u)
				{
					m -= (u-h[i]);
					h[i] = u;
				}
				else
				{
					flag = 0;
					break;
				}
			}
		}
		cout << (flag?"YES\n":"NO\n");
	}
}
