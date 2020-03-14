#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx,avx2,fma")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int ll
#define all(x) ((x).begin()),((x).end())
#define eps 1e-7
using pii = pair<int, int>;
struct Range_Minimum_Tree
{
    int n;
    vector<pii> segtree;

    Range_Minimum_Tree(const vector<int> &data)
    {
        n = data.size();
        segtree.resize(4 * n);
        initialize(data, 0, n - 1, 1);
    }

    pii initialize(const vector<int> &data, int l, int r, int node)
    {
        if (l == r)
            return segtree[node] = {data[l],l};
        int mid = (l + r) / 2;
        pii lmin = initialize(data, l, mid, node * 2);
        pii rmin = initialize(data, mid + 1, r, node * 2 + 1);
        return segtree[node] = min(lmin, rmin);
    }

    pii minq(int l, int r, int node, int nodeleft, int noderight)
    {
        if (r < nodeleft || noderight < l)
            return {INT_MAX, INT_MAX};
        if (l <= nodeleft && noderight <= r)
            return segtree[node];
        int mid = (nodeleft + noderight) / 2;
        return min(minq(l,r,node*2,nodeleft,mid),
                   minq(l,r,node*2+1,mid+1,noderight));
    }
    pii minq(int l, int r)
    {
        return minq(l, r, 1, 0, n-1);
    }
    void update(int left,int right,int node, int change_node ,int diff)
    {
        if (!(left <= change_node &&change_node <= right))
            return;
        if (left == right)
            segtree[node].first += diff;
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
        int u = minq(change_node, change_node).first;
        update(change_node, to-u);
    }
};
vector <int> v;
int n;
int32_t main()
{
    usecppio
    cin >> n;
    v.resize(n);
    for (int i = 0; i<n; i++)
        cin >> v[i];
    Range_Minimum_Tree S(v);
    int m;
    cin >> m;
    while(m--)
    {
        int type, a, b; cin >> type >> a >> b;
        if (type == 1)
        {
            a--;
            S.update_to(a,b);
        }
        else
        {
            a--, b--;
            auto u = S.minq(a, b);
            cout << u.second+1 << '\n';
        }
    }
}