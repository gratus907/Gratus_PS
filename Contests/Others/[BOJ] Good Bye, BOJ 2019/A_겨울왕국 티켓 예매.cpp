#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
using pii = pair <int, int>;

int solve()
{
	int m, n;
	cin >> m >> n;
	int x = 'l'-'a';
	if (m+'a'-1 < 'l' || n < 4)
		return -1;
	else return (x*n+4);
}
int32_t main()
{
	int t;
	cin >> t;
	while(t--)
		cout << solve() << '\n';
}