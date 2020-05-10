#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimine("O3")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000000007
#define int ll
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector <int> arr;
int n, k;

bool chk(int targ)
{
	int need = 0;
	for (int i = n-1; i>=((n-1)/2); i--)
		if (arr[i] < targ)
			need += (targ-arr[i]);
	return (k >= need);
}

int32_t main()
{
	cin >> n >> k;
	arr.resize(n);
	for (int i = 0; i<n; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(),arr.end());
	int lo = 1, hi = 1e10;
	int mid = (lo + hi)/2;
	while(lo +1 < hi)
	{
		mid = (lo + hi)/2;
		if (chk(mid))
			lo = mid;
		else
			hi = mid;
	}
	cout << lo;
}
