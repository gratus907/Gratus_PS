#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;
const bool debug = false;

int dp[101010];
bool vst[101010];
int t;
int subh[101010];
vector <int> Tree[101010];
vector <int> cutTree[101010];
int n, s, d;
int last;
int calcH(int r, int p)
{
    if (Tree[r].size()==1 && Tree[r][0] == p)
    {
        subh[r] = 1;
        return subh[r];
    }
    int ans = 0;
    for (auto it:Tree[r])
    {
        if (it != p)
        {
            ans = max(ans, calcH(it, r));
        }
    }
    ans++;
    subh[r] = ans;
    return subh[r];
}

int dfs(int r, int p)
{
    vst[r] = true;
    if (cutTree[r].size()==1 && cutTree[r][0]==p)
    {
        return 1;
    }
    int ans = 1;
    for (auto it:cutTree[r])
    {
        if (!vst[it])
        {
            ans++;
            ans += dfs(it, r);
        }
    }
    dp[r] = ans;
    return dp[r];
}
int32_t main()
{
    usecppio
    cin >> n >> s >> d;
    for (int i = 1; i<n; i++)
    {
        int u, v; cin >> u >> v;
        Tree[u].push_back(v);
        Tree[v].push_back(u);
    }
    calcH(s, -1);
    for (int i = 1; i<=n; i++)
    {
        if (subh[i] <= d) continue;
        for (auto it:Tree[i])
        {
            if (subh[it] > d)
            {
                cutTree[i].push_back(it);
                cutTree[it].push_back(i);
            }
        }
    }
    dfs(s, -1);
    cout << dp[s]-1 << '\n';
}