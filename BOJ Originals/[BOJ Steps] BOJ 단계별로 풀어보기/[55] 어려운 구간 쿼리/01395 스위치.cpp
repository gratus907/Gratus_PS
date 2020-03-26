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
            segtree[node] = (nr-nl+1) - segtree[node];
            if (nl != nr)
            {
                lazy[node*2] ^= lazy[node];
                lazy[node*2+1] ^= lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void range_upd(int s, int e)
    {
        return range_upd(s,e,1,0,n-1);
    }

    void range_upd(int s, int e, int node, int nl, int nr)
    {
        propagation(node,nl,nr);

        if (nr < s || nl > e)
            return;
        if (s <= nl && nr <= e)
        {
            lazy[node] ^= 1;
            propagation(node,nl,nr);
            return;
        }
        int mid = (nl + nr)/2;
        range_upd(s,e,node*2,nl,mid);
        range_upd(s,e,node*2+1,mid+1,nr);
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
int n, m;
int32_t main()
{
    usecppio
    cin >> n >> m;
    vector <int> v(n, 0);
    SegTree ST(v);
    for (int i = 0; i<m; i++)
    {
        int o, s, t; cin >> o >> s >> t;
        if (o == 0)
            ST.range_upd(s-1, t-1);
        else
            cout << ST.sum(s-1, t-1) << '\n';
    }
}