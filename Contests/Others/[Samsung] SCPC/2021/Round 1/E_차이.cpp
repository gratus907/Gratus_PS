#include <bits/stdc++.h>
#define int ll
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;
const bool debug = 0;
struct DSU
{
    int n;
    vector <int> par, weight;
    vector <bool> cf;
    DSU(){init();}
    void init()
    {
        par.clear(); weight.clear(); cf.clear();
        par.resize(n); weight.resize(n); cf.resize(n);
        for (int i = 0; i<n; i++)
            par[i] = i, weight[i] = 0, cf[i] = 0;
    }
    int find(int x)
    {
        if (x == par[x])
            return x;
        else
        {
            int p = find(par[x]);
            cf[p] = cf[p] | cf[x] | cf[par[x]];
            cf[x] = cf[x] | cf[p] | cf[par[x]];
            weight[x] += weight[par[x]];
            return par[x] = p;
        }
    }
    void unite(int x, int y, int w)
    {
        int u = find(x), v = find(y);
        if (cf[u] || cf[v]) {
            cf[u] = cf[u] | cf[v];
            cf[v] = cf[v] | cf[u];
            par[v] = par[u];
            return;
        }

        if (u == v) {
            if (weight[y] - weight[x] == w)
                return;
            else
                cf[u] = cf[v] = cf[x] = cf[y] = 1;
        }
        else {
            weight[v] += (w - weight[y] + weight[x]);
            par[v] = par[u];
            cf[u] = cf[u] | cf[v];
            cf[v] = cf[v] | cf[u];
        }
    }
};

DSU dsu;

void solve() {
    int n, k; scanf("%lld %lld",&n, &k);
    dsu.n = n;
    dsu.init();
    while(k--) {
        int type;
        scanf("%lld",&type);
        if (type == 1) {
            int u, v, d; scanf("%lld %lld %lld", &u, &v, &d);
            u--; v--;
            dsu.unite(u, v, d);
        }
        else {
            int u, v; scanf("%lld %lld", &u, &v);
            u--; v--;
            int fu = dsu.find(u);
            int fv = dsu.find(v);
            if (fu != fv)
                printf("NC\n");
            else if (dsu.cf[fu] || dsu.cf[fv])
                printf("CF\n");
            else
                printf("%lld\n",dsu.weight[v] - dsu.weight[u]);
        }
    }
}
int32_t main()
{
    int T, test_case;
    scanf("%lld",&T);
    for(test_case = 0; test_case  < T; test_case++)
    {
        printf("Case #%d\n", test_case+1);
        solve();
    }
    return 0;
}