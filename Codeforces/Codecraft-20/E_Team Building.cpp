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
#define int ll
using pii = pair <int, int>;
int n, p, k;
int play[101010][10];
int tmp[101010][10];
int aud[101010];
int tmpaud[101010];
int32_t main()
{
    usecppio
    cin >> n >> p >> k;
    int total = 0;
    for (int i = 1; i<=n; i++)
        cin >> aud[i];
    for (int i = 1; i<=n; i++)
        for (int j = 1; j<=p; j++)
            cin >> play[i][j];
    for (int pick = 1; pick <= p; pick++)
    {
        memcpy(tmp, play, sizeof(play));
        memcpy(tmpaud, aud, sizeof(aud));
        sort(tmpaud+1, tmpaud+n+1, greater<int>());
        for (int i = 1; i<=n; i++)
        {
            if (tmpaud[k]<=aud[i])
            {
                int u = aud[i] - tmpaud[k+1];
                for (int j = 1; j<=p; j++)
                    tmp[i][j] -= u;
            }
        }
        int mi = 0, mj = 0;
        int cm = -1;
        for (int i = 1; i<=n; i++)
        {
            for (int j = 1; j<=p; j++)
            {
                if (tmp[i][j] > cm)
                {
                    mi = i, mj = j, cm = tmp[i][j];
                }
            }
        }
        total += play[mi][mj];
        aud[mi] = 0;
        for (int i = 1; i<=n; i++)
            play[i][mj] = 0;
        for (int i = 1; i<=p; i++)
            play[mi][i] = 0;
    }
    memcpy(tmpaud, aud, sizeof(aud));
    sort(tmpaud+1, tmpaud+n+1, greater<int>());
    for (int i = 1; i<=k; i++)
        total += tmpaud[i];
    cout << total << '\n';
}