#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
#define eps 1e-7
#pragma GCC optimize ("unroll-loops")
#define int ll
const int mod = 998244353;
using pii = pair<int, int>;

bool equal(double a, double b, double tol = 1e-12)
{
    return abs(a-b)<=tol;
}

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
    point operator*(const double C)
    {
        return {x*C, y*C};
    }
    double normsq()
    {
        return x*x+y*y;
    }
};
double ang(point p)
{
    return atan2(p.x, -1 * p.y);;
}
struct polygon
{
    vector <point> pt;
    double S;
    bool calc = false;
    void move(point new_zero)
    {
        for (int i = 0; i<pt.size(); i++)
            pt[i] = pt[i]-new_zero;
    }
    void sort_point()
    {
        auto cmp_angle = [](point &a, point &b) -> bool
        {
            return ang(a) < ang(b);
        };
        sort(all(pt),cmp_angle);
    }
    double area(bool pr = false)
    {
        double A = 0;
        int n = pt.size();
        pt.push_back(pt[0]);
        for (int i = 0; i<n; i++)
            A += (pt[i].x*pt[i+1].y-pt[i].y*pt[i+1].x);
        pt.pop_back();
        calc = true;
        return S = abs(A/2);
    }
    void print()
    {
        for (auto it:pt)
            printf("(%.4lf, %.4lf)\n",it.x,it.y);
    }
};
int n;
polygon P;
inline double sum_with_deg(double a, double b, int r)
{
    double res = 0;
    for (int i = 0; i<=r; i++)
        res += (pow(a, i)*pow(b, r-i));
    return res;
}
int32_t main()
{
    cin >> n;
    for (int i = 0; i<n; i++)
    {
        double x, y; cin >> x >> y;
        P.pt.push_back({x, y});
    }
    P.S = P.area();
    P.pt.push_back(P.pt[0]);
    double xsq = 0;
    for (int i = 0; i<n; i++)
        xsq += (sum_with_deg(P.pt[i].x, P.pt[i+1].x, 3)*(P.pt[i+1].y-P.pt[i].y));
    xsq /= 12.0;
    double ysq = 0;
    for (int i = 0; i<n; i++)
        ysq += (sum_with_deg(P.pt[i].y, P.pt[i+1].y, 3)*(P.pt[i+1].x-P.pt[i].x));
    ysq /= (-12.0);
    double xs = 0;
    for (int i = 0; i<n; i++)
        xs += (sum_with_deg(P.pt[i].x, P.pt[i+1].x, 2)*(P.pt[i+1].y-P.pt[i].y));
    xs /= 6.0;
    double ys = 0;
    for (int i = 0; i<n; i++)
        ys += (sum_with_deg(P.pt[i].y, P.pt[i+1].y, 2)*(P.pt[i+1].x-P.pt[i].x));
    ys /= (-6.0);
    double ans = 1;
    ans /= (pow(P.S,2));
    ans *= (2*P.S*xsq+2*P.S*ysq-2*xs*xs-2*ys*ys);
    cout << fixed << setprecision(20) << ans << '\n';
}