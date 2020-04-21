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

int mobius[1010100];
int count_nonsquarefree(int N)
{
	int ans = 0;
	for (int i = 1; i*i<=N; i++)
		ans += (mobius[i]*(N/(i*i)));
	return N-ans;
}

int32_t main()
{
	for (int i = 1; i <= 1000000; i++)
		mobius[i] = 1;
	for (int i = 2; i*i <= 1000000; i++)
	{
		if (mobius[i] == 1)
		{
			for (int j = i; j <= 1000000; j += i)
				mobius[j] *= -i;
			for (int j = i * i; j <= 1000000; j += i * i)
				mobius[j] = 0;
		}
	}
	for (int i = 2; i <= 1000000; i++)
	{
		if (mobius[i] == i)
			mobius[i] = 1;
		else if (mobius[i] == -i)
			mobius[i] = -1;
		else if (mobius[i] < 0)
			mobius[i] = 1;
		else if (mobius[i] > 0)
			mobius[i] = -1;
	}
	int k;
	cin >> k;
	int lo = 0, hi = 1e12;
	while (lo + 1 < hi)
	{
		int mid = (lo + hi) / 2;
		if (count_nonsquarefree(mid)<k)
			lo = mid;
		else hi = mid;
	}
	cout << hi << '\n';
}