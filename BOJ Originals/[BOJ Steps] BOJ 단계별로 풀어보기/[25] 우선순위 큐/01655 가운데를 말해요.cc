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

priority_queue<int> small;
priority_queue<int, vector <int>, greater<int>> big;
int main()
{
	usecppio
	int n;
	cin >> n;
	for (int i = 1; i<=n; i++)
	{
		int x;
		cin >> x;
		small.push(x);
		if (!(i%2))
		{
			big.push(small.top());
			small.pop();
		}
		while(!big.empty() && !small.empty() && (big.top()<small.top()))
		{
			int u = small.top();
			int v = big.top();
			//printf("Change %d %d\n",u,v);
			small.pop();
			big.pop();
			small.push(v);
			big.push(u);
		}
		cout << small.top() << '\n';
	}
}