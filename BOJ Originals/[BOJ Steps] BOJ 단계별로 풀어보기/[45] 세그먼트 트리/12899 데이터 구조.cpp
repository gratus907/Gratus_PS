#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MAXN 202020
typedef tree<int,null_type, less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

ordered_set X;
int main()
{
	int n;
	usecppio
	cin >> n;
	while(n--)
	{
		int t, x;
		cin >> t >> x;
		if (t == 1)
			X.insert(x);
		else
		{
			int u = *(X.find_by_order(x-1));
			X.erase(X.upper_bound(u));
			cout << u << '\n';
		}
	}
}
