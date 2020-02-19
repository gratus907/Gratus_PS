#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimine("O3")
using namespace std;
#define int ll
#define ll long long
typedef pair<int, int> pii;

int dp[4][55][2];
int airport[4];
int p;
vector <pii> graph[4][55]; //source, dist
int32_t main()
{
	cin >> p;
	for (int person = 1; person<=p; person++)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 1; i<=n; i++)
		{
			int hotelcost;
			cin >> hotelcost;
			graph[person][i].push_back({i,hotelcost});
		}
		for (int i = 1; i<=m; i++)
		{
			int u, v, cost;
			cin >> u >> v >> cost;
			graph[person][v].push_back({u, cost});
		}
		cin >> airport[person];
	}
	for (int i = 0; i<4; i++)
	{
		for (int j = 0; j<55; j++)
		{
			for (int k = 0; k<2; k++)
			{
				dp[i][j][k] = (ll)3e12;
			}
		}
	}
	dp[1][1][0] = 0;
	dp[2][1][0] = 0;
	dp[3][1][0] = 0;
	int ans = LLONG_MAX;
	for (int time = 1; time <= 125000; time++)
	{
		int oldtime = (time + 1) % 2;
		int newtime = time%2;
		for (int i = 1; i<=p; i++)
		{
			for (int j = 1; j<=50; j++)
			{
				int u = (ll)3e12;
				for (auto it: graph[i][j])
				{
					u = min(u, dp[i][it.first][oldtime] + it.second);
				}
				dp[i][j][newtime] = u;
			}
		}
		int newans = 0;
		for (int i = 1; i<=p; i++)
		{
			newans += dp[i][airport[i]][newtime];
		}
		ans = min(ans, newans);
	}
	cout << ans << '\n';
}
