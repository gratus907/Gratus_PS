#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using pii = pair<int, int>;
const int V = 202020;
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
};

struct edge
{
    int s, e, w;
    bool operator<(const edge &other)
    {
        return w > other.w;
    }
};
vector <pii> Query;
vector <edge> edgelist;

int lo[202020], hi[202020];
map<int, vector<int>, greater<int>> mp;
int32_t main()
{
    usecppio
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i<m; i++)
    {
        int a, b, v; cin >> a >> b >> v;
        edgelist.push_back({a, b, v});
    }
    sort(edgelist.begin(),edgelist.end());
    for (int i = 0; i < q; i++)
    {
        int a, b; cin >> a >> b;
        Query.push_back({a, b});
    }
    fill(hi, hi+202020, 1e9);
    while(1)
    {
        bool flag = false;
        mp.clear();
        for(int i = 0; i < q; i++)
        {
            if(lo[i]+1 < hi[i])
            {
                flag = true;
                int mid = (lo[i]+hi[i])/2;
                if (mp.find(mid)==mp.end())
                    mp[mid] = {i};
                else mp[mid].push_back(i);
            }
        }
        if(!flag) break;
        Disjoint_Set_Union DSU;
        int pt = 0;
        for (auto it:mp)
        {
            int cur = it.first;
            while(pt < m && edgelist[pt].w >= cur)
            {
                DSU.unite(edgelist[pt].s, edgelist[pt].e);
                pt++;
            }
            for (auto itt:it.second)
            {
                if (DSU.Find(Query[itt].first) == DSU.Find(Query[itt].second))
                    lo[itt] = cur;
                else 
                    hi[itt] = cur;
            }
        }
    }
    for(int i = 0; i < q; i++)
    {
        cout << lo[i] << '\n';
    }
}