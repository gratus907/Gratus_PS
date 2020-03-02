#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int ll
using pii = pair<int, int>;
// Original Author : Ashishgup
struct edge
{
    int u, v, t, c;
};
int n, m;
struct Disjoint_Set_Union
{
#define V 202
    int parent[V], size[V];
    Disjoint_Set_Union(int N = V)
    {
        init(N);
    }
    void init(int N)
    {
        for(int i=0;i<N;i++)
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
vector <edge> ed;
vector <pii> pt;
inline double run_with_config(double r, bool print = false)
{
    int st = 0, sc = 0;
    int ct = 0;
    dsu.init(n);
    sort(all(ed),[r](edge &a, edge &b)->bool{return a.t+a.c*r<b.t+b.c*r;});


    if (print)
    {
        for (auto it:ed)
        {
            if (dsu.Find(it.u)!=dsu.Find(it.v))
            {
                dsu.unite(it.u, it.v);
                st += it.t;
                sc += it.c;
                ct++;
                pt.push_back({it.u, it.v});
                if (ct == n-1)
                    break;
            }
        }
    }
    else
    {
        for (auto it:ed)
        {
            if (dsu.Find(it.u)!=dsu.Find(it.v))
            {
                dsu.unite(it.u, it.v);
                st += it.t;
                sc += it.c;
                ct++;
                if (ct == n-1)
                    break;
            }
        }
    }
    if (print)
    {
        cout << st << ' ' << sc << '\n';
        for (auto it:pt)
        {
            cout << it.first << ' ' << it.second << '\n';
        }
    }
    return st*sc;
}
int32_t main()
{
    const double magic = 1.5;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(1/magic, magic);
    std::uniform_real_distribution<> dis2(0, 1);
    cin >> n >> m;
    for (int i = 0; i<m; i++)
    {
        int u, v, t, c;
        cin >> u >> v >> t >> c;
        ed.push_back({u,v,t,c});
    }
    double ratio = 1;
    double iT = 1;
    double k = 0.99;
    double e1 = run_with_config(1);
    double e2 = 0;
    while(iT > 0.01)
    {
        double newratio = ratio * dis(gen);
        e2 = run_with_config(newratio);
        double p = exp((e1-e2)/(iT));
        if (p > dis2(gen))
        {
            ratio = newratio;
            e1 = e2;
        }
        iT *= k;
    }
    run_with_config(ratio, true);
}