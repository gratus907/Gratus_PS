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

vector <int> boxers;
vector <int> init;
int n;
int main()
{
	usecppio
	cin >> n;
	init.resize(n);
	boxers.push_back(0);
	for (int i = 0; i<n; i++)
		cin >> init[i];
	sort(all(init));

	for (auto it:init)
	{
		if (it-1 > boxers.back())
			boxers.push_back(it-1);
		else if (it > boxers.back())
			boxers.push_back(it);
		else if (it+1 > boxers.back())
			boxers.push_back(it+1);
		else
			continue;
	}

	cout << boxers.size()-1;
}
