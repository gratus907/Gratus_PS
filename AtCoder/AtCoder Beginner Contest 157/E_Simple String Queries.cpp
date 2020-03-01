#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;

struct SEG
{
    int n;
    vector<int> segtree;
    SEG()
    {
    }
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
        int lmin = initialize(data, l, mid, node * 2);
        int rmin = initialize(data, mid + 1, r, node * 2 + 1);
        return segtree[node] = lmin+rmin;
    }

    int addq(int l, int r, int node, int nodeleft, int noderight)
    {
        if (r < nodeleft || noderight < l)
            return 0;
        if (l <= nodeleft && noderight <= r)
            return segtree[node];
        int mid = (nodeleft + noderight) / 2;
        return (addq(l,r,node*2,nodeleft,mid)+addq(l,r,node*2+1,mid+1,noderight));
    }

    void update(int left,int right,int node, int change_node ,int diff)
    {
        if (!(left <= change_node && change_node <= right))
            return;
        segtree[node] += diff;
        if (left != right)
        {
            int mid = (left + right) / 2;
            update(left, mid, node * 2, change_node, diff);
            update(mid +1,right, node * 2 +1, change_node, diff);
        }
    }
    int query(int l, int r)
    {
        return addq(l, r, 1, 0, n-1);
    }
    void upd(int change_node, int diff)
    {
        return update(0,n-1,1,change_node,diff);
    }
};

SEG alphabets[26];
vector <int> occ[26];
string str;
int32_t main()
{
	usecppio
    int n; cin >> n;
    cin >> str;
    int q; cin >> q;
    for (int i = 0; i<26; i++)
        occ[i].resize(n);
    for (int i = 0; i<n; i++)
        occ[str[i]-'a'][i]++;
    for (int i = 0; i<26; i++)
        alphabets[i] = SEG(occ[i]);
    while(q--)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int b; string c;
            cin >> b >> c;
            int t = str[b-1]-'a';
            alphabets[t].upd(b-1,-1);
            alphabets[c[0]-'a'].upd(b-1, 1);
            str[b-1] = c[0];
        }
        else if (a == 2)
        {
            int l, r;
            cin >> l >> r;
            l--; r--;
            int ct = 0;
            for (int i = 0; i<26; i++)
            {
                int u = alphabets[i].query(l, r);
                if (u > 0)
                {
                    //printf("%c present %d in %d~%d\n",i+'a',u,l,r);
                    ct++;
                }
            }
            cout << ct << '\n';
        }
    }
}