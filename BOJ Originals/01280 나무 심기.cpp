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
struct SEG
{
    int n;
    vector<int> segtree;

    SEG(const vector<int> &data)
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
        int ls = initialize(data, l, mid, node * 2);
        int rs = initialize(data, mid + 1, r, node * 2 + 1);
        return segtree[node] = ls+rs;
    }

    int sumq(int l, int r, int node, int nodeleft, int noderight)
    {
        if (r < nodeleft || noderight < l)
            return 0;
        if (l <= nodeleft && noderight <= r)
            return segtree[node];
        int mid = (nodeleft + noderight) / 2;
        return sumq(l,r,node*2,nodeleft,mid)+sumq(l,r,node*2+1,mid+1,noderight);
    }
    int sumq(int l, int r)
    {
        return sumq(l, r, 1, 0, n-1);
    }
    void update(int left,int right,int node, int change_node ,int diff)
    {
        if (!(left <= change_node &&change_node <= right))
            return;
        segtree[node] += diff;
        if (left != right)
        {
            int mid = (left + right) / 2;
            update(left, mid, node * 2, change_node, diff);
            update(mid +1,right, node * 2 +1, change_node, diff);
        }
    }
    void update(int change_node, int diff)
    {
        update(0,n-1,1,change_node,diff);
    }
    void update_to(int change_node, int to)
    {
        int u = sumq(change_node, change_node);
        update(change_node, to-u);
    }
};
vector <int> arr(202020, 0);
SEG S(arr);
SEG CT(arr);
int ans = 1;
int32_t main()
{
    usecppio
    int n;
    cin >> n;
    int x; cin >> x;
    S.update(x, x);
    CT.update(x, 1);
    for (int i = 2; i<=n; i++)
    {
        cin >> x;
        int tmp = 0;
        int rsum = S.sumq(x,200000);
        int rcnt = CT.sumq(x,200000);
        tmp += (rsum - rcnt*x);
        tmp %= mod;
        int lsum = S.sumq(0, x);
        int lcnt = CT.sumq(0, x);
        tmp += (lcnt*x - lsum);
        tmp %= mod;
        ans *= tmp;
        ans %= mod;
        S.update(x, x);
        CT.update(x, 1);
    }
    cout << ans << '\n';
}