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

struct entry
{
    multiset<int> elements;
    entry(){};
    entry(int x)
    {
        elements.insert(x);
    }
    bool operator<(int x)
    {
        if (elements.empty()) return true;
        else
            return *elements.begin()<x;
    }
};
int n;
vector <entry> vt;
vector <int> G[202020];
int dp[202020];
int pos[202020];
int arr[202020];
int sz = 0;
void dfs(int r, int p)
{
    if (vt.empty())
    {
        vt.push_back({arr[r]});
        sz++;
        pos[r] = 0;
    }
    else if (vt.back() < arr[r])
    {
        vt.push_back({arr[r]});
        sz++;
        pos[r] = vt.size()-1;
    }
    else
    {
        auto it = lower_bound(all(vt),arr[r]);
        if (it->elements.empty())
            sz++;
        it->elements.insert(arr[r]);
        pos[r] = it-vt.begin();
    }
    dp[r] = sz;
    for (auto it:G[r])
        if (it!=p)
            dfs(it, r);
    vt[pos[r]].elements.erase(vt[pos[r]].elements.lower_bound(arr[r]));
    if (vt[pos[r]].elements.empty())
        sz--;
    while (vt.back().elements.empty())
        vt.pop_back();
}
int32_t main()
{
    usecppio
    cin >> n;
    for (int i = 1; i<=n; i++) cin >> arr[i];
    for (int i = 1; i<n; i++)
    {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i<=n; i++)
        cout << dp[i] << '\n';
}