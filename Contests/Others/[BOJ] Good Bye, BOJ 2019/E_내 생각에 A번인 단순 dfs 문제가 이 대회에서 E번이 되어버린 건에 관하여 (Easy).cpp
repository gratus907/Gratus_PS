#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
using pii = pair <int, int>;
#define int ll
const int mod = 1000000007;

int rearr[303030];
int tree[303030];
int n, pt;
int ans;
vector <int> visitorder;
vector <int> tmp;
int kadane(vector <int> &arr)
{
	int nn = arr.size();
	int lm = arr[0], gm = arr[0];
	for (int i = 1; i<nn; i++)
	{
		lm = max(arr[i], lm+arr[i]);
		gm = max(gm, lm);
	}
	return gm;
}
void order(int root)
{
	if (root > n/2) visitorder.push_back(root);
	else
	{
		order(root*2);
		visitorder.push_back(root);
		order(root*2+1);
	}
}

void recmax(int lo, int hi)
{
	tmp.clear();
	int locrit = (1 << lo);
	int hicrit = (1 << hi);
	for (int i = 1; i<=n; i++)
		if (i%locrit == 0 && i%hicrit != 0)
			tmp.push_back(rearr[i]);
	ans = max(ans, kadane(tmp));
}
int32_t main()
{
	usecppio
	cin >> n;
	for (int i = 1; i<=n; i++)
		cin >> tree[i];
	order(1);
	for (int i = 1; i<=n; i++)
		rearr[i] = tree[visitorder[i-1]];
	int mlev = 0;
	for (int i = 0; i<30; i++)
	{
		if ((1<<i) == n+1)
		{
			mlev = i; break;
		}
	}
	for (int i = 0; i<mlev; i++)
	{
		for (int j = i+1; j<=mlev; j++)
		{
			recmax(i, j);
		}
	}
	int nmax = -INT_MAX;
	for (int i = 1; i<=n; i++)
		nmax = max(nmax, rearr[i]);
	if (nmax < 0)
	{
		cout << nmax << '\n'; return 0;
	}
	else cout << max(ans, nmax) << '\n';
}