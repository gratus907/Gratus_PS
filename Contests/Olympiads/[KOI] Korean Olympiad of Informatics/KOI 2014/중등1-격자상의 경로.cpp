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
int nCk(int n, int k)
{
	int res = 1;

	if ( k > n - k )
		k = n - k;

	for (int i = 0; i < k; ++i)
	{
		res *= (n - i);
		res /= (i + 1);
	}
	return res;
}
int32_t main()
{
	int n, m, k;
	cin >> n >> m >> k;
	if (!k)
		cout << nCk(n-1+m-1,m-1);
	else
	{
		int x, y;
		for (int i = 1; i<=n; i++)
			for (int j = 1; j<=m; j++)
				if (k==((i-1)*m+j))
					x = i, y = j;
		cout << nCk(x-1+y-1, y-1)*nCk(n-x+m-y,m-y);
	}
}