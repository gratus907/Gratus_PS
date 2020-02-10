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
int binomial[2010][2010];
int n, m;
 
int nhr(int a, int b)
{
    if (a == 0 || b == 0) return 1;
    return binomial[a+b-1][b];
}
int32_t main()
{
    for (int i = 0; i<=2000; i++)
        binomial[i][0] = binomial[0][i] = 1;
    for (int i = 1; i<=2000; i++)
    {
        for (int j = 1; j<=i; j++)
        {
            if (i==j)
                binomial[i][j] = 1;
            else
                binomial[i][j] = (binomial[i-1][j-1]+binomial[i-1][j])%MOD;
        }
    }
    cin >> n >> m;
    int ans = 0;
    for (int i = 1; i<=n; i++)
    {
        ans += nhr(i, m-1)*nhr(n-i+1,m);
        ans %= MOD;
    }
    cout << ans%MOD << '\n';
}
