#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;

string str;
int zeros, ones;
int main()
{
	cin >> str;
	int ans = 0;
	int s = str.length();
	for (int i = s-1; i>0; i--)
	{
		int u = s-1-i;
		if (u%2==0)
		{
			ans++;
		}
		if (str[i] == '0')
			zeros++;
		else
			ones++;
	}
	if (ones>0 && str[0] == '1')
	{
		ans += (s%2==1);
	}
	cout << ans;
}
