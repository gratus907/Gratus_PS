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

char belt[105][105];
bool solved[105][105];
void solve()
{
    memset(belt, 0, sizeof(belt));
    memset(solved, 0, sizeof(solved));
    int n, m; scanf("%lld %lld", &n, &m);
    for (int i = 1; i<=n; i++)
        scanf("%s",belt[i]+1);
    int cnt = 0;
    solved[n][m] = 1;
    for (int i = n; i>=1; i--)
    {
        for (int j = m; j>=1; j--)
        {
            if (i == n && j == m)
                continue;
            if (belt[i][j] == 'D')
            {
                if (solved[i+1][j])
                {
                    solved[i][j] = true;
                }
                else if (solved[i][j+1])
                {
                    cnt++;
                    solved[i][j] = true;
                }
            }
            else if (belt[i][j] == 'R')
            {
                if (solved[i][j+1])
                {
                    solved[i][j] = true;
                }
                else if (solved[i+1][j])
                {
                    cnt++;
                    solved[i][j] = true;
                }
            }
        }
    }
    printf("%lld\n",cnt);
}

int32_t main()
{
    usecppio
    int t;
    scanf("%lld", &t);
    while(t--) solve();
}