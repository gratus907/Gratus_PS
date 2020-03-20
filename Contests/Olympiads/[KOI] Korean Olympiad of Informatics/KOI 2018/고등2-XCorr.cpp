#include <bits/stdc++.h>
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
using namespace std;
typedef long long ll;
using pii = pair<int, int>;
#define int ll
vector <int> x, y, xind, yind, ysum;
int n, m, a, b;


int32_t main()
{
	cin >> n;
	x.resize(n);
	xind.resize(n);
	for (int i = 0; i<n; i++)
		cin >> xind[i] >> x[i];
	cin >> m;
	y.resize(m+1);
	yind.resize(m+1);
	ysum.resize(m+1);
	for (int i = 0; i<m; i++)
		cin >> yind[i] >> y[i];
	yind[m] = INT_MAX;
	for (int i = 1; i<=m; i++)
		ysum[i] = ysum[i-1] + y[i-1];
	cin >> a >> b;
	int ans = 0;
	for (int i = 0; i<n; i++)
	{
		int tmp = 0;
		int l = lower_bound(all(yind),xind[i]+a)-yind.begin();
		int r = lower_bound(all(yind),xind[i]+b+1)-yind.begin();
		tmp = (x[i])*(ysum[r]-ysum[l]);
		ans += tmp;
	}
	cout << ans;
}