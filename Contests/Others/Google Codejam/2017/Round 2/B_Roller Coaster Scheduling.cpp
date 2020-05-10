#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using pii = pair<int, int>;

vector<int> ticket[1010];
int least[1010];
int pref[1010];
pii solve()
{
    memset(least, 0, sizeof(least));
    memset(pref, 0, sizeof(pref));
    for (auto &it:ticket)
        it.clear();
    int n, c, m;
    scanf("%d %d %d",&n,&c,&m);
    for (int i = 0; i<m; i++)
    {
        int pi, ci;
        scanf("%d %d",&pi,&ci);
        ticket[ci].push_back(pi);
        least[pi]++;
    }
    for (int i = 1; i<=n; i++)
        pref[i] = pref[i-1]+least[i];
    int minride = 0;
    for (int i = 1; i<=c; i++)
        minride = max(minride, (int)(ticket[i].size()));

    for (int r = minride;;r++)
    {
        bool ok = true;
        for (int i = 1; i<=n; i++)
        {
            if (r*i>=pref[i])
                continue;
            else
            {
                ok = false; break;
            }
        }
        if (!ok) continue;
        int promotion = 0;
        for (int i = 1; i<=n; i++)
        {
            if (least[i]>r)
            {
                promotion += (least[i]-r);
            }
        }
        return {r, promotion};
    }
}
int32_t main()
{
    int T; scanf("%d",&T);
    for (int tc = 1; tc<=T; tc++)
    {
        auto ans = solve();
        printf("Case #%d: %d %d\n",tc, ans.first, ans.second);
    }
}