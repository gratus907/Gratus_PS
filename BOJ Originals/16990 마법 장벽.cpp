#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
#define int ll
using pii = pair <int, int>;
#define INF 0x7f7f7f7f7f7f7f7f
const bool debug = 0;
bool tbl[10][10][10];
int ans = 0;
inline int safemod(int x, int M)
{
    return ((x%M)+M)%M;
}
int32_t main()
{
    usecppio
    int n, m;
    cin >> n >> m;
    memset(tbl, true, sizeof(tbl));
    for (int i = 1; i<=n; i++)
    {
        int L; string S;
        cin >> L >> S;
        for (int a = 0; a<L; a++)
        {
            for (int b = 0; b<L; b++)
            {
                int di = safemod(b*i, L);
                int pi = safemod(a, L);
                if (S[(pi+di)%L]=='0')
                    tbl[L][a][b] = false;
            }
        }
    }
    while(m--)
    {
        int p, d; 
        cin >> p >> d;
        bool t = true;
        for (int i = 1; i<=6; i++)
        {
            int u = safemod(p, i);
            int v = safemod(d, i);
            t &= tbl[i][u][v];
        }
        if (t) 
        {
            if(debug) printf("\nOK %lld %lld\n",p, d);
            ans++;
        }
    }
    cout << ans << '\n';
}