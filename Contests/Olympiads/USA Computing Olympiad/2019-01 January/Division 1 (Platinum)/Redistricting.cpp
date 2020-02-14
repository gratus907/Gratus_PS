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
#define int ll
int dp[303030];
int cow[303030];
int prefix[303030];
string str;
int n, k;
multiset<int> pval[303030];
multiset<int> dq;
inline void multiset_erase(int x, int setind)
{
	pval[setind].erase(pval[setind].lower_bound(x));
}
int32_t main()
{
	memset(dp,0x7f,sizeof(dp));
	dp[0] = 0;
	cin >> n >> k;
	cin >> str;
	for (int i = 1; i<=n; i++)
		cow[i] = (str[i-1]=='H'?1:-1);
	prefix[1] = cow[1];
	for (int i = 2; i<=n; i++)
		prefix[i] = prefix[i-1] + cow[i];
	pval[0].insert(0);
	dq.insert(0);

	for (int i = 1; i<=n; i++)
	{
		if (i > k)
		{
			multiset_erase(prefix[i-k-1],dp[i-k-1]);
			dq.erase(dq.lower_bound(dp[i-k-1]));
		}
		int mini = *dq.begin();
		dp[i] = mini;
		if (*(pval[mini].begin()) >= prefix[i])
			dp[i]++;
		dq.insert(dp[i]);
		pval[dp[i]].insert(prefix[i]);
	}
	cout << dp[n] << '\n';
}