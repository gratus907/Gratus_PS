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
struct SegTree
{
    int n;
    vector <int> segtree;
    vector <int> lazy;

    SegTree()
    {
        n = 0;
    }

    SegTree(vector <int> &data)
    {
        n = data.size();
        segtree.resize(4*n);
        lazy.resize(4*n);
        init(data,1,0,n-1);
    }

    int init(vector <int> &data, int node, int l, int r)
    {
        if (l==r)
        {
            segtree[node] = data[l];
            return segtree[node];
        }
        int mid = (l+r)/2;
        int ls = init(data,node*2,l,mid);
        int rs = init(data,node*2+1,mid+1,r);
        segtree[node] = (ls+rs);
        return segtree[node];
    }

    void propagation(int node, int nl, int nr)
    {
        if (lazy[node]!=0)
        {
            segtree[node] += (lazy[node] * (nr-nl+1));
            if (nl != nr)
            {
                lazy[node*2] += lazy[node];
                lazy[node*2+1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void range_upd(int s, int e, int k)
    {
        return range_upd(s,e,k,1,0,n-1);
    }
    void point_upd(int p, int k)
    {
        return range_upd(p, p, k);
    }
    void range_upd(int s, int e, int k, int node, int nl, int nr)
    {
        propagation(node,nl,nr);

        if (nr < s || nl > e)
            return;
        if (s <= nl && nr <= e)
        {
            lazy[node] += k;
            propagation(node,nl,nr);
            return;
        }
        int mid = (nl + nr)/2;
        range_upd(s,e,k,node*2,nl,mid);
        range_upd(s,e,k,node*2+1,mid+1,nr);
        segtree[node] = segtree[node*2] + segtree[node*2+1];
        return;
    }

    int sum(int s, int e)
    {
        return sum(s,e,1,0,n-1);
    }

    int sum(int s, int e, int node, int nl, int nr)
    {
        propagation(node,nl,nr);
        if (nr < s || nl > e)
            return 0;
        if (s <= nl && nr <= e)
        {
            return segtree[node];
        }
        int mid = (nl+nr)/2;
        return (sum(s,e,node*2,nl,mid) + sum(s,e,node*2+1,mid+1,nr));
    }

};

vector <int> arr(101010, 0);
SegTree slope(arr);
SegTree ypos(arr);
int val[101010];
int32_t main()
{
    usecppio
    int n;
    cin >> n;
    for (int i = 1; i<=n; i++)
        cin >> val[i];
    int Q;
    cin >> Q;
    while (Q--)
    {
        int t; cin >> t;
        if (t == 1)
        {
            int l, r; cin >> l >> r;
            slope.range_upd(l, r, 1);
            ypos.range_upd(l, r, -l+1);
        }
        else
        {
            int w; cin >> w;
            int p = slope.sum(w, w);
            int q = ypos.sum(w, w);
            cout << p*w+q+val[w] << '\n';
        }
    }
}