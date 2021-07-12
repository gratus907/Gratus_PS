#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int ll
using namespace std;
using pii = pair<int, int>;
int INF = 1e9;
const int N = 101010;
struct element
{
    int ls = -INF, rs = -INF, s = -INF, ms = -INF;
};
struct SEG
{
    int n;
    vector <element> segtree;
    void init()
    {
        segtree.clear();
        segtree.resize(4*n);
    }
    element agg(element a, element b) {
        element e;
        if (a.s <= -INF)
            e.s = b.s;
        else if (b.s <= -INF)
            e.s = a.s;
        else
            e.s = a.s + b.s;
        e.ls = max(a.ls, a.s + b.ls);
        e.rs = max(b.rs, a.rs+b.s);
        e.ms = max(max(a.ms, b.ms),max(e.ls, e.rs));
        e.ms = max(e.ms, a.rs+b.ls);
        return e;
    }
    element query(int l, int r, int node, int nodeleft, int noderight)
    {
        if (r < nodeleft || noderight < l)
            return {-INF, -INF, -INF, -INF};
        if (l <= nodeleft && noderight <= r)
            return segtree[node];
        int mid = (nodeleft + noderight) / 2;
        return agg(query(l,r,node*2,nodeleft,mid),query(l,r,node*2+1,mid+1,noderight));
    }
    element query(int l, int r)
    {
        return query(l, r, 1, 0, n-1);
    }
    void update(int left, int right, int node, int change_node ,int diff)
    {
        if (!(left <= change_node &&change_node <= right))
            return;
        if (left == right && left == change_node)
        {
            segtree[node].ls = diff;
            segtree[node].rs = diff;
            segtree[node].ms = diff;
            segtree[node].s = diff;
        }
        else
        {
            int mid = (left + right) / 2;
            update(left, mid, node * 2, change_node, diff);
            update(mid +1,right, node * 2 +1, change_node, diff);
            segtree[node] = agg(segtree[node*2], segtree[node*2+1]);
        }
    }
    void update(int change_node, int diff)
    {
        update(0,n-1,1,change_node,diff);
    }
};

SEG S;
int32_t main() {
    usecppio
    int n; cin >> n;
    S.n = n; S.init();
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        S.update(i, x);
    }
    int m; cin >> m;
    while (m--) {
        int l, r; cin >> l >> r; l--; r--;
        cout << S.query(l, r).ms << '\n';
    }
}