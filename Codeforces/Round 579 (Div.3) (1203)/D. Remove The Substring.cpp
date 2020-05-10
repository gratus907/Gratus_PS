//Can solve both D1 and D2
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

string s, t;
vector <int> tind_front;
vector <int> tind_back;
int ans = 0;
int main()
{
	usecppio
	cin >> s >> t;
	int slen = s.length();
	int tlen = t.length();
	int tpt = 0;
	tind_front.resize(tlen);
	for (int i = 0; (i<slen)&&(tpt<tlen); i++)
	{
		if (s[i] == t[tpt])
		{
			tind_front[tpt] = i;
			tpt++;
		}
	}

	ans = max(ans, tind_front[0]);
	for (int i = 1; i<tlen; i++)
	{
		ans = max(ans, tind_front[i]-tind_front[i-1]-1);
	}
	ans = max(ans, slen-tind_front[tlen-1]-1);

	tind_back.resize(tlen);
	tpt = tlen-1;
	for (int i = slen-1; (i>=0)&&(tpt>=0); i--)
	{
		if (s[i] == t[tpt])
		{
			tind_back[tpt] = i;
			tpt--;
		}
	}
	ans = max(ans, slen-tind_back[tlen-1]-1);
	for (int i = 1; i<tlen; i++)
	{
		ans = max(ans, tind_back[i] - tind_back[i-1] - 1);
	}
	ans = max(ans, tind_back[0]);

	for (int i = 1; i<tlen; i++)
	{
		ans = max(ans, tind_back[i]-tind_front[i-1]-1);
	}

	cout << ans;
}
