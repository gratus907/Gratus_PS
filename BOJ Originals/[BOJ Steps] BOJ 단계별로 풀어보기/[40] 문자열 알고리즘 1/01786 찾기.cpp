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

string T, P;
vector<int> getPi(string p)
{
	int j = 0;
	int plen = p.length();
	vector<int> pi;
	pi.resize(plen);
	for(int i = 1; i< plen; i++)
	{
		while((j > 0) && (p[i] !=  p[j]))
			j = pi[j-1];
		if(p[i] == p[j])
		{
			j++;
			pi[i] = j;
		}
	}
	return pi;
}
vector <int> kmp(string s, string p)
{
	vector<int> ans;
	auto pi = getPi(p);
	int slen = s.length(), plen = p.length(), j = 0;
	for(int i = 0 ; i < slen ; i++)
	{
		while(j>0 && s[i] != p[j])
			j = pi[j-1];
		if(s[i] == p[j])
		{
			if(j==plen-1)
			{
				ans.push_back(i-plen+1);
				j = pi[j];
			}
			else
				j++;
		}
	}
	return ans;
}

int main()
{
	usecppio
	getline(cin, T);
	getline(cin, P);
	vector <int> ans = kmp(T,P);
	cout << ans.size() << '\n';
	for (auto it:ans)
	{
		cout << it+1 << ' ';
	}
}