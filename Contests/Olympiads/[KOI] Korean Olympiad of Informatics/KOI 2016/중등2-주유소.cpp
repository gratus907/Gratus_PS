#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
ll price[101010];
ll dist[101010];
ll next_small[101010];
ll total;
int main()
{
	cin >> n;
	for (int i = 1; i<n; i++)
	{
		ll x;
		cin >> x;
		dist[i] = dist[i-1] + x;
	}
	dist[n] = dist[n-1];
	for (int i = 0; i<n; i++)
		cin >> price[i];
	int l = 0, r = 0;
	while(l < n)
	{
		while(price[l] <= price[r])
			r++;
		for (int i = l; i<r; i++)
			next_small[i] = r;
		l = r;
	}
	for (int i = 0; i<n;)
	{
		total += (dist[next_small[i]]-dist[i])*price[i];
		i = next_small[i];
	}
	cout << total;
}
