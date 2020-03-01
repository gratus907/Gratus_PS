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
const int MOD = 1000000007;

ll modpow(ll x, ll y, ll p = MOD)
{
	ll res = 1;
	x = x % p;
	while (y > 0)
	{
		if (y & 1)
			res = (res*x) % p;
		y = y>>1;
		x = (x*x) % p;
	}
	return res;
}


int n, m, k;
vector <pii> words;
int occ[26];
int sentence[5050];
int combi[5050];
int32_t main()
{
	cin >> n >> m >> k;
	for (int i = 0; i<n; i++)
	{
		int s, c;
		cin >> s >> c;
		words.push_back({c, s});
	}
	for (int i = 0; i<m; i++)
	{
		char x;
		cin >> x;
		occ[x-'A']++;
	}
	sentence[0] = 1;
	for (int i = 1; i<=5000; i++)
		for (auto it:words)
			if (i >= it.second)
				sentence[i] = (sentence[i] + sentence[i-it.second])%MOD;
	combi[0] = sentence[k];
	for (auto it:words)
		if (k >= it.second)
			combi[it.first] = (combi[it.first] += sentence[k-it.second])%MOD;
	int ans = 1;
	for (int i = 0; i<26; i++)
	{
		int t = 0;
		if (occ[i])
		{
			for (int j = 1; j<=5000; j++)
			{
				if (combi[j] > 0)
				{
					t += modpow(combi[j], occ[i]);
					t %= MOD;
				}
			}
			ans *= t;
			ans %= MOD;
		}
	}
	cout << ans << '\n';
}