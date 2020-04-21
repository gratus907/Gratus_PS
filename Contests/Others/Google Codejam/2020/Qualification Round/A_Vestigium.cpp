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

void solve()
{
    vector <int> row[120], col[120];
    int n; scanf("%d",&n);
    int arr[120][120];
    for (int i = 1; i<=n; i++)
    {
        for (int j = 1; j<=n; j++)
        {
            scanf("%d",&arr[i][j]);
            row[i].push_back(arr[i][j]);
            col[j].push_back(arr[i][j]);
        }
    }
    int trc = 0;
    int badrow = 0, badcol = 0;
    for (int i = 1; i<=n; i++) trc += arr[i][i];
    for (int i = 1; i<=n; i++)
    {
        vector <int> uq = row[i];
        sort(all(uq));
        uq.erase(unique(all(uq)),uq.end());
        if (uq.size()<row[i].size())
            badrow++;
    }
    for (int i = 1; i<=n; i++)
    {
        vector <int> uq = col[i];
        sort(all(uq));
        uq.erase(unique(all(uq)),uq.end());
        if (uq.size()<col[i].size())
            badcol++;
    }
    printf("%d %d %d\n",trc,badrow,badcol);
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