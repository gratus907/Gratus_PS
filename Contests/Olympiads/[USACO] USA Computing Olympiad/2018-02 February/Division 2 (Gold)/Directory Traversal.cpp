#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int ll
using namespace std;
using pii = pair<int, int>;
using piii = pair<pair <int, int>, int>;
int n, root;
int sz[101010];
int ans[101010];
int from_root[101010];
bool vst[101010];
vector <pii> tree[101010];
int is_file[101010];
vector <int> alled[101010];
int par[101010];
int num_of_leaves[101010];
int dfscall;
void dfs(int rt, int bef)
{
    dfscall++;
    int tp = ans[bef];
    tp -= (sz[rt]+1)*num_of_leaves[rt];
    tp += 3*(num_of_leaves[0]-num_of_leaves[rt]);
    ans[rt] = tp;
    for (auto it:tree[rt])
    {
        dfs(it.first, rt);
    }
}
int cdfs(int r)
{
    int u = 0;
    if (is_file[r])
        return 1;
    for (auto it:tree[r])
        u += cdfs(it.first);
    num_of_leaves[r] = u;
    return u;
}
int32_t main()
{
    usecppio
    cin >> n;
    for (int i = 1; i<=n; i++)
    {
        string s;
        int m;
        cin >> s >> m;
        if (m == 0)
            is_file[i] = 1;
        sz[i] = s.length();
        for (int j = 0; j<m; j++)
        {
            int c; cin >> c;
            alled[i].push_back(c);
            par[c] = i;
        }
    }
    for (int i = 1; i<=n; i++)
    {
        for (auto it:alled[i])
        {
            if (!is_file[it])
                tree[i].push_back({it, sz[it]+1});
            else
                tree[i].push_back({it, sz[it]});
        }
        if (!par[i])
            root = i;
    }
    num_of_leaves[root] = cdfs(root);
    num_of_leaves[0] = num_of_leaves[root];
    queue <int> q;
    q.push(root);
    vst[root] = 1;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto it:tree[x])
        {
            if (!vst[it.first])
            {
                from_root[it.first] = from_root[x] + it.second;
                vst[it.first] = true;
                q.push(it.first);
            }
        }
    }
    for (int i = 1; i<= n; i++)
        if (is_file[i])
            ans[root] += from_root[i];
        
    int ansans = LLONG_MAX;

    for (auto it:tree[root])
        dfs(it.first, root);

    for (int i = 1; i<=n; i++)
        if (!is_file[i])
            ansans = min(ansans, ans[i]);
    cout << ansans << '\n';
}