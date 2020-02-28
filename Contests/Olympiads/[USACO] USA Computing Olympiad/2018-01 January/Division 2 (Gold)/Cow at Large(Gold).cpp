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
using pii = pair<int, int>;

int n, k, ans;
vector <int> tree[101010];
bool is_exit[101010];
int depth[101010];
int minleafdepth[101010];
bool vst[101010];
vector <int> exits;

int dfs(int r)
{
    if (is_exit[r])
        return (minleafdepth[r] = depth[r]);
    int u = INT_MAX;
    vst[r] = true;
    for (auto it:tree[r])
    {
        if (!vst[it])
            u = min(u, dfs(it));
    }
    return (minleafdepth[r] = u);
}
void solve(int r)
{
    int dmdl = minleafdepth[r]-depth[r];
    vst[r] = true;
    if (depth[r] >= dmdl)
    {
        ans++;
        return;
    }
    for (auto it:tree[r])
    {
        if (!vst[it])
            solve(it);
    }
    return;
}
int32_t main()
{
    usecppio
    cin >> n >> k;
    for (int i = 1; i<n; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    for (int i = 1; i<=n; i++)
    {
        if (tree[i].size()==1)
        {
            is_exit[i] = true;
            exits.push_back(i);
        }
    }
    vst[k] = true;
    queue <int> q;
    q.push(k);
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto it:tree[x])
        {
            if (!vst[it])
            {
                vst[it] = true;
                depth[it] = depth[x] + 1;
                q.push(it);
            }
        }
    }
    memset(vst, 0, sizeof(vst));
    dfs(k);
    memset(vst, 0, sizeof(vst));
    solve(k);
    cout << ans << '\n';
}