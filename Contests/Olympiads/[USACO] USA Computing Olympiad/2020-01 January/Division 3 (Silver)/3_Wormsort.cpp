#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
#define MOD 1000000007
using pii = pair <int, int>;

int N, M;
struct Disjoint_Set_Union
{
#define V 101010
    int parent[V], size[V];
    Disjoint_Set_Union(int n = V-1)
    {
        init(n);
    }
    void init(int n = V-1)
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
int arr[101010];
int pos[101010];
int rw[101010];
int notok = N;
struct edge
{
    int s, e, w;
    edge(int a = 0, int b = 0, int c = 0)
    {
        s = a, e = b, w = c;
    }
};
bool compare(edge a, edge b)
{
    return a.w > b.w;
}
vector <edge> v;
vector <edge> ed_by_w[101010];


bool able(int x)
{
    //printf("Edges to weight > %lld\n",rw[x]);
    for (int i = 0; i<x; i++)
        for (auto it:ed_by_w[i])
            dsu.unite(it.s, it.e);
    for (int i = 1; i<=N; i++)
    {
        if (dsu.Find(i)!=dsu.Find(pos[i]))
            return false;
    }
    //printf("Ok\n");
    return true;
}
int32_t main()
{
    ifstream fin("wormsort.in");
    ofstream fout("wormsort.out");
    fin >> N >> M;
    for (int i = 1; i<=N; i++)
    {
        fin >> arr[i];
        pos[arr[i]] = i;
        if (arr[i] != i) notok++;
    }
    for (int i = 0; i<M; i++)
    {
        int s, e, w;
        fin >> s >> e >> w;
        v.push_back(edge(s,e,w));
    }
    if (notok == 0)
    {
        fout << -1;
        return 0;
    }
    sort(all(v),compare);
    int ptr = 0;
    ed_by_w[0].push_back(v[0]);
    rw[0] = v[0].w;
    for (int i = 1; i<v.size(); i++)
    {
        if (v[i].w == v[i-1].w)
        {
            ed_by_w[ptr].push_back(v[i]);
        }
        else
        {
            ptr++;
            ed_by_w[ptr].push_back(v[i]);
            rw[ptr] = v[i].w;
        }
    }
    int ans = 2e9;
    int sz = ptr+1;
    int lo = 1, hi = sz+1;
    while(lo + 1 < hi)
    {
        dsu.init();
        int mid = (lo + hi)/2;
        if (able(mid))
            hi = mid;
        else
            lo = mid;
    }
    fout << rw[lo];
}