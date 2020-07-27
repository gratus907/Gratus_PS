#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define ll long long
#define int ll
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;

int n;
vector <int> T[303030];
vector <pii> edges;

inline int deg(int x)
{
    return T[x].size();
}
int count_d()
{
    int ans = 0;
    for (auto it:edges)
        ans += (deg(it.first)-1)*(deg(it.second)-1);
    return ans;
}

int count_g()
{
    int ans = 0;
    for (int i = 1; i<=n; i++)
    {
        int k = deg(i);
        ans += (k*(k-1)*(k-2))/6;
    }
    return ans;
}

int32_t main()
{
    usecppio
    cin >> n;
    for (int i = 1; i<n; i++)
    {
        int u, v; cin >> u >> v;
        edges.push_back({u, v});
        T[u].push_back(v);
        T[v].push_back(u);
    }
    int D = count_d();
    int G = count_g();
    if (D > 3*G) cout << "D\n";
    else if (D < 3*G) cout << "G\n";
    else cout << "DUDUDUNGA\n";
}