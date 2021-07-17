#include <bits/stdc++.h>
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;
const int V = 101010;
struct DSU {
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
    void unite(int x, int y)
    {
        int u=find(x), v=find(y);
        if(u==v) return;
        if(sz[u]>sz[v]) swap(u, v);
        sz[v]+=sz[u];
        sz[u] = 0;
        par[u] = par[v];
    }
};
DSU dsu;
int arr[101010];
set <int> st;

int solve() {
    st.clear();
    int n; scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    dsu.init(n);
    for (int i = 0; i < n; i++) {
        if (i + arr[i] < n)
            dsu.unite(i, i + arr[i]);
    }
    st.clear();
    for (int i = 0; i < n; i++) {
        st.insert(dsu.find(i));
    }
    return st.size();
}
int32_t main()
{
    int T, test_case;
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for(test_case = 0; test_case < T; test_case++)
    {
        printf("Case #%d\n", test_case+1);
        int Answer = solve();
        printf("%d\n", Answer);

    }
    return 0;
}