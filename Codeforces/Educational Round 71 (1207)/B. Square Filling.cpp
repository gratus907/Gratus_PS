#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 987654321
using namespace std;
using pii = pair<int, int>;
#define MAXN 56
bool mustmark[MAXN][MAXN];
int A[MAXN][MAXN];
int B[MAXN][MAXN];
int n, m;
vector <pii> moves;

bool capable(int x, int y)
{
	bool ok = true;
	ok &= A[x][y];
	ok &= A[x][y+1];
	ok &= A[x+1][y];
	ok &= A[x+1][y+1];
	return ok;
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i<=n; i++)
	{
		for (int j = 1; j<=m; j++)
		{
			cin >> A[i][j];
			if (A[i][j])
			{
				mustmark[i][j] = true;
			}
		}
	}
	for (int i = 1; i<=n; i++)
	{
		for (int j = 1; j<=m; j++)
		{
			if (capable(i, j))
			{
				moves.push_back({i,j});
				mustmark[i][j] = 0;
				mustmark[i][j+1] = 0;
				mustmark[i+1][j] = 0;
				mustmark[i+1][j+1] = 0;
			}
			else
			{
				if (mustmark[i][j])
				{
					cout << -1;
					return 0;
				}
				else continue;
			}
		}
	}
	bool done = false;
	for (int i = 1; i<=n; i++)
	{
		for (int j = 1; j<=m; j++)
		{
			done |= mustmark[i][j];
		}
	}
	done = !done;
	if (done)
	{
		cout << moves.size() << '\n';
		for (auto it:moves)
		{
			cout << it.first << ' ' << it.second << '\n';
		}
	}
	else
	{
		cout << -1;
		return 0;
	}
}
