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

vector <int> a, b;
int main()
{
	usecppio
	int n, m;
	cin >> n;
	a.resize(n);
	for (int i = 0; i<n; i++)
		cin >> a[i];
	cin >> m;
	b.resize(m);
	for (int i = 0; i<m; i++)
		cin >> b[i];
	sort(all(a));
	sort(all(b));
	cout << a[n-1] << " " << b[m-1] << '\n';
}
