#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define int ll
#define PI acos(-1.0)
using pii = pair<int, int>;
struct Cosaraju
{
    int V, E;
    vector <vector<int>> G;
    vector <vector<int>> rG;
    vector <vector <int>> scc;
    vector <int> dfs_stack;
    vector <bool> visit;
    Cosaraju(int n = 0)
    {
        V = n;
        G.resize(V+5);
        rG.resize(V+5);
        visit.resize(V+5);
        scc.resize(V+5);
    }
    void re_init(int n)
    {
        V = n;
        G.resize(V+5);
        rG.resize(V+5);
        visit.resize(V+5);
        scc.resize(V+5);
    }
    void AddEdge(int u, int v)
    {
        G[u].push_back(v);
        rG[v].push_back(u);
    }
    void dfs(int r)
    {
        visit[r] = true;
        for (auto it:G[r])
            if (!visit[it])
                dfs(it);
        dfs_stack.push_back(r);
    }
    void rev_dfs(int r, int scc_num)
    {
        visit[r] = true;
        scc[scc_num].push_back(r);
        for (auto it:rG[r])
            if (!visit[it])
                rev_dfs(it, scc_num);
    }
    void find_scc()
    {
        fill(all(visit),0);
        for (int i = 1; i<=V; i++)
            if (!visit[i])
                dfs(i);
        fill(all(visit),0);
        int scc_count = 0;
        while(!dfs_stack.empty())
        {
            int tp = dfs_stack.back();
            dfs_stack.pop_back();
            if (!visit[tp])
            {
                rev_dfs(tp, scc_count);
                scc_count++;
            }
        }
        scc.resize(scc_count);
        for (int i = 0; i<scc_count; i++)
            sort(all(scc[i]));
        sort(all(scc),[](vector<int>&a, vector<int>&b)->bool{return a[0]<b[0];});
    }
};


Cosaraju SCC;

int32_t main()
{
    usecppio
    int V, E;
    cin >> V >> E;
    SCC.re_init(V);
    for (int i = 0; i<E; i++)
    {
        int u, v;
        cin >> u >> v;
        SCC.AddEdge(u, v);
    }
    SCC.find_scc();
    cout << SCC.scc.size() << '\n';
    for (auto it:SCC.scc)
    {
        for (auto itt:it)
        {
            cout << itt << ' ';
        }
        cout << -1 << '\n';
    }
}
