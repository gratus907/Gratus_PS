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
#define PI 3.1415926535
using pii = pair<int, int>;
int n;
struct point
{
    int x, y ,oil;
};
struct segment
{
    int xl, xr, y;
    int value() {return xr - xl;}
};
vector <point> P;
vector <segment> seg;
int ccw (point a, point b, point c)
{
    int v = (b.x - a.x) * (c.y - a.y) - (b.y-a.y)*(c.x-a.x);
    if (v > 0) return 1;
    if (!v) return 0;
    return -1;
}
void solve()
{
    for (int i = 0; i<n; i++)
    {
        int x0, x1, y; cin >> x0 >> x1 >> y;
        if (x0 > x1) swap(x0, x1);
        seg.push_back({x0, x1, y});
    }
    int best = 0;
    for (int i = 0; i<2*n; i++)
    {
        int local_best = 0;
        int cur_x, cur_y;
        if (i%2 == 0)
            cur_x = seg[i/2].xl;
        else
            cur_x = seg[i/2].xr;
        cur_y = seg[i/2].y;
        int V = seg[i/2].value();
        local_best = max(local_best, V);
        P.clear();
        for (segment S : seg)
        {
            point in, out;
            if (S.y > cur_y)
            {
                in.x = cur_x - S.xl;
                out.x = cur_x - S.xr;
            }
            else if (S.y < cur_y)
            {
                in.x = S.xr-cur_x;
                out.x = S.xl-cur_x;
            }
            else
                continue;
            in.oil = S.value();
            out.oil = -S.value();
            in.y = abs(S.y - cur_y);
            out.y = abs(S.y - cur_y);
            P.push_back(in);
            P.push_back(out);
        }
        sort(all(P), [](auto a, auto b)
        {
            int u = ccw({0, 0}, a, b);
            if (u!=0) return u > 0;
            else return a.oil > b.oil;
        });
        for (point p : P)
        {
            V += p.oil;
            local_best = max(local_best, V);
        }
        best = max(best, local_best);
    }
    cout << best << '\n';
}

int32_t main()
{
    usecppio
    cin >> n;
    solve();
}