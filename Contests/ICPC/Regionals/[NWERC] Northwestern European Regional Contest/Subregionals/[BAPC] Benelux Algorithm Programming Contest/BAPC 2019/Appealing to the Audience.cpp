#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
using pii = pair <int, int>;
#define int ll
#define INF 0x7f7f7f7f7f7f7f7f
int n, k;
vector <int> skill;
int par[101010];
vector <int> graph[101010];
bool visited[101010];
vector <int> values;
int dfs(int r)
{
    visited[r] = true;
    vector <int> v;
    if (graph[r].size()==0)
        v = {0};
    for (auto it:graph[r])
    {
        if (!visited[it])
        {
            auto v2 = dfs(it);
            v.push_back(v2);
        }
    }
    sort(all(v),greater<int>());
    v[0]++;
    for (int i = 1; i<v.size(); i++)
        values.push_back(v[i]);
    return v[0];
}
int32_t main()
{
    usecppio
    cin >> n >> k;
    for (int i = 0; i<k; i++)
    {
        int x; cin >> x; skill.push_back(x);
    }
    for (int i = 1; i<n; i++)
    {
        cin >> par[i];
        graph[par[i]].push_back(i);
    }
    int t = dfs(0);
    values.push_back(t-1);
    sort(all(values),greater<int>());
    sort(all(skill),greater<int>());
    int ans = 0;
    for (int i = 0; i<k; i++)
        ans += skill[i]*values[i];
    cout << ans << '\n';
}