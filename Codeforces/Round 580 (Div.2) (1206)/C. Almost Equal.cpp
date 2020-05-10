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
#define int ll
vector <int> order;
int32_t main()
{
	int n;
	cin >> n;
	if (n % 2 == 0)
	{
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	order.resize(2*n);
	int curpt = 0;
	for (int i = 1; i<2*n; i+=2)
	{
		order[curpt] = i;
		order[(curpt+n)%(2*n)] = i+1;
		curpt = curpt + (n-1);
		curpt %= (2*n);
	}
	for (auto it:order)
	{
		cout << it << ' ';
	}
}
