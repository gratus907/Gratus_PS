#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx,avx2,fma")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int ll
#define all(x) ((x).begin()),((x).end())
#define eps 1e-6
using pii = pair<int, int>;
int n;
vector <int> G[202020];
int color[202020];
int down_cnt[202020], out_total[202020], up_cnt[202020];
int par[202020];
queue <int> q;
bool vst[202020];
void dfs(int r, int p, int* cnt)
{
    par[r] = p;
    for (auto it:G[r])
        if (it!=p)
            dfs(it, r, cnt);
    if (cnt[r]>0)
        cnt[p]+=cnt[r];
}
int32_t main()
{
    usecppio
    cin >> n;
    memset(par, -1, sizeof(par));
    for (int i = 1; i<=n; i++)
    {
        cin >> color[i];
        color[i] = color[i]==1?1:-1;
        down_cnt[i] = color[i];
    }
    for (int i = 1; i<n; i++)
    {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0, down_cnt);
    q.push(1);
    vst[1] = true;
    for (auto it:G[1])
        out_total[1] += max(down_cnt[it], 0ll);
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto it:G[x])
        {
            if (!vst[it])
            {
                up_cnt[it] = out_total[x]+color[x];
                if (down_cnt[it]>0)
                    up_cnt[it] -= down_cnt[it];
                vst[it] = true;
                q.push(it);
                for (auto itt:G[it])
                    if (itt!=par[it])
                        out_total[it] += max(down_cnt[itt], 0ll);
                out_total[it] += max(up_cnt[it], 0ll);
            }
        }
    }
    for (int i = 1; i<=n; i++)
        printf("%lld ",out_total[i]+color[i]);
    printf("\n");
}
