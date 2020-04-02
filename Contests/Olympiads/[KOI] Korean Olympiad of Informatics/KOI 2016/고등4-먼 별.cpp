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
struct point
{
    int x, y, dx, dy;
    point operator+(const point &other)
    {
        return {x+other.x, y+other.y};
    }
    point operator-(const point &other)
    {
        return {x-other.x, y-other.y};
    }
    point operator*(const int C)
    {
        return {x*C, y*C, dx, dy};
    }
    int normsq()
    {
        return x*x+y*y;
    }
};

int dist(point &a, point &b)
{
    return (a-b).normsq();
}
class convex_hull
{
public:
    int n;
    static int ccw (point a, point b, point c)
    {
        int v = (b.x - a.x) * (c.y - a.y) - (b.y-a.y)*(c.x-a.x);
        if (v > 0) return 1;
        if (!v) return 0;
        return -1;
    }
    static bool compy (point &a, point &b)
    {
        if (a.y == b.y) return a.x < b.x;
        return a.y < b.y;
    }
    vector <point> pt;
    vector <point> convex;
    void graham_scan()
    {
        convex.clear();
        sort(all(pt), compy);
        point down = pt[0];
        sort(all(pt), [&down](auto a, auto b)
        {
            int u = ccw(down, a, b);
            if (u!=0) return u>0;
            else return dist(down, a) < dist(down, b);
        });
        convex.push_back(pt[0]);
        convex.push_back(pt[1]);
        for (int i = 2; i<n; i++)
        {
            while(convex.size() > 1)
            {
                point tp = convex.back();
                convex.pop_back();
                point tptp = convex.back();
                if (ccw(tptp,tp,pt[i]) > 0)
                {
                    convex.push_back(tp);
                    break;
                }
            }
            convex.push_back(pt[i]);
        }
    }
    int rotating_calipers()
    {
        int msz = 0;
        int t = 0;
        point o = {0, 0};
        int nc = convex.size();
        for(int i=0; i<convex.size(); i++)
        {
            while(t+1 < convex.size() && ccw(o, convex[i+1]-convex[i], convex[t+1]-convex[t])>=0)
            {
                if (msz < dist(convex[i], convex[t]))
                    msz = dist(convex[i], convex[t]);
                t++;
            }
            if (msz < dist(convex[i], convex[t]))
                msz = dist(convex[i], convex[t]);
        }
        return msz;
    }
};

convex_hull C;
vector <point> ptt;
int n, t;
int func(int x)
{
    C.pt.clear();
    for (int i = 0; i<n; i++)
        C.pt.push_back({ptt[i].x+ptt[i].dx*x, ptt[i].y+ptt[i].dy*x,0,0});
    C.graham_scan();
    int u = C.rotating_calipers();
    return u;
}
int32_t main()
{
    usecppio
    cin >> n >> t;
    C.n = n;
    for (int i = 0; i<n; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        ptt.push_back({a, b, c, d});
    }
    int lo = 0, hi = t;
    while(lo + 3 <= hi)
    {
        int m1 = (2*lo+hi)/3;
        int m2 = (lo+2*hi)/3;
        if (func(m1) > func(m2))
            lo = m1;
        else hi = m2;
    }
    int ind = lo;
    int best = func(lo);
    for (int i = lo; i<=hi; i++)
    {
        int cur = func(i);
        if (cur < best)
        {
            best = cur;
            ind = i;
        }
    }
    cout << ind << '\n';
    cout << best << '\n';
}