#include <bits/stdc++.h>
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define int ll
const bool debug = 0;
using pii = pair<int, int>;
typedef long double D;

int n, k;
vector <int> tree[202020];
int subtree[202020];
int depth[202020];
int score[202020];
int dfs_count(int r, int p, int d)
{
    depth[r] = d;
    if (tree[r].size()==1 && tree[r].front()==p)
    {
        return (subtree[r] = 1);
    }
    int u = 1;
    for (auto it:tree[r])
    {
        if (depth[it]==-1)
            u += dfs_count(it, r, d+1);
        else u += subtree[it];
    }
    return (subtree[r] = u);
}
vector <pii> v;
int sc = 0;
int32_t main()
{
    usecppio
    cin >> n >> k;
    for (int i = 0; i<n-1; i++)
    {
        int u, v; cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    memset(depth,-1,sizeof(depth));
    dfs_count(1, 0, 0);
    for (int i = 1; i<=n; i++)
    {
        score[i] = depth[i]-subtree[i]+1;
        //printf("%lld node %lld %lld\n",i,depth[i],subtree[i]);
        v.push_back({score[i], i});
    }
    sort(all(v),greater<pii>());
    for (int i = 0; i<k; i++)
    {
        sc += v[i].first;
    }
    cout << sc << '\n';
}