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
    int x, y;
    cin >> x >> y;
    vector <int> xdir, ydir;
    int ax = -x, ay = -y;
    int sum = ax+ay;
    int bit = -1;
    vector <pii> move;
    int ms = 0;
    while(ms < abs(ax)+abs(ay))
    {
        bit++;
        ms += (1ll<<bit);
    }
    if (sum %2 == 0)
    {
        cout << "IMPOSSIBLE" << '\n'; return;
    }
    while(ax != 0 || ay != 0)
    {
        int u = (1ll<<bit);
        if (abs(ax)>=abs(ay))
        {
            if (ax>0)
            {
                xdir.push_back(-u);
                ax -= u;
            }
            else if (ax<0)
            {
                xdir.push_back(u);
                ax += u;
            }
        }
        else if (abs(ax)<abs(ay))
        {
            if (ay>0)
            {
                ydir.push_back(-u);
                ay-=u;
            }
            else if (ay<0)
            {
                ydir.push_back(u);
                ay += u;
            }
        }
        bit--;
    }
    for (auto it:xdir)
        move.push_back({it, 0});
    for (auto it:ydir)
         move.push_back({it, 1});
    sort(all(move),[](auto a, auto b)->bool{return abs(a.first)<abs(b.first);});
    for (auto it:move)
    {
        if (it.second==0)
            cout << (it.first>0?'E':'W');
        else
            cout << (it.first>0?'N':'S');
    }
    return;
}

int32_t main()
{
    usecppio
    int TC; cin >> TC;
    for (int tc = 1; tc<=TC; tc++)
    {
        cout << "Case #" << tc << ": ";
        solve();
        cout << "\n";
    }
}