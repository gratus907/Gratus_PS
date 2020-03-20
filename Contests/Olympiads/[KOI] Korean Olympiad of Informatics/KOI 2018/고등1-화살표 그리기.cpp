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
vector <int> points[101010];
int n;
int32_t main()
{
	usecppio
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		int x, y;
		cin >> x >> y;
		points[y].push_back(x);
	}
	int ans = 0;
	for (int i = 0; i<101010; i++)
	{
		int s = points[i].size();
		if (s<=1)
			continue;
		else
		{
			sort(all(points[i]));
			for (int j = 1; j<s-1; j++)
			{
				ans += (min(points[i][j]-points[i][j-1],points[i][j+1]-points[i][j]));
			}
			ans += points[i][1]-points[i][0];
			ans += points[i][s-1]-points[i][s-2];
		}
	}
	cout << ans;
}