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
struct Cosaraju
{
    int V, E;
    vector <vector<int>> G;
    vector <vector<int>> rG;
    vector <vector <int>> scc;
    vector <int> dfs_stack;
    vector <bool> visit;
    vector <int> sccinfo;
    vector <int> indeg;
    Cosaraju(int n = 0)
    {
        V = n;
        G.resize(V+5);
        rG.resize(V+5);
        visit.resize(V+5, 0);
        scc.resize(V+5);
    }
    void re_init(int n)
    {
        V = n;
        G.clear(); rG.clear(); visit.clear(); scc.clear();
        G.resize(V+5);
        rG.resize(V+5);
        visit.resize(V+5, 0);
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
    int find_scc()
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
        sccinfo.clear(); sccinfo.resize(V+5);
        fill(all(sccinfo),0);
        for (int i = 0; i<scc.size(); i++)
            for (auto itt:scc[i])
                sccinfo[itt] = i;
        indeg.clear();
        indeg.resize(scc.size()+5);
        fill(all(indeg),0);
        for (int i = 1; i<=V; i++)
            for (auto it:G[i])
                if (sccinfo[it]!=sccinfo[i])
                    indeg[sccinfo[it]]++;
        int ans = 0;
        for (int i = 0; i<scc.size(); i++)
            if (indeg[i] == 0)
                ans++;
        return ans;
    }
};
Cosaraju C;
int32_t main()
{
    usecppio
    int T; cin >> T;
    while(T--)
    {
        int n, m; cin >> n >> m;
        C.re_init(n);
        for (int i = 0; i<m; i++)
        {
            int u, v; cin >> u >> v;
            C.AddEdge(u, v);
        }
        cout << C.find_scc() << '\n';
    }

}