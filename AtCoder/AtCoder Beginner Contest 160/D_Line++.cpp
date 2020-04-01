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
const int mod = 998244353;

int n, x, y;
vector <int> G[2020];
int dpd[2020];
int dt[2020];
int32_t main()
{
    usecppio
    cin >> n >> x >> y;
    for (int i = 1; i<n; i++)
    {
        G[i].push_back(i+1);
        G[i+1].push_back(i);
    }
    G[x].push_back(y);
    G[y].push_back(x);
    for (int i = 1; i<=n; i++)
    {
        memset(dt, 0x7f, sizeof(dt));
        queue <int> q;
        q.push(i);
        dt[i] = 0;
        while(!q.empty())
        {
            int p = q.front();
            q.pop();
            for (auto it:G[p])
            {
                if (dt[it]==INF)
                {
                    dt[it] = dt[p]+1;
                    q.push(it);
                }
            }
        }
        for (int j = 1; j<=n; j++)
        {
            dpd[dt[j]]++;
        }
    }
    for (int i = 1; i<n; i++)
    {
        cout << dpd[i]/2 << '\n';
    }
}
