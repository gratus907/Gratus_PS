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

vector <pii> positive;
vector <pii> negative;
vector <vector <int>> dp;
int n, r;
bool compare(pii &a, pii &b)
{
	return a.first+a.second>b.first+b.second;
}
int main()
{
	usecppio
	cin >> n >> r;
	int donetask = 0;
	for (int i = 0; i<n; i++)
	{
		int need, gain;
		cin >> need >> gain;
		if (gain>=0)
			positive.push_back({need,gain});
		else
			negative.push_back({need,gain});
	}
	sort(all(positive));
	for (auto it:positive)
	{
		if (it.first <= r)
		{
			r += it.second;
			donetask++;
		}
	}
	int ns = negative.size();
	for (int i = 0; i<ns; i++)
	{
		negative[i].first = max(negative[i].first,-negative[i].second);
	}
	sort(all(negative),compare);
	dp.resize(ns+1);
	for (int i = 0; i<=ns; i++)
	{
		dp[i] = vector <int> (r+10, 0);
	}
	dp[0][r] = donetask;
	for (int i = 0; i<ns; i++)
	{
		for (int cur = 0; cur <= r; cur++)
		{
			dp[i+1][cur] = max(dp[i+1][cur], dp[i][cur]);
			if (cur>=negative[i].first)
			{
				dp[i+1][cur+negative[i].second] = max(dp[i+1][cur+negative[i].second],dp[i][cur]+1);
			}
		}
	}
	for (int i = 0; i<=r; i++)
	{
		donetask = max(donetask,dp[ns][i]);
	}
	cout << (donetask==n?"YES":"NO");

}
