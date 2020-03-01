#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;

// Original Author : Ashishgup
struct Disjoint_Set_Union
{
#define V 101010
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
int n, m, k;
vector <int> fr[101010];
vector <int> blk[101010];
int sug[101010];
int32_t main()
{
    usecppio
    cin >> n >> m >> k;
    for (int i = 0; i<m; i++)
    {
        int a, b; cin >> a >> b;
        fr[a].push_back(b);
        fr[b].push_back(a);
        dsu.unite(a, b);
    }
    for (int i = 0; i<k; i++)
    {
        int c, d; cin >> c >> d;
        blk[c].push_back(d);
        blk[d].push_back(c);
    }
    for (int i = 1; i<=n; i++)
    {
        sug[i] = dsu.getSize(i)-fr[i].size()-1;
        for (auto it:blk[i])
        {
            if (dsu.Find(it)==dsu.Find(i))
                sug[i]--;
        }
    }
    for (int i = 1; i<=n; i++)
    {
        cout << sug[i] << ' ';
    }
}
