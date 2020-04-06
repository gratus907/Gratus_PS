#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

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
        return min(minq(l,r,node*2,nodeleft,mid), minq(l,r,node*2+1,mid+1,noderight));
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
            return INT_MIN;
        if (l <= nodeleft && noderight <= r)
            return segtree[node];
        int mid = (nodeleft + noderight) / 2;
        return max(maxq(l,r,node*2,nodeleft,mid), maxq(l,r,node*2+1,mid+1,noderight));
    }
};

vector <int> arr;
int main()
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
    Range_Minimum_Tree S(arr);
    Range_Maximum_Tree S2(arr);
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        cout << S.minq(a-1,b-1,1,0,n-1) << ' ' << S2.maxq(a-1,b-1,1,0,n-1) << '\n';
    }
}