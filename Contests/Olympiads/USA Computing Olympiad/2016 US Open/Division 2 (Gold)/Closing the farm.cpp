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

int n, m;
vector <int> graph[202020];
vector <int> closes;
vector <bool> answers;
bool got[202020];
struct Disjoint_Set_Union
{
#define V 202020
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

int main()
{
    cin >> n >> m;
    for (int i = 0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 0; i<n; i++)
    {
        int x; cin >> x; closes.push_back(x);
    }
    reverse(all(closes));
    int ct = 0;
    for (auto it:closes)
    {
        got[it] = true;
        ct++;
        for (auto itt:graph[it])
            if (got[itt])
                dsu.unite(it,itt);
        answers.push_back(dsu.getSize(it)==ct);
    }
    reverse(all(answers));
    for (auto it:answers)
    {
        cout << (it?"YES\n":"NO\n");
    }
}