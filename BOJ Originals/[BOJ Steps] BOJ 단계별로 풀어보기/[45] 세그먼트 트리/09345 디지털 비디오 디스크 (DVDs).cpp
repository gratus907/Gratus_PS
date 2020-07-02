#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define int ll
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;
const int mod = 1000000007;
struct Range_Minimum_Tree
{
    int n;
    vector<int> segtree;

    Range_Minimum_Tree(const vector<int> &data)
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
        int lmin = initialize(data, l, mid, node * 2);
        int rmin = initialize(data, mid + 1, r, node * 2 + 1);
        return segtree[node] = min(lmin, rmin);
    }
    int minq(int l, int r, int node, int nodeleft, int noderight)
    {
        if (r < nodeleft || noderight < l)
            return INT_MAX;
        if (l <= nodeleft && noderight <= r)
            return segtree[node];
        int mid = (nodeleft + noderight) / 2;
        return min(minq(l,r,node*2,nodeleft,mid),
                   minq(l,r,node*2+1,mid+1,noderight));
    }
    void update(int left,int right,int node, int change_node ,int diff)
    {
        if (!(left <= change_node &&change_node <= right))
            return;
        if (left == right)
        {
            segtree[node] += diff;
        }
        if (left != right)
        {
            int mid = (left + right) / 2;
            update(left, mid, node * 2, change_node, diff);
            update(mid +1,right, node * 2 +1, change_node, diff);
            segtree[node] = min(segtree[node*2], segtree[node*2+1]);
        }
    }
    void update(int change_node, int diff)
    {
        update(0,n-1,1,change_node,diff);
    }
    void update_to(int change_node, int to)
    {
        int u = minq(change_node, change_node, 1, 0, n-1);
        update(change_node, to-u);
    }
    int Query(int l, int r)
    {
        return minq(l, r, 1, 0, n-1);
    }
};

struct Range_Maximum_Tree
{
    int n;
    vector<int> segtree;

    Range_Maximum_Tree(const vector<int> &data)
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
        int lmax = initialize(data, l, mid, node * 2);
        int rmax = initialize(data, mid + 1, r, node * 2 + 1);
        return segtree[node] = max(lmax, rmax);
    }
    int maxq(int l, int r, int node, int nodeleft, int noderight)
    {
        if (r < nodeleft || noderight < l)
            return 0;
        if (l <= nodeleft && noderight <= r)
            return segtree[node];
        int mid = (nodeleft + noderight) / 2;
        return max(maxq(l,r,node*2,nodeleft,mid),
                   maxq(l,r,node*2+1,mid+1,noderight));
    }
    void update(int left,int right,int node, int change_node ,int diff)
    {
        if (!(left <= change_node &&change_node <= right))
            return;
        if (left == right)
        {
            segtree[node] += diff;
        }
        if (left != right)
        {
            int mid = (left + right) / 2;
            update(left, mid, node * 2, change_node, diff);
            update(mid +1,right, node * 2 +1, change_node, diff);
            segtree[node] = max(segtree[node*2], segtree[node*2+1]);
        }
    }
    void update(int change_node, int diff)
    {
        update(0,n-1,1,change_node,diff);
    }
    void update_to(int change_node, int to)
    {
        int u = maxq(change_node, change_node, 1, 0, n-1);
        update(change_node, to-u);
    }
    int Query(int l, int r)
    {
        return maxq(l, r, 1, 0, n-1);
    }
};

int32_t main()
{
    usecppio
    int T; cin >> T;
    while(T--)
    {
        int n, k; cin >> n >> k;
        vector <int> arr(n);
        for (int i = 0; i<n; i++) arr[i] = i;
        Range_Maximum_Tree MaxT(arr);
        Range_Minimum_Tree MinT(arr);
        while(k--)
        {
            int q, a, b;
            cin >> q >> a >> b;
            if (q == 0)
            {
                int va = MaxT.Query(a, a);
                int vb = MaxT.Query(b, b);
                MaxT.update_to(a, vb);
                MaxT.update_to(b, va);
                MinT.update_to(a, vb);
                MinT.update_to(b, va);
            }
            else
            {
                int maxval = MaxT.Query(a, b);
                int minval = MinT.Query(a, b);
                if (minval == a && maxval == b)
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
        }
    }
}