#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
using pii = pair <int, int>;
#define int ll

struct Query
{
    int index, value, queryindex, result;
    Query(int a = 0, int b = 0, int c = 0)
    {
        index = a, value = b, queryindex = c;
    }
};
bool qbv(Query &a, Query &b)
{
    return a.value > b.value;
}
bool qbqi(Query &a, Query &b)
{
    return a.queryindex < b.queryindex;
}
struct Edge
{
    int a, b, r;
    bool operator<(const Edge& other)
    {
        return (r < other.r);
    }
};

struct Disjoint_Set_Union
{
#define V 101010
    int parent[V], size[V];
    Disjoint_Set_Union(int n = V-1)
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
int n, q;
vector <Query> allquery;
vector <Edge> eds;
int32_t main()
{
    usecppio
    cin >> n >> q;
    for (int i = 1; i<n; i++)
    {
        int u, v, r;
        cin >> u >> v >> r;
        eds.push_back({u,v,r});
    }
    for (int i = 1; i<=q; i++)
    {
        int a, b;
        cin >> a >> b;
        allquery.push_back({b,a,i});
    }
    sort(all(eds));
    reverse(all(eds));
    int ptr = 0;
    eds.push_back({0,0,-1});
    sort(all(allquery),qbv);
    for (int i = 0; i<q; i++)
    {
        while(eds[ptr].r>=allquery[i].value)
        {
            dsu.unite(eds[ptr].a,eds[ptr].b);
            ptr++;
        }
        allquery[i].result = dsu.getSize(allquery[i].index)-1;
    }
    sort(all(allquery),qbqi);
    for (auto it:allquery)
        cout << it.result << '\n';
}