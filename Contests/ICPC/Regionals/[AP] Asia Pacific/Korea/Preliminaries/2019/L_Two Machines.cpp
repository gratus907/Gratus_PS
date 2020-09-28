#include <bits/stdc++.h>
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define sz(x) (int)((x).size())
#define gcd(a, b) (__gcd((a), (b)))
#define lcm(a, b) ((a) / __gcd((a), (b)) * (b))
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int dp[255][67600][2];
int a[255], b[255];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i<=n; i++)
	{
		cin >> a[i] >> b[i];
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[1][a[1]][0] = a[1];
	dp[1][b[1]][1] = b[1];
	for (int i = 1; i<=n; i++)
	{
		int u = a[i];
		int v = b[i];
		for (int j = 0; j<=250*250; j++)
		{
			dp[i][j+u][0] = min(dp[i][j+u][0],dp[i-1][j][0]+u);
			dp[i][j+v][1] = min(dp[i][j+v][1],dp[i-1][j][1]+v);
			if (u < j)
				dp[i][j-u][1] = min(dp[i][j-u][1], dp[i-1][j][1]);
			else
				dp[i][u-j][0] = min(dp[i][u-j][0], dp[i-1][j][1]+u-j);
			if (v < j)
				dp[i][j-v][0] = min(dp[i][j-v][0], dp[i-1][j][0]);
			else
				dp[i][v-j][1] = min(dp[i][v-j][1], dp[i-1][j][0]+v-j);
		}
	}
	int ans = INT_MAX;
	for (int i = 0; i<=250*250; i++)
		ans = min(ans, min(dp[n][i][0],dp[n][i][1]));
	cout << ans;
}