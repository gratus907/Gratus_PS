#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int V, q;
struct Disjoint_Set_Union
{
    int parent[202020], size[202020];
    Disjoint_Set_Union(int n = V)
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
};
Disjoint_Set_Union DSU;
int par[202020];
bool mark[202020];
vector <string> results;
vector <pair <int, int>> queries;
int main()
{
    usecppio
    cin >> V >> q;
    DSU = Disjoint_Set_Union(V);
    for (int i = 2; i<=V; i++)
        cin >> par[i];
    for (int i = 0; i<V+q-1; i++)
    {
        int a, b, c;
        cin >> a;
        if (a)
        {
            cin >> b >> c;
            queries.push_back({b,c});
        }
        else
        {
            cin >> b;
            queries.push_back({a,b});
            mark[b] = true;
        }
    }
    for (int i = V+q-2; i>=0; i--)
    {
        pair <int, int> p = queries[i];
        if (!p.first)
            DSU.unite(p.second,par[p.second]);
        else 
        {
            bool flag = true;
            flag = (DSU.Find(p.first) == DSU.Find(p.second));
            results.push_back((flag?"YES\n":"NO\n"));
        }
    }
    reverse(all(results));
    for (auto it:results)
        cout << it;
}