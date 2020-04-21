#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;

struct work
{
    int s, e, ind;
    bool operator<(const work & other)
    {
        return s < other.s;
    }
};
void solve()
{
    vector <work> works;
    vector <pii> who;
    int n; scanf("%d",&n);
    for (int i = 0; i<n; i++)
    {
        int a, b; scanf("%d %d",&a,&b);
        works.push_back({a, b, i});
    }
    sort(all(works));
    int c = 0, j = 0;
    for (auto &it : works)
    {
        if (c <= it.s)
        {
            c = it.e;
            who.push_back({it.ind, 0});
        }
        else if (j <= it.s)
        {
            j = it.e;
            who.push_back({it.ind, 1});
        }
        else
        {
            printf("IMPOSSIBLE\n");
            return;
        }
    }
    sort(all(who));
    string ans = "CJ";
    for (auto it:who)
    {
        printf("%c",ans[it.second]);
    }
    printf("\n");
}

int32_t main()
{
    int t;
    cin >> t;
    int tc = 1;
    while(t--)
    {
        printf("Case #%d: ",tc);
        tc++;
        solve();
    }
}