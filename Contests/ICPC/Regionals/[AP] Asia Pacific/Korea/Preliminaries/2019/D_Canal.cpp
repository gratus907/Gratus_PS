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

int n;
struct point
{
    double x, y;
    bool operator<(const point &other)
    {
        return x < other.x;
    }
};
vector <point> pts;
deque <int> dq;
double fM[303030], fm[303030], bM[303030], bm[303030];
int fI, bI;
inline double maxgap()
{
    if (fI < 0)
    {
        if (bI >= n)
            return 0;
        else return bM[bI]-bm[bI];
    }
    else if (bI >= n)
    {
        return fM[fI]-fm[fI];
    }
    return max(fM[fI], bM[bI])-min(fm[fI],bm[bI]);
}

bool ok(double d)
{
    dq.clear();
    for (int i = 0; i<n; i++)
    {
        if (dq.empty())
            dq.push_back(i);
        else
        {
            while(!dq.empty() && (pts[i].x > pts[dq.front()].x + 2*d))
                dq.pop_front();
            dq.push_back(i);
        }
        fI = dq.front()-1;
        bI = dq.back()+1;
        double md = maxgap();
        if (md <= 2*d)
            return true;
    }
    return false;
}
int32_t main()
{
    usecppio
    cin >> n;
    for (int i = 0; i<n; i++)
    {
        int x, y; cin >> x >> y;
        pts.push_back({x*1.0, y*1.0});
    }
    sort(all(pts));
    fM[0] = fm[0] = pts[0].y;
    for (int i = 1; i<n; i++)
    {
        fM[i] = max(fM[i-1], pts[i].y);
        fm[i] = min(fm[i-1], pts[i].y);
    }
    bM[n-1] = bm[n-1] = pts[n-1].y;
    for (int i = n-2; i>=0; i--)
    {
        bM[i] = max(bM[i+1], pts[i].y);
        bm[i] = min(bm[i+1], pts[i].y);
    }
    double hi = 1e9, lo = 0;
    while(abs(hi - lo) >= 1e-2)
    {
        double mid = (lo + hi)/2;
        if (ok(mid))
            hi = mid;
        else lo = mid;
    }
    cout << fixed << setprecision(1) << lo << '\n';
}