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

int tc = 1;

void solve()
{
    int k, n;
    scanf("%lld %lld",&n,&k);
    map<int, int> mp;
    int cur = 0;
    int last = n;
    mp[n] = 1;
    while(cur < k)
    {
        auto t = *mp.rbegin();
        //printf("%lld uses %lld empty\n",t.second,t.first);
        cur += t.second;
        last = t.first;
        int ft = t.first/2;
        int se = t.first-ft-1;
        if (ft>0)
            mp[ft] += t.second;
        if (se>0)
            mp[se] += t.second;
        mp.erase(t.first);
    }
    int mx = last/2, my = last-mx-1;
    printf("Case #%lld: %lld %lld\n",tc,mx,my);
    tc++;
}

int32_t main()
{
    int t;
    scanf("%lld",&t);
    while(t--)
        solve();
}