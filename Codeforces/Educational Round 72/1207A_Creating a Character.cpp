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
int n, m;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int s, in, ex;
		cin >> s >> in >> ex;
		int g = s-in;
		int ans = (ex+g+1)/2;
		cout << min(max(ans,0),ex+1) << '\n';
	}
}