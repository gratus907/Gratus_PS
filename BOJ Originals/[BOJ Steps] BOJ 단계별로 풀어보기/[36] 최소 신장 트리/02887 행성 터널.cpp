#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int ll
using pii = pair<ll, ll>;
vector <pii> x, y, z;

struct edge
{
    int s, e, w;
    bool operator<(const edge &other) const 
    {
        return w < other.w;
    }
};
const int V = 101010;
struct Disjoint_Set_Union
{
    int connected;
    int parent[V], size[V];
    Disjoint_Set_Union()
    {
        init(100000);
    }
    void init(int n)
    {
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
        connected=n;
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

vector <edge> graph;
int Kruskal()
{
    int mstlen = 0;
    sort(graph.begin(),graph.end());
    for (auto it:graph)
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
    usecppio
    int n;
    cin >> n;
    for (int i = 1; i<=n; i++)
    {
        int xx, yy, zz;
        cin >> xx >> yy >> zz;
        x.push_back({xx,i});
        y.push_back({yy,i});
        z.push_back({zz,i});
    }
    sort(all(x));
    sort(all(y));
    sort(all(z));
    for (int i = 0; i<(n-1); i++)
    {
        graph.push_back({x[i].second,x[i+1].second,x[i+1].first-x[i].first});
        graph.push_back({x[i+1].second,x[i].second,x[i+1].first-x[i].first});
        graph.push_back({y[i].second,y[i+1].second,y[i+1].first-y[i].first});
        graph.push_back({y[i+1].second,y[i].second,y[i+1].first-y[i].first});
        graph.push_back({z[i].second,z[i+1].second,z[i+1].first-z[i].first});
        graph.push_back({z[i+1].second,z[i].second,z[i+1].first-z[i].first});
    }
    cout << Kruskal() << '\n';
}