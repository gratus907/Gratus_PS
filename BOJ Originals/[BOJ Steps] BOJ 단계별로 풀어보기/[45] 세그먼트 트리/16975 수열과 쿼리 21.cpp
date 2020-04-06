#include <bits/stdc++.h>
#define int ll
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#define bigprime (int)1e9+7
#define verybigprime 29996224275833LL
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

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

    void print()
    {
        for (int i = 0; i<4*n; i++)
        {
            cout << segtree[i] << ' ';
        }
        cout << '\n';
    }
    void printlazy()
    {
        for (int i = 0; i<4*n; i++)
        {
            cout << lazy[i] << ' ';
        }
        cout << '\n';
    }

};

SegTree ST;
vector <int> dt;
int32_t main()
{
    usecppio
    int n, m, k;
    cin >> n;
    for (int i = 0; i<n; i++)
    {
        int x;
        cin >> x;
        dt.push_back(x);
    }
    ST = SegTree(dt);
    //ST.print();
    cin >> m;
    for (int i = 0; i<m; i++)
    {
        int a;
        cin >> a;
        if (a==1)
        {
            int b,c,d;
            cin >> b >> c >> d;
            ST.range_upd(b-1,c-1,d);
            //ST.printlazy();
        }
        else
        {
            int b;
            cin >> b;
            cout << ST.sum(b-1,b-1) << '\n';
        }
        //ST.print();
    }
}