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
	deque<int> dq;
	vector <int> v;
	int n;
	cin >> n;
	for (int i = 0; i<4*n; i++)
	{
		int x;
		cin >> x;
		dq.push_back(x);
	}
	sort(all(dq));
	for (int i = 0; i<n; i++)
	{
		int x1, x2, y1, y2;
		x1 = dq.front();
		dq.pop_front();
		x2 = dq.front();
		dq.pop_front();
		y1 = dq.back();
		dq.pop_back();
		y2 = dq.back();
		dq.pop_back();
		if ((x1 != x2) || (y1 != y2))
		{
			printf("NO\n");
			return;
		}
		else
		{
			v.push_back(x1*y1);
		}
	}
	sort(all(v));
	printf("%s\n",(v[0]==v[n-1]?"YES":"NO"));
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
