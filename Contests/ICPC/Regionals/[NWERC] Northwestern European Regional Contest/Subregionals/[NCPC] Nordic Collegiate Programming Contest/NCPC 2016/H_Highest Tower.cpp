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
vector <int> num;
vector <pii> el;
vector <int> G[505050];
vector <int> dfs_tree;
bool vst[505050];
void coord_comp()
{
    sort(all(num));
    num.erase(unique(all(num)),num.end());
    for (auto &it:el)
    {
        it.first = lower_bound(all(num),it.first)-num.begin();
        it.second = lower_bound(all(num),it.second)-num.begin();
        G[it.first].push_back(it.second);
        G[it.second].push_back(it.first);
    }
}
void dfs(int r)
{
    dfs_tree.push_back(r);
    vst[r] = true;
    for (auto it:G[r])
        if (!vst[it])
            dfs(it);
}
int ans;
int32_t main()
{
    usecppio
    cin >> n;
    for (int i = 0; i<n; i++)
    {
        int a, b; cin >> a >> b;
        num.push_back(a); num.push_back(b);
        el.push_back({a, b});
    }
    coord_comp();
    int m = num.size();
    for (int i = 0; i<m; i++)
    {
        if (vst[i])
            continue;
        dfs(i);
        int edc = 0;
        for (auto it:dfs_tree)
            edc += G[it].size();
        edc /= 2;
        for (auto it:dfs_tree)
            ans += (num[it])*(G[it].size()-1);
        if (dfs_tree.size()>edc)
            ans += (num[*max_element(all(dfs_tree))]);
        dfs_tree.clear();
    }
    cout << ans << '\n';
}