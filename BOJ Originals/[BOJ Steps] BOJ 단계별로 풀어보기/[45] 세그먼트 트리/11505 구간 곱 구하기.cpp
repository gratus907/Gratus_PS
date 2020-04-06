#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using pii = pair<int, int>;
const ll mod = 1000000007;
#define int ll
struct SegTree
{
	int n;
	vector<int> segtree;

	SegTree(const vector<int> &data)
	{
		n = data.size();
		segtree.resize(4 * n);
		initialize(data, 0, n - 1, 1);
	}
	SegTree()
	{

	}
	int initialize(const vector<int> &data, int l, int r, int node)
	{
		if (l == r)
			return segtree[node] = data[l];
		int mid = (l + r) / 2;
		int left = initialize(data, l, mid, node * 2);
		int right = initialize(data, mid + 1, r, node * 2 + 1);
		return segtree[node] = (left * right) % mod;
	}

	int query(int l, int r, int node, int nodeleft, int noderight)
	{
		if (r < nodeleft || noderight < l)
			return 1;
		if (l <= nodeleft && noderight <= r)
			return segtree[node];
		int mid = (nodeleft + noderight) / 2;
		return (query(l,r,node*2,nodeleft,mid)*query(l,r,node*2+1,mid+1,noderight)) % mod;
	}

	ll update(ll pos, ll val, ll node, ll l, ll r)
	{
		if (r < pos || pos < l)
			return segtree[node];
		if (l == r)
			return segtree[node] = val;
		ll mid = (l+r)/2;
		return segtree[node] = (update(pos, val, node * 2, l, mid)*update(pos, val, node * 2 + 1, mid + 1, r)) % mod;
	}

};

vector <int> v;
int n, m, k;
SegTree Seg;
int32_t main()
{
	usecppio
	cin >> n >> m >> k;
	v.resize(n);
	for (int i = 0; i<n; i++)
		cin >> v[i];
	Seg = SegTree(v);
	for (int i = 0; i<(m+k); i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
			Seg.update(b, c, 1, 1, n);
		else
			cout << Seg.query(b, c, 1, 1, n) << '\n';
	}
}