#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

struct edge
{
    int u, v, w;
    bool operator<(const edge &o)
    {
        return w<o.w;
    }
};
int arr[1030][1030];
vector <int> Tree[1030];
vector <edge> edges;
struct Disjoint_Set_Union
{
#define V 1030
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
int32_t main()
{
    usecppio
    int n;
    cin >> n;
    for (int i = 1; i<=n; i++)
    {
        for (int j = i+1; j<=n; j++)
        {
            cin >> arr[i][j];
            edges.push_back({i, j, arr[i][j]});
            arr[j][i] = arr[i][j];
        }
    }
    sort(all(edges));
    for (auto it:edges)
    {
        if (dsu.Find(it.u)!=dsu.Find(it.v))
        {
            dsu.unite(it.u,it.v);
            Tree[it.u].push_back(it.v);
            Tree[it.v].push_back(it.u);
        }
    }
    for (int i = 1; i<=n; i++)
    {
        cout << Tree[i].size() << ' ';
        sort(all(Tree[i]));
        for (auto it:Tree[i])
        {
            cout << it << ' ';
        }
        cout << '\n';
    }
}