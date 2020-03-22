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
#define roundz(x,d) ((floor(((x)*pow(10,d))+.5))/pow(10,d)
using pii = pair <int, int>;
using pdd = pair<double, double>;

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
        double A = 0;
        int n = pt.size();
        pt.push_back(pt[0]);
        for (int i = 0; i<n; i++)
            A += (pt[i].x*pt[i+1].y-pt[i].y*pt[i+1].x);
        pt.pop_back();
        calc = true;
        return S = abs(A/2);
    }
};

polygon P;
int32_t main()
{
    usecppio
    int n; cin >> n;
    for (int i = 0; i<n; i++)
    {
        double x, y;
        cin >> x >> y;
        P.pt.push_back({x, y});
    }
    printf("%.1lf\n", P.area());
}