#include <bits/stdc++.h>
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define int ll
using pii = pair<int, int>;

const int mod = 1000000007;
struct SegTree
{
    int n;
    int segtree[808080];
    int lazy[808080];
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
    //range_upd(s,e,k,1,0,n-1);
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
    //sum(s,e,1,0,n-1)
    int sum(int s, int e, int node, int nl, int nr)
    {
        propagation(node,nl,nr);
        if (nr < s || nl > e)
            return 0;
        if (s <= nl && nr <= e)
            return segtree[node];
        int mid = (nl+nr)/2;
        return (sum(s,e,node*2,nl,mid) + sum(s,e,node*2+1,mid+1,nr));
    }
};
const int MAX_NODE = 202020;
struct ETT
{
    int id = 0, n;
    vector <int> G[MAX_NODE];
    int S[MAX_NODE], E[MAX_NODE];
    void addEdge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }
    void dfs(int r, int p) {
        S[r] = id; id++;
        for (auto it : G[r])
            if (it != p)
                dfs(it, r);
        E[r] = id;
    }
    void preprocess(){dfs(0, -1);};
} E;

struct query {
    int v, c;
};

vector <query> qs;
vector <pii> vert;
int col[MAX_NODE];
SegTree S;
int32_t main() {
    usecppio
    int n, m, c; cin >> n >> m >> c;
    for (int i = 0; i < n; i++) {
        cin >> col[i];
        vert.push_back({col[i], i});
    }
    sort(all(vert), greater<pii>());
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; u--; v--;
        E.addEdge(u, v);
    }
    E.n = n;
    S.n = n;
    E.preprocess();
    vector <int> v(n, 0);
    for (int i = 1; i <= m; i++) {
        int vi, ci; cin >> vi >> ci; vi--;
        qs.push_back({vi, ci});
    }
    sort(all(qs), [](query &a, query &b) -> bool {
        return a.c < b.c;
    });
    int ans = 0;
    for (query &q : qs) {
        while (!vert.empty() and vert.back().first <= q.c) {
            int uvi = vert.back().second;
            S.range_upd(E.S[uvi], E.S[uvi], 1, 1, 0, n-1);
            vert.pop_back();
        }
        ans += S.sum(E.S[q.v], E.E[q.v]-1, 1, 0, n-1);
        ans %= mod;
    }
    cout << ans << '\n';
}