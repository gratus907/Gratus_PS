#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define int ll
using pii = pair<int, int>;
const int INF = 1e9;
struct DLSEG
{
    struct Node
    {
        int s, e, v, l;
        Node *L, *R;
        Node()
        {
            s = 1, e = INF;
            v = l = 0;
            L = R = NULL;
        }
        void extend()
        {
            if (L == NULL && R == NULL)
            {
                L = new Node();
                R = new Node();
                L -> s = s;
                L -> e = (s + e) >> 1;
                R -> s = (L -> e) + 1;
                R -> e = e;
            }
        }
    };
    Node *root = new Node();
    void propagate(Node *cur)
    {
        if ((cur -> l) != 0)
        {
            cur -> v += ((cur->e) - (cur->s) + 1) * (cur -> l);
            if (cur -> s != cur -> e)
            {
                cur -> extend();
                cur -> L -> l += cur -> l;
                cur -> R -> l += cur -> l;
            }
            cur -> l = 0;
        }
    }
    void _update(Node *cur, int l, int r, int d)
    {
        propagate(cur);
        if ((cur -> s) > (cur -> e) || (cur -> s) > r || (cur -> e) < l) return;
        if ((l <= cur -> s) && (cur -> e <= r))
        {
            cur -> v += ((cur->e) - (cur->s) + 1) * d;
            if (cur -> s != cur -> e)
            {
                cur -> extend();
                cur -> L -> l += d;
                cur -> R -> l += d;
            }
            return;
        }
        cur -> extend();
        _update(cur->L, l, r, d);
        _update(cur->R, l, r, d);
        cur -> v = (cur -> L -> v) + (cur -> R -> v);
    }
    int _query(Node *cur, int l, int r)
    {
        if ((cur -> s) > (cur -> e) || (cur -> s) > r || (cur -> e) < l)
            return 0;
        propagate(cur);
        if ((l <= cur -> s) && (cur -> e <= r))
            return cur -> v;
        cur -> extend();
        return _query(cur->L, l, r) + _query(cur->R, l, r);
    }
    void update(int l, int r, int d)
    {
        return _update(root, l, r, d);
    }
    int query(int l, int r)
    {return _query(root, l, r);}
};
DLSEG S;
struct Q
{
    int l, r, k, idx, res = 0;
    void apply(DLSEG &SEG)
    {
        SEG.update(l, r, k);
    }
};
deque <Q> Qs;
vector <Q> pQs;
int32_t main()
{
    usecppio
    int n; cin >> n;
    int idx = 1;
    for (int i = 0; i<n; i++)
    {
        int a, b, c;
        int t; cin >> t;
        cin >> a >> b >> c;
        if (t == 1)
            Qs.push_back({a, b, c, idx++});
        else
            pQs.push_back({a, b, c, i});
    }
    sort(all(Qs),[](Q &a, Q&b)->bool{return a.idx < b.idx;});
    sort(all(pQs),[](Q &a, Q&b)->bool{return a.k < b.k;});
    for (auto &it:pQs)
    {
        while(!Qs.empty() && Qs.front().idx <= it.k)
        {
            Qs.front().apply(S);
            Qs.pop_front();
        }
        it.res = S.query(it.l, it.r);
    }
    sort(all(pQs),[](Q &a, Q&b)->bool{return a.idx < b.idx;});
    for (auto it:pQs)
        cout << it.res << '\n';
}