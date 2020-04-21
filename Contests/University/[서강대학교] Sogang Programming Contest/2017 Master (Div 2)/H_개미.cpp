#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
#define int ll
using pii = pair <int, int>;
#define INF 0x7f7f7f7f7f7f7f7f
const bool debug = 0;

int n;
vector <pii> T[101010];
int par[101010][20];
int dist[101010];
int energy[101010];
inline int dt(int a, int b)
{
    return abs(dist[a]-dist[b]);
}
int32_t main()
{
    usecppio
    cin >> n;
    for (int i = 1; i<=n; i++)
        cin >> energy[i];
    for (int i = 1; i<n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        T[a].push_back({b, c});
        T[b].push_back({a, c});
    }
    queue<int>q;
    q.push(1);
    memset(par, -1, sizeof(par));
    memset(dist, -1, sizeof(dist));
    dist[1] = 0;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto it:T[x])
        {
            if (dist[it.first]==-1)
            {
                dist[it.first] = dist[x]+it.second;
                par[it.first][0] = x;
                //printf("Direct parent of %lld is %lld\n",it.first, x);
                q.push(it.first);
            }
        }
    }
    for (int i = 1; i<20; i++)
        for (int j = 1; j<=n; j++)
            if (par[j][i-1]!=-1)
                par[j][i] = par[par[j][i-1]][i-1];
    for (int i = 1; i<=n; i++)
    {
        int cur = i;
        int cur_energy = energy[i];
        for (int p = 19; p>=0; p--)
        {
            int pp = par[cur][p];
            //printf("Try %lld parent of %lld, %lld\n",p,cur,pp);
            if (pp == -1) continue;
            int d = dt(cur, pp);
            if (d > cur_energy) continue;
            cur = pp;
            cur_energy -= d;
        }
        cout << cur << '\n';
    }
}