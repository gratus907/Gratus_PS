#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimine("O3")
#define all(x) (x).begin(),(x).end()
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
	string x, y;
	cin >> x >> y;
	int xl = x.length();
	int yl = y.length();
	int fi = 0;
	for (int i = yl-1; i>=0; i--)
	{
		if (y[i] == '1')
		{
			fi = yl-1-i;
			break;
		}
	}
	for (int ans = 0; ans < xl; ans++)
	{
		if (x[xl-1-(ans+fi)]=='1')
		{
			cout << ans << '\n';
			break;
		}
	}
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		solve();
	}
}
