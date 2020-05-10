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

char str[202020];
vector <int> ind;
void solve()
{
	int ct = 0;
	ind.clear();
	scanf("%s",str);
	int n = strlen(str);
	ind.push_back(-1);
	for (int i = 0; i<n; i++)
	{
		if (str[i] == '1')
			ind.push_back(i);
	}
	int u = ind.size();
	for (int i = 1; i<u; i++)
	{
		int r = ind[i]-ind[i-1]-1;
		int cur = 0;
		for (int j = 0; j<20; j++)
		{
			if (ind[i]+j >= n)
				continue;
			else
			{
				cur *= 2;
				cur += (str[ind[i]+j]-'0');
			}
			if (cur <= (1+j+r))
				ct++;
		}
	}
	printf("%d\n",ct);
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
}