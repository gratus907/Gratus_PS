#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using pii = pair<int, int>;
int n, m; 
vector<int> G[101010];
vector<pii> eds;
inline int count_intersection(vector<int> &a, vector <int> &b)
{
    int inter = 0;
    for (auto it:b)
        inter += binary_search(all(a),it);
    return inter;
}
int32_t main()
{
    usecppio
    cin >> n >> m;
    for (int i = 0; i<m; i++)
    {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        eds.push_back({u, v});
    }
    for (int i = 1; i<=n; i++)
        sort(all(G[i]));
    int trig = 0;
    for (auto it:eds)
        trig += count_intersection(G[it.first],G[it.second]);
    cout << trig/3 << '\n';
}