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

int solve()
{
    int n, m; cin >> n >> m;
    if (n == 1 || m == 1)
        return n + m - 1;
    if (n == m) return n;
    int p = 2*n-2, q = 2*m-2;
    if (p % q == 0) return n;
    if (q % p == 0) return m;
    int g = __gcd(p, q);
    int gg = g/2;
    int pp = p/2, qq = q/2;
    int mp = pp/gg, mq = qq/gg;
    int ans = mp*mq*(gg-1);
    int tp = pp+1-mp*(gg-1);
    int tq = qq+1-mq*(gg-1);
    int tp1, tp2, tq1, tq2;
    tp1 = tp2 = tp/2;
    tq1 = tq2 = tq/2;
    if (tp%2) tp1++;
    if (tq%2) tq1++;
    ans += tp1 * tq1 + tp2 * tq2;
    return ans;
}
int32_t main()
{
    cout << solve() << '\n';
}
