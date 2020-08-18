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
    double x, y;
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
        return {x*C, y*C};
    }
    double angle(bool radian = true)
    {
        double u = atan2(y, x);
        if (!radian)
        {
            u *= 180/PI;
            return u >= 0 ? u : 360+u;
        }
        return u >= 0? u : 2*PI + u;
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
double inner(point &a, point &b)
{
    return a.x*b.x + a.y*b.y;
}
class convex_hull
{
public:
    int n;
    static int ccw (point a, point b, point c)
    {
        double v = (b.x - a.x) * (c.y - a.y) - (b.y-a.y)*(c.x-a.x);
        if (v > 0) return 1;
        if (v == 0) return 0;
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
};

void solve()
{
    convex_hull C;
    vector <double> min_angles;
    C.n = n;
    for (int i = 0; i<n; i++)
    {
        int x, y; cin >> x >> y;
        C.pt.push_back({x*1.0, y*1.0});
    }
    C.graham_scan();
    double curbestvalue = 1e16;
    for (int i = 0; i<C.convex.size(); i++)
    {
        point p = C.convex[(i+1)%C.convex.size()];
        point q = C.convex[i];
        point r = p-q;
        double vec_angle = r.angle();
        point pp = {cos(vec_angle), sin(vec_angle)};
        point qq = {cos(vec_angle+PI/2), sin(vec_angle+PI/2)};
        double v1 = -1e16, v2 = 1e16, v3 = -1e16, v4 = 1e16;
        //printf("EDGEVECTOR : {%.2lf %.2lf} PERPENDICULAR {%.2lf %.2lf}\n",pp.x,pp.y,qq.x,qq.y);
        for (int j = 0; j<C.convex.size(); j++)
        {
            point pt = C.convex[j];
            v1 = max(v1, inner(pt, pp));
            v2 = min(v2, inner(pt, pp));
            v3 = max(v3, inner(pt, qq));
            v4 = min(v4, inner(pt, qq));
        }
        double candi = 2*((v1-v2)+(v3-v4));
        curbestvalue = min(curbestvalue, candi);
    }
    cout << setprecision(10) << fixed << curbestvalue << '\n';
}

int32_t main()
{
    usecppio
    while(!(cin >> n).eof())
        solve();
}