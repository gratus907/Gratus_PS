#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimine("O3")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000000007
#define int ll
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

priority_queue<int> pq;
int arr[101010];
int32_t main()
{
	usecppio
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i<n; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	if (sum%2)
	{
		cout << "NO\n";
		return 0;
	}
	for (int i = 0; i<n; i++)
	{
		if (arr[i] > (sum/2))
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}
