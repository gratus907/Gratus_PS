#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;

bool farm[120][120];
int n, r, c;
int main()
{
	cin >> n >> r >> c;
	for (int i = 1; i<=n; i++)
		for (int j = 1; j<=n; j++)
			farm[i][j] = (((i+j)&1)==((r+c)&1));
	for (int i = 1; i<=n; i++)
	{
		for (int j = 1; j<=n; j++)
			cout << (farm[i][j]?'v':'.');
		cout << '\n';
	}
}