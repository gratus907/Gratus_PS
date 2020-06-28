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
        return segtree[node] = ls*rs;
    }

    int Query(int l, int r, int node, int nodeleft, int noderight)
    {
        if (r < nodeleft || noderight < l)
            return 1;
        if (l <= nodeleft && noderight <= r)
            return segtree[node];
        int mid = (nodeleft + noderight) / 2;
        return Query(l,r,node*2,nodeleft,mid)*Query(l,r,node*2+1,mid+1,noderight);
    }
    int Query(int l, int r)
    {
        return Query(l, r, 1, 0, n-1);
    }
    void update(int left,int right,int node, int change_node ,int diff)
    {
        if (!(left <= change_node &&change_node <= right))
            return;
        if (left == right)
            segtree[node] = diff;
        if (left != right)
        {
            int mid = (left + right) / 2;
            update(left, mid, node * 2, change_node, diff);
            update(mid +1,right, node * 2 +1, change_node, diff);
            segtree[node] = segtree[node*2]*segtree[node*2+1];
        }
    }
    void update(int change_node, int diff)
    {
        update(0,n-1,1,change_node,diff);
    }
};
int n, k;
int32_t main()
{
    usecppio
    while(!(cin >> n >> k).eof())
    {
        vector <int> v;
        for (int i = 0; i<n; i++)
        {
            int x; cin >> x;
            if (x > 0) x = 1;
            else if (x < 0) x = -1;
            else x = 0;
            v.push_back(x);
        }
        SEG S = SEG(v);
        for (int i = 0; i<k; i++)
        {
            string type;
            cin >> type;
            if (type[0] == 'C')
            {
                int pos, val;
                cin >> pos >> val;
                if (val > 0) val = 1;
                else if (val < 0) val = -1;
                else val = 0;
                pos--;
                S.update(pos, val);
            }
            else
            {
                int l, r;
                cin >> l >> r;
                l--, r--;
                char ch;
                int z = S.Query(l, r);
                if (z > 0) ch = '+';
                else if (z < 0) ch = '-';
                else ch = '0';
                cout << ch;
            }
        }
        cout << '\n';
    }
}
