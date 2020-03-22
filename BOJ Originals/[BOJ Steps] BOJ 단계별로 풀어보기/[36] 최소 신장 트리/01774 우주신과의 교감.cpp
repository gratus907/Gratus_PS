#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define V 1050
struct edge
{
    int s, e;
    double w;
};
struct Disjoint_Set_Union
{
    int parent[V], size[V];
    Disjoint_Set_Union(int N = V-1)
    {
        init(N);
    }
    void init(int N)
    {
        for(int i=1;i<=N;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }
    int Find(int K)
    {
        while(K!=parent[K])
        {
            parent[K]=parent[parent[K]];
            K=parent[K];
        }
        return K;
    }
    int getSize(int K)
    {
        return size[Find(K)];
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

vector <edge> edgelist;
double Kruskal()
{
    double mstlen = 0;
    sort(edgelist.begin(),edgelist.end(),[](auto &a, auto &b){ return a.w < b.w; });
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

vector <pair<double, double>> v;
int32_t main()
{
    int n, m; cin >> n >> m;
    for (int i = 0; i<n; i++)
    {
        double a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++)
            edgelist.push_back({i, j, (sqrt(pow(v[i].first-v[j].first,2)+pow(v[i].second-v[j].second,2)))});
    for (int i = 0; i<m; i++)
    {
        int a, b; cin >> a >> b;
        dsu.unite(a-1, b-1);
    }
    printf("%.2lf\n",Kruskal());
}