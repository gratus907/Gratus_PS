#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
#define eps 1e-7
#pragma GCC optimize ("unroll-loops")
#define int ll
const int mod = 998244353;
using pii = pair<int, int>;

struct Range_Maximum_Tree
{
    int n;
    vector<int> segtree;

    Range_Maximum_Tree()
    {
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
    void update(int left,int right, int node, int change_node ,int diff)
    {
        if (!(left <= change_node &&change_node <= right))
            return;
        if (left == right)
            segtree[node] = diff;
        else
        {
            int mid = (left + right) / 2;
            update(left, mid, node * 2, change_node, diff);
            update(mid +1,right, node * 2 +1, change_node, diff);
            segtree[node] = max(segtree[2 * node], segtree[2 * node + 1]);
        }
    }
};


vector <pii> v;
Range_Maximum_Tree T;
int nxt[202020];
vector <int> p;
int ct[202020];
int32_t main()
{
    usecppio
    int n; cin >> n;
    T.n = n;
    T.segtree.resize(4*n);
    for (int i = 0; i<n; i++)
    {
        int x, d; cin >> x >> d;
        v.push_back({x, d});
    }
    sort(all(v));
    v.push_back({1e10,0});
    nxt[n] = n;
    for (int i = n-1; i>=0; i--)
        nxt[i] = i+1;
    for (int i = 0; i<n; i++)
    {
        p.push_back(nxt[i]);
    }
    T.initialize(p,0,n-1,1);
    for (int i = n-1; i>=0; i--)
    {
        pair<int, int> pp = make_pair(v[i].first+v[i].second, 0ll);
        int u = (lower_bound(all(v),pp)-v.begin());
        nxt[i] = T.maxq(i,u-1,1,0,n-1);
        T.update(0,n-1,1,i,nxt[i]);
    }
    ct[0] = 1;
    for (int i = 0; i<n; i++)
    {
        ct[nxt[i]]+=ct[i];
        ct[nxt[i]]%=mod;
        ct[i+1]+=ct[i];
        ct[i+1]%=mod;
    }
    cout << ct[n] << '\n';
}
