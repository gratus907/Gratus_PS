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

void solve()
{
    int p, f, cs, cw, s, w;
    cin >> p >> f >> cs >> cw >> s >> w;
    if (s > w)
    {
        swap(s, w);
        swap(cs, cw);
    }
    int ans = 0;
    for (int msd = 0; msd <= cs; msd++)
    {
        if (msd*s > p) continue;
        int tmpcnt = msd;
        int mleft = p - tmpcnt * s;
        int takeaxe = min(cw, mleft/w);
        mleft -= takeaxe * w;
        tmpcnt += takeaxe;
        int lefts = cs-msd;
        int leftx = cw-takeaxe;
        int psd = min(lefts, f/s);
        lefts -= psd;
        tmpcnt += psd;
        int fleft = f - psd * s;
        int pax = min(leftx, fleft/w);
        tmpcnt += pax;
        ans = max(ans, tmpcnt);
        //printf("I take %lld sword : me (%lld, %lld), part (%lld, %lld)\n",msd,msd,takeaxe,psd,pax);
    }
    cout << ans << '\n';
}

int32_t main()
{
    usecppio
    int t;
    cin >> t;
    while(t--) solve();
}