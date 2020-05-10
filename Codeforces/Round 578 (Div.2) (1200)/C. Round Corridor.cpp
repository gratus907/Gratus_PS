#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimization ("unroll-loops")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using namespace std::chrono;
using pii = pair<int, int>;
#define int ll
int n, m, g, q;
int32_t main()
{
	usecppio
	cin >> n >> m >> q;
	g = __gcd(m,n);
	int u = n/g;
	int v = m/g;
	while(q--)
	{
		int sx,sy,ex,ey;
		int a, b;
		cin >> sx >> sy >> ex >> ey;
		sy--;
		ey--;
		a = (sx==1)?(sy/u):(sy/v);
		b = (ex==1)?(ey/u):(ey/v);
		cout << (a==b?"YES\n":"NO\n");
	}
}
 
