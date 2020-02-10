#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
using pii = pair <int, int>;
#define int ll
#define MOD 1000000007
pii answer = {-1, -1};
int n, m, arr[303030][10];
int chk[303030];
int occ[256];
bool ok(int k)
{
    memset(occ,0,sizeof(occ));
    memset(chk,0,sizeof(chk));
    for (int i = 1; i<=n; i++)
    {
        for (int j = 0; j<m; j++)
        {
            if (arr[i][j]>=k)
                chk[i] += (1<<j);
        }
        occ[chk[i]] = i;
    }
    for (int i = 0; i<(1<<m); i++)
    {
        for (int j = 0; j<(1<<m); j++)
        {
            if ((i|j) != ((1<<m)-1))
                continue;
            else if (occ[i]==0 || occ[j]==0) continue;
            else
            {
                answer = {occ[i], occ[j]};
                return true;
            }
        }
    }
    return false;
}
int32_t main()
{
    usecppio
    cin >> n >> m;
    for (int i = 1; i<=n; i++)
        for (int j = 0; j<m; j++)
            cin >> arr[i][j];
    int lo = -1, hi = 1e9+5;
    while(lo + 1 < hi)
    {
        int mid = (lo+hi)/2;
        if (ok(mid))
        {
            lo = mid;
        }
        else hi = mid;
    }
    //printf("Result = %lld\n",lo);
    cout << answer.first << ' ' << answer.second << '\n';
}