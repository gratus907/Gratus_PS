#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
using pii = pair <int, int>;
#define int ll
const int mod = 1000000007;
int dp[202020];

int32_t main()
{
	usecppio
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i<=200000; i++)
	{
		dp[i] = dp[i-2] + dp[i-1];
		dp[i] %= mod;
	}
	int t;
	cin >> t;
	for (int i = 0; i<t; i++)
	{
		int n; cin >> n;
		cout << dp[n] << '\n';
	}
}