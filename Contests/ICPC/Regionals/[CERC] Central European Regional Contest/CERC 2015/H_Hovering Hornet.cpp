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
#define int ll
using pii = pair <int, int>;

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
};

struct line
{
    double slope, y;
    double left, right;
    pair<double, bool> eval_x(double target_y)
    {
        if (slope == 0 && target_y != y)
            return {0, false};
        double x = (target_y-y)/slope;
        bool t = (left <= x && x <= right);
        return {x, t};
    }
    pair<double, bool> eval_y(double target_x)
    {
        bool t = (left <= target_x && target_x <= right);
        return {slope*target_x+y, t};
    }
};

line segment_line(point a, point b)
{
    if (b.x-a.x == 0)
        return {1e100,-1e100*a.x, min(a.x, b.x), max(a.x, b.x)};
    double s = (b.y-a.y)/(b.x-a.x);
    double yy = a.y-a.x*s;
    return {s, yy, min(a.x, b.x), max(a.x, b.x)};
}
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
        if (calc)
            return S;
        sort_point();
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
        {
            printf("(%.4lf, %.4lf)\n",it.x,it.y);
        }
    }
};

vector <point> outer;
vector <line> sq;
int32_t main()
{
    for (int i = 0; i<4; i++)
    {
        double x, y; cin >> x >> y;
        outer.push_back({x, y});
    }
    for (int i = 0; i<4; i++)
    {
        point a = outer[i%4], b = outer[(i+1)%4];
        line s = segment_line(a, b);
        sq.push_back(s);
    }
    polygon one;
    for (int i = 0; i<4; i++)
    {
        auto p = sq[i].eval_x(-0.5);
        if (p.second)
            one.pt.push_back({p.first, -0.5});
        if (outer[i].y<-0.5)
            one.pt.push_back(outer[i]);
    }

    polygon three;
    for (int i = 0; i<4; i++)
    {
        auto p = sq[i].eval_y(0.5);
        if (p.second)
            three.pt.push_back({0.5, p.first});
        if (outer[i].x>0.5)
            three.pt.push_back(outer[i]);
    }
    polygon four;
    for (int i = 0; i<4; i++)
    {
        auto p = sq[i].eval_y(-0.5);
        if (p.second)
            four.pt.push_back({-0.5, p.first});
        if (outer[i].x<-0.5)
            four.pt.push_back(outer[i]);
    }
    polygon six;
    for (int i = 0; i<4; i++)
    {
        auto p = sq[i].eval_x(0.5);
        if (p.second)
            six.pt.push_back({p.first, 0.5});
        if (outer[i].y>0.5)
            six.pt.push_back(outer[i]);
    }
    double expect = one.area()+three.area()*3+four.area()*4+six.area()*6;
    expect *= (5.0/124.0);
    expect += (500.0/124.0);
    cout << fixed << setprecision(15) << expect << '\n';
}
