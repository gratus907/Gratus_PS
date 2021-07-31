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
using psi = pair<string, int>;

struct boo {
    int u, v, w;
};

vector <int> G[202020], T[202020];
vector <boo> boos;
int Tvert[202020];
bool vst[202020];

int n, m;

void add_edge(int a, int b) {
    T[a].push_back(b);
    T[b].push_back(a);
}

void build_tree(int r, int p) {
    vst[r] = true;
    for (int c : G[r]) {
        if (c == p) continue;
        if (!vst[c]) {
            add_edge(r, c);
            build_tree(c, r);
        }
        else {
            if (c < r) continue;
            n++;
            Tvert[n] = c;
            add_edge(r, n);
        }
    }
}

bool build_boo(int r, int p) {
    vst[r] = true;
    if (T[r].size() == 1) return false;
    vector <bool> used;
    used.resize(T[r].size(), 0);
    int d = T[r].size();
    for (int i = 0; i < d; i++) {
        if (T[r][i] != p)
            used[i] = build_boo(T[r][i], r);
    }
    vector <int> unused;
    for (int i = 0; i < d; i++) {
        if (!used[i] and T[r][i] != p)
            unused.push_back(T[r][i]);
    }
    for (int i = 0; i + 1 < unused.size(); i += 2)
        boos.push_back({unused[i], r, unused[i+1]});
    if (unused.size() % 2 == 1) {
        if (p != -1) {
            boos.push_back({unused.back(), r, p});
            return true;
        }
    }
    return false;
}

void print_boo() {
    cout << boos.size() << '\n';
    for (boo b : boos)
        cout << Tvert[b.u] << ' ' << Tvert[b.v] << ' ' << Tvert[b.w] << '\n';
}

int32_t main() {
    usecppio
    cin >> n >> m;
    int on = n;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= on; i++) {
        Tvert[i] = i;
    }
    for (int i = 1; i <= on; i++) {
        if (!vst[i])
            build_tree(i, -1);
    }
    memset(vst, 0, sizeof(vst));
    for (int i = 1; i <= n; i++) {
        if (!vst[i])
            build_boo(i, -1);
    }
    print_boo();
}