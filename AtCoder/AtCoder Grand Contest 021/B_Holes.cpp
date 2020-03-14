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
#define INF 0x7f7f7f7f7f7f7f7f
using D = long double;
const bool debug = false;
const D PI = acos(-1.0);
struct point
{
    D x, y;
    int index;
    point(D a, D b, int ind)
    {
        x = a, y = b;
        index = ind;
    }
};
class convex_hull
{
public:
    int n;
    int ccw (point &a, point &b, point &c)
    {
        D v = (b.x - a.x) * (c.y - a.y) - (b.y-a.y)*(c.x-a.x);
        if (v > 0) return 1;
        if (!v) return 0;
        return -1;
    }
    static bool compy (point &a, point &b)
    {
        if (a.y == b.y) return a.x < b.x;
        return a.y < b.y;
    }
    static bool compang(point &a, point &b)
    {
        if (a.y*b.x == a.x*b.y) return compy(a, b);
        return a.y*b.x < a.x*b.y;
    }
    vector <point> pt;
    vector <point> convex;
    void graham_scan()
    {
        sort(all(pt),compy);
        point down = pt[0];
        for (int i = 0; i<n; i++)
        {
            pt[i].x -= down.x;
            pt[i].y -= down.y;
        }
        sort(all(pt), compang);
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

convex_hull CV;
int n;
D prob[120];
struct vt
{
    D dx = 0, dy = 0;
    D inner(vt a)
    {
        return dx*a.dx+dy*a.dy;
    }
    D norm()
    {
        return sqrt(dx*dx+dy*dy);
    }
};
int32_t main()
{
    usecppio
    cin >> n;
    CV.n = n;
    for (int i = 0; i<n; i++)
    {
        D x, y;
        cin >> x >> y;
        CV.pt.push_back({x, y, i});
    }
    CV.graham_scan();
    CV.convex.push_back(CV.convex[0]);
    CV.convex.push_back(CV.convex[1]);
    int m = CV.convex.size();
    for (int i = 1; i<m-1; i++)
    {
        point a = CV.convex[i];
        point b = CV.convex[i-1];
        point c = CV.convex[i+1];
        vt A = {b.x-a.x, b.y-a.y};
        vt B = {c.x-a.x, c.y-a.y};
        D cth = A.inner(B)/(A.norm()*B.norm());
        D tha = acos(cth);
        if (tha < 0) tha = 0;
        if (tha > PI) tha = PI;
        prob[a.index] = (PI-tha)/(2*PI);
    }
    for (int i = 0; i<n; i++)
        cout << fixed << setprecision(20)<< prob[i] << '\n';
}
