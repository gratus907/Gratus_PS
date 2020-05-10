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

void solve()
{
	int n;
	cin >> n;
	vector <int> students(n, 0);
	for (int i = 0; i<n; i++)
	{
		cin >> students[i];
	}
	bool a = 1, b = 1;
	for (int i = 0; i<n-1; i++)
	{
		int u = students[i] + 1;
		if (u > n)
		{
			u -= n;
		}
		if (u != students[i+1])
		{
			a = 0;
			break;
		}
	}
	for (int i = 0; i<n-1; i++)
	{
		int u = students[i]-1;
		if (u == 0)
			u += n;
		if (u != students[i+1])
		{
			b = 0;
			break;
		}
	}
	printf("%s\n",(a||b)?"YES":"NO");
	return;
}

int main()
{
	usecppio
	int q;
	cin >> q;
	while(q--)
	{
		solve();
	}
}
