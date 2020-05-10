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

int main()
{
	usecppio
	int t;
	cin >> t;
	while(t--)
	{
		int b, p, f, h, c;
		cin >> b >> p >> f;
		cin >> h >> c;
		b /= 2;
		if (h >= c)
		{
			int x = min(b, p);
			b -= x;
			int y = min(b, f);
			b -= y;
			cout << x *h + y*c << '\n';
		}
		else
		{
			int y = min(b, f);
			b -= y;
			int x = min(b, p);
			b -= x;
			cout << x*h + y*c << '\n';
		}
	}
}
