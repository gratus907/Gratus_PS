#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
#define eps 1e-7
using pii = pair <int, int>;

int r, c, m;
char message[5050];
bitset<550> dp[2][550];
char mp[550][550];
bitset<550> bd[550];
int32_t main()
{
    scanf("%d %d %d\n",&r,&c,&m);
    for (int i = 1; i<=r; i++)
        scanf(" %s",&mp[i][1]);
    scanf(" %s",message+1);
    for (int i = 1; i<=r; i++)
        for (int j = 1; j<=c; j++)
            bd[i][j] = (mp[i][j]=='#'?0:1);

    memcpy(dp[0],bd,sizeof(dp[0]));
    for (int id = 1; id<=m; id++)
    {
        int t = id%2, b = 1-t;
        memcpy(dp[t],bd,sizeof(dp[t]));
        if (message[id] == 'E')
            for (int i = 1; i<=r; i++)
                dp[t][i] &= (dp[b][i]<<1);
        else if (message[id] == 'W')
            for (int i = 1; i<=r; i++)
                dp[t][i] &= (dp[b][i]>>1);
        else if (message[id] == 'N')
            for (int i = 1; i<=r; i++)
                dp[t][i] &= dp[b][i+1];
        else if (message[id] == 'S')
            for (int i = 1; i<=r; i++)
                dp[t][i] &= dp[b][i-1];
        else if (message[id] == '?')
            for (int i = 1; i<=r; i++)
                dp[t][i] &= (dp[b][i+1] | dp[b][i-1] | dp[b][i]>>1 | dp[b][i]<<1);
    }
    int ans = 0;
    for (int i = 1; i<=r; i++)
        for (int j = 1; j<=c; j++)
            ans += (dp[m%2][i][j]?1:0);
    printf("%d\n",ans);
}