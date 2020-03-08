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
struct point
{
    double x, y;
};

double inner(point a, point b)
{
    return a.x*b.x+a.y*b.y;
}
int n;
vector <point> P;
int32_t main()
{
    usecppio
    int tc = 1;
    while(true)
    {
        P.clear();
        cin >> n;
        if (!n) return 0;
        for (int i = 0; i<n; i++)
        {
            double x, y; cin >> x >> y;
            P.push_back({x, y});
        }
        double minmax = 1e18;
        for (int j = 0; j<n; j++)
        {
            for (int k = j+1; k<n; k++)
            {
                double m = 0;
                point up;
                if (P[j].y==P[k].y)
                    up = {0, 1};
                else if (P[j].x==P[k].x)
                    up = {1, 0};
                else
                {
                    double slope = (P[k].y-P[j].y)/(P[k].x-P[j].x);
                    slope = -1/slope;
                    double len = sqrt(1+slope*slope);
                    up = {1/len, slope/len};
                }
                double t1 = 1e10, t2 = -1e10;
                for (int i = 0; i<n; i++)
                {
                    double tt = inner(up, P[i]);
                    t1 = min(tt, t1);
                    t2 = max(tt, t2);
                }
                m = abs(t1-t2);
                minmax = min(m, minmax);
            }
        }
        printf("Case %lld: %.2lf\n",tc,minmax+0.005-eps);
        tc++;
    }
}