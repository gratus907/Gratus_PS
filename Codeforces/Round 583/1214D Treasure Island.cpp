#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using pii = pair<int, int>;
vector <vector <bool>> field;
vector <vector <bool>> ok;
int n, m;
int reachable[1010100];
char str[1010100];
int main()
{
	scanf("%d %d",&n,&m);
	int mmd = m+n-2;
	field.resize(n+5);
	ok.resize(n+5);
	for (int i = 0; i<n+5; i++)
	{
		field[i].resize(m+5, 0);
		ok[i].resize(m+5, 0);
	}
	for (int i = 1; i<=n; i++)
	{
		scanf("%s",str);
		for (int j = 1; j<=m; j++)
			field[i][j] = (str[j-1] == '.');
	}
	ok[1][1] = true;
	for (int i = 1; i<=n; i++)
	{
		for (int j = 1; j<=m; j++)
		{
			if (i == 1 && j == 1)
				continue;
			ok[i][j] = ((ok[i-1][j]||ok[i][j-1]) && field[i][j]);
		}
	}
	for (int i = n; i>=1; i--)
	{
		for (int j = m; j>=1; j--)
		{
			if (i == n && j == m)
				continue;
			ok[i][j] = ok[i][j] && ((ok[i+1][j]||ok[i][j+1]) &&field[i][j]);
			if (ok[i][j])
				reachable[i+j-2]++;
		}
	}
	if (ok[n][m]==0)
	{
		printf("0\n");
		return 0;
	}
	for (int i = 1; i<mmd; i++)
	{
		if (reachable[i]==0)
		{
			printf("0\n");
			return 0;
		}
	}
	for (int i = 1; i<mmd; i++)
	{
		if (reachable[i]==1)
		{
			printf("1\n");
			return 0;
		}
	}
	printf("2\n");
	return 0;
}