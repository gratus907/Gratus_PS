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

struct DSU
{
#define V 1010
    int par[V], sz[V];
    DSU(){init(V);}
    void init(int n)
    {
        for (int i = 0; i<n; i++)
            par[i] = i, sz[i] = 1;
    }
    int find(int x)
    {
        return x == par[x] ? x : (par[x] = find(par[x]));
    }
    int getSize(int k){return sz[find(k)];}
    bool unite(int x, int y)
    {
        int u=find(x), v=find(y);
        if(u==v) return false;
        if(sz[u]>sz[v]) swap(u, v);
        sz[v]+=sz[u];
        sz[u] = 0;
        par[u] = par[v];
        return true;
    }
};

DSU S;
struct edge {
    int u, v, w;
    bool operator<(const edge &e) {
        return w < e.w;
    }
};
vector <edge> edges;
vector <edge> matches;
vector <vector<int>> T;
int P[1010], C[1010], L[1010];

void dfs(int r, int p) {
    for (int c : T[r]) {
        if (c != p) {
            dfs(c, r);
            cout << r << ' ' << c << '\n';
        }
    }
}
int32_t main() {
    usecppio
    int n; cin >> n;
    T.resize(n+5);
    for (int i = 1; i <= n; i++) {
        cin >> P[i] >> C[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j == i) continue;
            int w = (C[i] + C[j]) / (abs(P[i] - P[j]));
            edges.push_back({i, j, w});
        }
    }
    sort(all(edges));

    int totalView = 0;
    while (!edges.empty()) {
        edge e = edges.back();
        edges.pop_back();
        if (S.unite(e.u, e.v)) {
            matches.push_back(e);
            T[e.u].push_back(e.v);
            T[e.v].push_back(e.u);
            totalView += e.w;
        }
    }
    cout << totalView << '\n';
    dfs(1, 0);
}