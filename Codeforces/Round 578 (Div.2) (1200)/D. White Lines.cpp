#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using namespace std::chrono;
using pii = pair<int, int>;

int n, k;
int board[2020][2020];
int matchcol[2020][2020];
int matchrow[2020][2020];
pii row[2020];
pii col[2020];
int rowct[2020];
int colct[2020];
string tmp;

inline int check(int x, int y)
{
	int ct = 0;
	if (matchrow[x-1][y] == -1)
	{
		int ctx = 0;
		for (int i = x; i<=x+k-1; i++)
		{
			if (!rowct[i])
				continue;
			if (row[i].first >= y && row[i].second <= y+k-1)
				ctx++;
		}
		matchrow[x][y] = ctx;
		ct += ctx;
	}
	else
	{
		int ctx = 0;
		ctx += matchrow[x-1][y];
		if (rowct[x-1])
		{
			if (row[x-1].first >= y && row[x-1].second <= y+k-1)
				ctx--;
		}
		if (rowct[x+k-1])
		{
			if (row[x+k-1].first >= y && row[x+k-1].second <= y+k-1)
				ctx++;
		}
		matchrow[x][y] = ctx;
		ct += ctx;
	}
	if (matchcol[x][y-1] == -1)
	{
		int cty = 0;
		for (int i = y; i<=y+k-1; i++)
		{
			if (!colct[i])
				continue;
			if (col[i].first >= x && col[i].second <= x+k-1)
				cty++;
		}
		matchcol[x][y] = cty;
		ct += cty;
	}
	else
	{
		int cty = 0;
		cty += matchcol[x][y-1];
		if (colct[y-1])
		{
			if (col[y-1].first >= x && col[y-1].second <= x+k-1)
				cty--;
		}
		if (colct[y+k-1])
		{
			if (col[y+k-1].first >= x && col[y+k-1].second <= x+k-1)
				cty++;
		}
		matchcol[x][y] = cty;
		ct += cty;
	}
	return ct;
}

int main()
{
	usecppio
	memset(matchrow,-1,sizeof(matchrow));
	memset(matchcol,-1,sizeof(matchcol));
	cin >> n >> k;
	for (int i = 0; i<2020; i++)
	{
		row[i] = {INT_MAX,-1};
		col[i] = {INT_MAX,-1};
	}
	for (int i = 1; i<=n; i++)
	{
		cin >> tmp;
		for (int j = 1; j<=n; j++)
		{
			board[i][j] = (tmp[j-1]=='B'?1:0);
			if (board[i][j])
			{
				col[j].first = min(i,col[j].first);
				col[j].second = max(i,col[j].second);
				row[i].first = min(j,row[i].first);
				row[i].second = max(j,row[i].first);
				rowct[i]++;
				colct[j]++;
			}
		}
	}
	int def = 0;
	for (int i = 1; i<=n; i++)
	{
		if (rowct[i] == 0)
			def++;
		if (colct[i] == 0)
			def++;
	}
	for (int i = 0; i<2020; i++)
	{
		if (rowct[i] > k)
			row[i] = {-1, INT_MAX};
		if (colct[i] > k)
			col[i] = {-1, INT_MAX};
	}
	int ans = 0;
	for (int i = 1; i<=(n-k+1); i++)
	{
		for (int j = 1; j<=(n-k+1); j++)
		{
			ans = max(ans, check(i, j));
		}
	}
	cout << ans+def;
}
