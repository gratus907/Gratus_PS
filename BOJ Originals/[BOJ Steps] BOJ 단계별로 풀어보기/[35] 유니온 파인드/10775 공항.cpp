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
        for(int i = 0;i <= N;i++)
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
        parent[x] = y;
    }
} dsu;

int32_t main()
{
    usecppio
    int G, P;
    cin >> G >> P;
    int cnt = 0;
    for (int i = 0; i<P; i++)
    {
        int g; cin >> g;
        int u = dsu.Find(g);
        if (u == 0)
            break;
        dsu.unite(u, u-1);
        cnt++;
    }
    cout << cnt << '\n';
}