#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimine("O3")
using namespace std;
#define int ll
#define ll long long
typedef pair<int, int> pii;
int x_L[25050];
int y_L[25050];
int x_U[25050];
int y_U[25050];

bool dec_L, dec_U;
bool crossed[50550];
int ycord_L[50550];
int ycord_U[50550];
int sz[50550];
int32_t main()
{
	int n, m;
	cin >> n >> m;
	x_L[n + 1] = 50001;
	x_U[m + 1] = 50001;
	for (int i = 0; i <= (2 * n); i++)
	{
		int t;
		cin >> t;
		if (i % 2)
			x_L[i / 2 + 1] = t;
		else
			y_L[i / 2] = t;
	}
	for (int i = 1; i <= n + 1; i++)
	{
		for (int x = x_L[i - 1]; x < x_L[i]; x++)
		{
			ycord_L[x] = y_L[i - 1];
		}
	}
	for (int i = 0; i <= (2 * m); i++)
	{
		int t;
		cin >> t;
		if (i % 2)
			x_U[i / 2 + 1] = t;
		else
			y_U[i / 2] = t;
	}
	for (int i = 1; i <= m + 1; i++)
	{
		for (int x = x_U[i - 1]; x < x_U[i]; x++)
		{
			ycord_U[x] = y_U[i - 1];
		}
	}

	if (y_L[0] > y_L[1])
		dec_L = true;
	if (y_U[0] > y_U[1])
		dec_U = true;

	if (dec_L xor dec_U)
	{
		cout << "0 0" << '\n';
		return 0;
	}

	int start = 50000, end = 0;


	for (int i = 0; i<=50000; i++)
	{
		crossed[i] = (ycord_U[i] > ycord_L[i]);
	}
	for (int i = 1; i<=50000; i++)
	{
		if (crossed[i] != crossed[i-1])
		{
			start = min(start,i);
			end = max(end, i);
		}
	}
	bool newcrossed = (y_U[0] > y_L[0]);
	if (crossed[0]!=newcrossed)
	{
		start = min(start,0LL);
		end = max(end, 0LL);
	}
	int ans = 0;
	int ct = 0;
	for (int i = start; i<end; i++)
	{
		if (ycord_L[i] < ycord_U[i])
			sz[i] = (ycord_U[i] - ycord_L[i]);
	}
	for (int i = start; i<end; i++)
	{
		ans += sz[i];
		if (sz[i] && (!sz[i-1]))
			ct++;
	}
	cout << ct <<' ' << ans << '\n';

}
