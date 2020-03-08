#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
#define eps 1e-7
#define int ll
using pii = pair <int, int>;
int n;
int ans;
vector <int> graph[5050];
int count_dist[5050];
bool visit[5050];
vector <int> dt[5050];
int dfs(int r, int d)
{
    visit[r] = true;
    count_dist[d]++;
    int res = d;
    for (auto it:graph[r])
        if (!visit[it])
            res = max(res, dfs(it, d+1));
    return res;
}

int32_t main()
{
    usecppio
    cin >> n;
    for (int i = 1; i<n; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 1; i<=n; i++)
    {
        memset(visit, 0, sizeof(visit));
        memset(dt, 0, sizeof(dt));
        visit[i] = true;
        int md = 0;
        for (auto it:graph[i])
        {
            if (!visit[it])
            {
                memset(count_dist, 0, sizeof(count_dist));
                md = dfs(it, 1);
                for (int l = 1; l<=md; l++)
                    dt[l].push_back(count_dist[l]);
            }
        }
        for (int l = 1; l<=n; l++)
        {
            int a = 0, b = 0;
            for (auto it:dt[l])
                b += it;
            for (auto it:dt[l])
            {
                b -= it;
                ans += it*a*b;
                a += it;
            }
        }
    }
    cout << ans << '\n';
}