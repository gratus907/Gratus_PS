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
const int mod = 1000000007;
int n;
int vind[101010];
deque <vector <int>> st;
int ans = 0;
int32_t main()
{
    memset(vind, -1, sizeof(vind));
    cin >> n;
    int washed = 0;
    for (int i = 0; i<n; i++)
    {
        int u;
        cin >> u;
        if (u < washed)
            break;
        if (vind[u] == -1)
        {
            st.push_back({u});
            for (int j = u; vind[j]==-1 && j>=1; j--)
                vind[j] = st.size()-1;
            continue;
        }
        while(!st[vind[u]].empty() && st[vind[u]].back() < u)
        {
            washed = max(washed, st[vind[u]].back());
            ans++;
            st[vind[u]].pop_back();
        }
        st[vind[u]].push_back(u);
    }
    for (auto it:st)
        ans += it.size();
    cout << ans << '\n';
}