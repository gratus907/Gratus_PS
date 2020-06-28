#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
using pii = pair <int, int>;

struct SEG
{
    int n;
    vector<int> segtree;

    SEG(const vector<int> &data)
    {
        n = data.size();
        segtree.resize(4 * n);
        initialize(data, 0, n - 1, 1);
    }

    int initialize(const vector<int> &data, int l, int r, int node)
    {
        if (l == r)
            return segtree[node] = data[l];
        int mid = (l + r) / 2;
        int ls = initialize(data, l, mid, node * 2);
        int rs = initialize(data, mid + 1, r, node * 2 + 1);
        return segtree[node] = ls+rs;
    }

    int sumq(int l, int r, int node, int nodeleft, int noderight)
    {
        if (r < nodeleft || noderight < l)
            return 0;
        if (l <= nodeleft && noderight <= r)
            return segtree[node];
        int mid = (nodeleft + noderight) / 2;
        return sumq(l,r,node*2,nodeleft,mid)+sumq(l,r,node*2+1,mid+1,noderight);
    }
    int sumq(int l, int r)
    {
        return sumq(l, r, 1, 0, n-1);
    }
    void update(int left,int right,int node, int change_node ,int diff)
    {
        if (!(left <= change_node &&change_node <= right))
            return;
        segtree[node] += diff;
        if (left != right)
        {
            int mid = (left + right) / 2;
            update(left, mid, node * 2, change_node, diff);
            update(mid +1,right, node * 2 +1, change_node, diff);
        }
    }
    void update(int change_node, int diff)
    {
        update(0,n-1,1,change_node,diff);
    }
    void update_to(int change_node, int to)
    {
        int u = sumq(change_node, change_node);
        update(change_node, to-u);
    }
};

vector <int> arr;
int32_t main()
{
    usecppio
    int n, m;
    cin >> n >> m;
    for (int i = 0; i<n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    SEG ST = SEG(arr);
    while(m--)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        if (x > y) swap(x, y);
        x--, y--, a--;
        cout << ST.sumq(x, y) << '\n';
        ST.update_to(a, b);
    }
}