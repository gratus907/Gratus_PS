#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#define ll long long
#define gcd(A,B) (__gcd(A,B))
using namespace std;

typedef pair <int, int> pii;
const double PI = 3.1415926525892932;
const double eps = 0.000001;
int n;
const double radconv = 180/PI;
struct Point
{
    Point(ll x, ll y)
    {
        this->x = x;
        this->y = y;
    }
    ll x;
    ll y;
};
vector <Point> pt;

ll dist_from_0 (Point p)
{
    return p.x*p.x + p.y*p.y;
}
double cross(Point p1, Point p2)
{
    return p1.x*p2.y-p1.y*p2.x;
}

int main()
{
    scanf("%d",&n);
    ll cur_dist = 0;
    for (int i = 0; i<n; i++)
    {
        ll x, y;
        scanf("%lld %lld",&x,&y);
        Point pp = Point(x,y);
        ll dist = dist_from_0(pp);
        if (dist>cur_dist)
        {
            cur_dist = dist;
            pt.clear();
            pt.push_back(pp);
        }
        else if (dist==cur_dist)
            pt.push_back(pp);
        else
            continue;
    }
    if (pt.size()==1)
    {
        printf("360.0");
        return 0;
    }
    int s = pt.size();
    pt.push_back(pt[0]);
    double maxang = 0;
    for (int i = 0; i<s; i++)
    {
        double t = acos((pt[i].x*pt[i+1].x + pt[i].y*pt[i+1].y)/(1.0*cur_dist));
        ll cr = cross(pt[i],pt[i+1]);
        if (cr<0)
            t = 2*PI-t;
        maxang = max(maxang,t);
    }
    printf("%.10lf",maxang*180/PI);
}