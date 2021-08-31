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
const int mod = 1000000007;

#define V 101010
struct DSU {
    int par[V], sz[V];
    DSU(){init(V);}
    void init(int n) {
        for (int i = 0; i<n; i++)
            par[i] = i, sz[i] = 1;
    }
    int find(int x) {
        return x == par[x] ? x : (par[x] = find(par[x]));
    }
    void unite(int x, int y){
        int u = find(x), v = find(y);
        if (u==v) return;
        par[u] = par[v];
    }
};
DSU dsu;
struct edge {
    int u, v, idx;
    bool operator==(const edge &o) {
        return idx == o.idx;
    }
    bool operator<(const edge &o) {
        return idx < o.idx;
    }
};
char ans[101010];
int n, m, p;
struct ArticulationEdge {
    int n;
    vector <edge> G[V];
    vector <edge> arts;
    int low[V], order[V];
    bool vst[V];
    int t = 0, rt = 0;
    void dfs(int r, int par) {
        vst[r] = true;
        order[r] = t++;
        low[r] = t;
        for (edge e : G[r]) {
            int nxt = e.u + e.v -r;
            if (nxt == par) continue;
            if (!vst[nxt]) {
                dfs(nxt, r);
                if (low[nxt] > order[r])
                    arts.push_back(e);
                low[r] = min(low[nxt], low[r]);
            }
            else low[r] = min(low[r], order[nxt]);
        }
    }

    void find_art_edges() {
        memset(vst, 0, sizeof(vst));
        for (int i = 1; i <= n; i++)
            if (!vst[i])
                dfs(rt = i, 0);
        sort(all(arts));
        arts.erase(unique(all(arts)), arts.end());
    }
} ART;

vector <edge> edge_list;
vector <edge> tree_edge_list;
vector <edge> T[V];
map<pii, int> edgefind;
int dep[101010];
int tpar[101010];
int updown[101010];
#define UP 100
#define DOWN 200
void find_dep(int r, int par) {
    tpar[r] = par;
    dep[r] = dep[par]+1;
    for (edge e : T[r]) {
        int nxt = dsu.find(e.u + e.v - r);
        if (dep[nxt] > 1e9) {
            find_dep(nxt, r);
        }
    }
}
int32_t main() {
    usecppio
    cin >> n >> m; ART.n = n;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        ART.G[u].push_back({u, v, i});
        ART.G[v].push_back({u, v, i});
        edge_list.push_back({u, v, i});
    }
    ART.find_art_edges();
    for (edge e : ART.arts) {
        ans[e.idx] = 1;
    }
    for (int i = 0; i < m; i++) {
        if (!ans[i]) {
            edge e = edge_list[i];
            dsu.unite(e.u, e.v);
            ans[i] = 'B';
        }
        else ans[i] = 0;
    }
    for (edge e : edge_list) {
        if (ans[e.idx] == 0) {
            int u = dsu.find(e.u);
            int v = dsu.find(e.v);
            tree_edge_list.push_back({u, v, e.idx});
            T[u].push_back({u, v, e.idx});
            T[v].push_back({u, v, e.idx});
            edgefind[{u, v}] = e.idx;
        }
    }
    memset(dep, 0x7f, sizeof(dep));
    for (int i = 1; i <= n; i++) {
        if (dep[dsu.find(i)] > 1e9) {
            dep[0] = -1;
            find_dep(dsu.find(i), 0);
        }
    }


    cin >> p;
    while(p--) {
        int u, v; cin >> u >> v;
        u = dsu.find(u); v = dsu.find(v);
        if (u == v) {
            continue;
        }
        else {
            while(dsu.find(u) != dsu.find(v)) {
                u = dsu.find(u); v = dsu.find(v);
                if (dep[u] > dep[v]) {
                    updown[u] = UP;
                    if (edgefind.find({u, tpar[u]}) != edgefind.end()) {
                        int idx = edgefind[{u, tpar[u]}];
                        ans[idx] = 'R';
                    }
                    else {
                        int idx = edgefind[{tpar[u], u}];
                        ans[idx] = 'L';
                    }
                    dsu.unite(u, tpar[u]);
                }
                else {
                    updown[v] = DOWN;
                    if (edgefind.find({tpar[v], v}) != edgefind.end()) {
                        int idx = edgefind[{tpar[v], v}];
                        ans[idx] = 'R';
                    }
                    else {
                        int idx = edgefind[{v, tpar[v]}];
                        ans[idx] = 'L';
                    }
                    dsu.unite(v, tpar[v]);
                }
            }
        }
    }

    for (int i = 0; i < m; i++) {
        if (ans[i] == '?' || ans[i] == 0) ans[i] = 'B';
        cout << ans[i];
    }
    cout << '\n';
}