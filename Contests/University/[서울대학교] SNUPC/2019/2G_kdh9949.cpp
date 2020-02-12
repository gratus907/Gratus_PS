#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x.begin()),(x.end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using pii = pair<int, int>;
int n, m;
int nodenum[202020];
vector <int> topo_sort;
int nodeind[202020];
int mlen[202020];
string str;
vector <int> graph[202020];
bool visit[202020];
vector <pii> edges;
void topo(int r)
{
    visit[r] = true;
    for (auto it:graph[r])
    {
        if (!visit[it])
        {
            topo(it);
        }
    }
    topo_sort.push_back(r);
}
int main()
{
    usecppio
    cin >> n >> m;
    cin >> str;
    for (int i = 0; i<n; i++)
    {
        if (str[i]=='K')
            nodenum[i+1] = 0;
        if (str[i]=='D')
            nodenum[i+1] = 1;
        if (str[i]=='H')
            nodenum[i+1] = 2;
    }
    for (int i = 0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;
        if ((nodenum[u]+1)%3 == nodenum[v])
        {
            graph[u].push_back(v);
            edges.push_back({u,v});
        }    
        else if ((nodenum[v]+1)%3 == nodenum[u])
        {
            graph[v].push_back(u);
            edges.push_back({v,u});
        }    
    }
    int ans = 0;
    for (int i = 1; i<=n; i++)
    {
        if (!visit[i])
            topo(i);
    }
    reverse(all(topo_sort));
    for (int i =  1; i<=n; i++)
    {
        nodeind[topo_sort[i-1]] = i;
    }
    for (auto it:edges)
    {
        if (nodeind[it.first] > nodeind[it.second])
        {
            cout << -1;
            return 0;
        }
    }

    for (int i = n-1; i >=0; i--)
    {
        int u = topo_sort[i];
        if (graph[u].empty())
        {
            //printf("Empty\n");
            mlen[u] = 1;
        }
        else
        {
            int M = 1;
            for (auto it:graph[u])
            {
                M = max(mlen[it]+1, M);
            }
            mlen[u] = M;
        } 
        //printf("Node %d : mlen = %d, nodenum = %d\n",u,mlen[u],nodenum[u]);
        if (nodenum[u]==0)
        {
            ans = max(ans, mlen[u]/3*3);
        }
    }
    if (ans == 0)
    {
        cout << -1; 
        return 0;
    }
    cout << ans;
}