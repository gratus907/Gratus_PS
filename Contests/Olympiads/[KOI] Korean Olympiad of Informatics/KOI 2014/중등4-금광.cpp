#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
#define int ll
using pii = pair <int, int>;
#define INF 0x7f7f7f7f
const int MX = 3030;
int n;
struct mine
{
    int x, y;
    int val;
};
vector <mine> mines;
void coordinate_compression()
{
    vector <int> v;
    sort(all(mines), [](auto &a, auto &b) { return a.x < b.x; });
    for (auto it:mines) v.push_back(it.x);
    v.erase(unique(all(v)),v.end());
    for (auto &it:mines)
        it.x = lower_bound(all(v),it.x)-v.begin();
    v.clear();
    sort(all(mines), [](auto &a, auto &b) { return a.y < b.y; });
    for (auto it:mines) v.push_back(it.y);
    v.erase(unique(all(v)),v.end());
    for (auto &it:mines)
        it.y = lower_bound(all(v),it.y)-v.begin();
}

struct element
{
    int ls = 0, rs = 0, s = 0, ms = 0;
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
    int query(int l, int r, int node, int nodeleft, int noderight)
    {
        if (r < nodeleft || noderight < l)
            return 0;
        if (l <= nodeleft && noderight <= r)
            return segtree[node].ms;
        int mid = (nodeleft + noderight) / 2;
        return max(query(l,r,node*2,nodeleft,mid),query(l,r,node*2+1,mid+1,noderight));
    }
    int query(int l, int r)
    {
        return query(l, r, 1, 0, n-1);
    }
    void update(int left, int right, int node, int change_node ,int diff)
    {
        if (!(left <= change_node &&change_node <= right))
            return;
        if (left == right && left == change_node)
        {
            segtree[node].ls += diff;
            segtree[node].rs += diff;
            segtree[node].ms += diff;
            segtree[node].s += diff;
        }
        else
        {
            int mid = (left + right) / 2;
            update(left, mid, node * 2, change_node, diff);
            update(mid +1,right, node * 2 +1, change_node, diff);
            segtree[node].ls = max(segtree[node*2].ls, segtree[node*2].s+segtree[node*2+1].ls);
            segtree[node].rs = max(segtree[node*2+1].rs, segtree[node*2].rs+segtree[node*2+1].s);
            segtree[node].ms = max(max(segtree[node*2].ms, segtree[node*2+1].ms),max(segtree[node].ls, segtree[node].rs));
            segtree[node].ms = max(segtree[node].ms, segtree[node*2].rs+segtree[node*2+1].ls);
            segtree[node].s = segtree[node*2].s+segtree[node*2+1].s;
        }
    }
    void update(int change_node, int diff)
    {
        update(0,n-1,1,change_node,diff);
    }
};
SEG S;
int32_t main()
{
    usecppio
    cin >> n;
    for (int i = 0; i<n; i++)
    {
        int x, y, v; cin >> x >> y >> v;
        mines.push_back({x, y, v});
    }
    coordinate_compression();
    S.n = n;
    int ans = 0;
    for (int i = 0; i<n; i++)
    {
        if (i > 0 && mines[i].y == mines[i-1].y) continue;
        S.init();
        for (int j = i; j<n; j++)
        {
            S.update(mines[j].x, mines[j].val);
            if (j < n-1 && mines[j].y == mines[j+1].y) continue;
            else
                ans = max(ans, S.query(0, n));
        }
    }
    cout << ans << '\n';
}