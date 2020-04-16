#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define int ll
using pii = pair<int, int>;

int grid[120][120];
void solve()
{
    memset(grid,-1,sizeof(grid));
    int n, m;
    cin >> n >> m;
    for (int i = 1; i<=n; i++)
    {
        for (int j = 1; j<=m; j++)
        {
            grid[i][j] = 1-(i+j)%2;
        }
    }
    if (n*m%2==0)
    {
        if (m%2==0)
            grid[1][m] = 1;
        else grid[n][1] = 1;
    }
    for (int i = 1; i<=n; i++)
    {
        for (int j = 1; j<=m; j++)
        {
            cout << (grid[i][j]==0?"W":"B");
        }
        cout << '\n';
    }
}

int32_t main()
{
    usecppio
    int t;
    cin >> t;
    while(t--) solve();
}