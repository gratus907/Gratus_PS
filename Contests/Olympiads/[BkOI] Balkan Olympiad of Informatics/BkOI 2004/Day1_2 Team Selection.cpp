#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;
int INF = 987654321;
struct Range_Minimum_Tree
{
    int n;
    vector<int> segtree;

    Range_Minimum_Tree(vector<int> &data)
    {
        n = data.size();
        segtree.resize(4 * n);
        initialize(data, 0, n - 1, 1);
    }

    int initialize(vector<int> &data, int l, int r, int node)
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
            return INF;
        if (l <= nodeleft && noderight <= r)
            return segtree[node];
        int mid = (nodeleft + noderight) / 2;
        return min(minq(l,r,node*2,nodeleft,mid),
                   minq(l,r,node*2+1,mid+1,noderight));
    }
    void update(int left,int right,int node, int change_node ,int diff)
    {
        if (!(left <= change_node && change_node <= right))
            return;
        if (left == right)
        {
            segtree[node] = diff;
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
};

struct Student
{
    int a, b, c;
    bool operator<(const Student& o)
    {
        return a < o.a;
    }
};


vector <Student> v;
int n;
int32_t main()
{
    usecppio
    cin >> n;
    v.resize(n);
    vector <int> tmp(n, 0);
    Range_Minimum_Tree S(tmp);
    for (int i = 0; i<n; i++)
    {
        int x; cin >> x; x--;
        v[x].a = i;
    }
    for (int i = 0; i<n; i++)
    {
        int x; cin >> x; x--;
        v[x].b = i;
    }
    for (int i = 0; i<n; i++)
    {
        int x; cin >> x; x--;
        v[x].c = i;
    }
    sort(all(v));
    for (int i = 0; i<n; i++)
        S.update(i,INF);
    int ans = 0;
    for (int i = 0; i<n; i++)
    {
        int u = S.minq(0,v[i].b,1,0,n-1);
        if (u > v[i].c)
            ans ++;
        S.update(v[i].b, v[i].c);
    }
    cout << ans << '\n';
}
