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
int INF = 0x7f7f7f7f;
int resort[150];
int n, m;
int dp[150][150];

int filldp(int day, int coupon)
{
	if (coupon<0)
		return INF;
	if (day > n)
		return 0;
	if (dp[day][coupon]!=INF)
		return dp[day][coupon];
	if (resort[day])
	{
		dp[day][coupon] = filldp(day+1, coupon);
		return dp[day][coupon];
	}
	dp[day][coupon] = min({filldp(day+1,coupon-3),filldp(day+1,coupon)+10000,filldp(day+3,coupon+1)+25000,filldp(day+5,coupon+2)+37000});
	return dp[day][coupon];
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i<m; i++)
	{
		int x;
		cin >> x;
		resort[x] = 1;
	}
	memset(dp,0x7f,sizeof(dp));
	cout << filldp(1, 0);
}