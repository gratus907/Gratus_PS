#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
struct block
{
    int s, e, tp;
    bool operator<(const block&other)
    {
        if (e != other.e) return e< other.e;
        return (s < other.s);
    }
};
int dp[15200];
bool visit[15200];
int price[120];
int pt = 1;
vector <block> v;
int32_t main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i<=n; i++)
        cin >> price[i];
    for (int i = 0; i<m; i++)
    {
        int s, e, tp;
        cin >> s >> e >> tp;
        v.push_back({s,e,tp});
    }
    visit[0] = true;
    sort(v.begin(),v.end());
    for (auto it:v)
    {
        while(pt<=it.s)
        {
            dp[pt] = max(dp[pt],dp[pt-1]);
            pt++;
            visit[pt] = true;
        }
        dp[it.e] = max(dp[it.e],dp[it.s]+(it.e-it.s)*(price[it.tp]));
    }
    while(pt<=15000)
    {
        dp[pt] = max(dp[pt],dp[pt-1]);
        pt++;
        visit[pt] = true;
    }
    cout << dp[15000];
}