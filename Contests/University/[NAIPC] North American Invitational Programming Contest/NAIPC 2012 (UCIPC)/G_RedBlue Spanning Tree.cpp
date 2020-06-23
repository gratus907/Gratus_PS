#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using pii = pair<int, int>;

struct Disjoint_Set_Union
{
    int parent[1010], size[1010];
    Disjoint_Set_Union(int n = 1000)
    {
        init(n);
    }
    void init(int n)
    {
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }
    int Find(int k)
    {
        while(k!=parent[k])
        {
            parent[k]=parent[parent[k]];
            k=parent[k];
        }
        return k;
    }
    int getSize(int k)
    {
        return size[Find(k)];
    }
    void unite(int x, int y)
    {
        int u=Find(x), v=Find(y);
        if(u==v)
            return;
        if(size[u]>size[v])
            swap(u, v);
        size[v]+=size[u];
        size[u] = 0;
        parent[u] = parent[v];
    }
} dsu;
struct edge
{
    int c, s, e, w;
    bool operator<(const edge &other) const
    {
        return w < other.w;
    }
};
int Kruskal(vector <edge> & edgelist)
{
    int mstlen = 0;
    sort(all(edgelist));
    for (auto it:edgelist)
    {
        if (dsu.Find(it.s)==dsu.Find(it.e)) // Cycle Detection
            continue;
        else
        {
            dsu.unite(it.s,it.e);
            mstlen += it.w;
        }
    }
    return mstlen;
}
int32_t main()
{
    vector <edge> edgelist;
    usecppio
    while(true)
    {
        dsu.init(1010);
        edgelist.clear();
        int n, m, k;
        cin >> n >> m >> k;
        edgelist.resize(m);
        if (n == 0 && m == 0 && k == 0) return 0;
        for (int i = 0; i < m; i++)
        {
            string c;
            int f, t;
            cin >> c >> f >> t;
            int color = c[0]=='B'?1:-1;
            edge e = {color, f, t, 0};
            edgelist[i] = e;
        }
        for (auto &it:edgelist)
            it.w = (it.c==1);
        int Bmin = Kruskal(edgelist);
        dsu.init(1000);
        for (auto &it:edgelist)
            it.w = (it.c==-1);
        int Bmax = n-Kruskal(edgelist)-1;
        if (Bmin <= k && k <= Bmax)
            cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}