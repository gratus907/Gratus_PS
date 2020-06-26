#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#define ll long long
#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
#define gcd(A,B) (__gcd(A,B))
#define lcm(A,B) A/(__gcd(A,B))*B
#define MP make_pair
#define PB push_back
#define EPS 1e-9
#define ld long double
#define mod 1000000007LL
#define all(x) x.begin(), x.end()
#define usecppio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define int ll
const int INF = 987654321987654321;
struct Edge
{
    int u, v, w;
};

vector <Edge> edgelist;
int V, E;
int dist[502];

bool relax_all_edge()
{
    bool flag = false;
    for (auto it:edgelist)
    {
        int u = it.u, v = it.v, w = it.w;
        if (dist[v] > dist[u] + w && (dist[u]!=INF))
        {
            flag = true;
            dist[v] = dist[u]+w;
        }
    }
    return flag;
}

int bellman_ford()
{
    fill(dist,dist+502,INF);
    dist[1] = 0;
    for (int i = 0; i<V-1; i++)
    {
        relax_all_edge();
    }
    if (relax_all_edge())
        return -1;
    else
        return 0;
}
int32_t main()
{
    usecppio
    cin >> V >> E;
    for (int i = 0; i<E; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        Edge newedge;
        newedge.u = u;
        newedge.v = v;
        newedge.w = w;
        edgelist.PB(newedge);
    }
    if (bellman_ford()==-1)
    {
        cout << -1 << '\n';
        return 0;
    }
    else
    {
        for (int i = 2; i<=V; i++)
        {
            cout << (dist[i]==INF?-1:dist[i]) << '\n';
        }
    }

}
