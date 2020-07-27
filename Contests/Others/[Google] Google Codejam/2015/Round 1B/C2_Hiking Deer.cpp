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
const int mod = 1000000007;
const bool debug = false;
struct hike
{
    double zero;
    double slope;
    int eval(double x)
    {
        if (x <= zero) return 1;
        double d = (x-zero);
        return (int)(d*slope);
    }
};
struct info
{
    vector <hike> all_hikes;
    int eval(double x)
    {
        if (debug)
            printf("Evaluate everything at %.2lf\n",x);
        int res = 0;
        for (auto it:all_hikes)
            res += it.eval(x);
        return res;
    }
};
int solve()
{
    int n;
    cin >> n;
    info data;
    for (int i = 0; i<n; i++)
    {
        int di, hi, mi;
        cin >> di >> hi >> mi;
        for (int j = 0; j<hi; j++)
        {
            double z = (360.0 - di) / (360.0/(mi + j));
            double slope = 1.0/(mi + j);
            hike ch = {z, slope};
            data.all_hikes.push_back(ch);
        }
    }
    int m = INT_MAX;
    for (auto it:data.all_hikes)
    {
        m = min(m, data.eval(it.zero+eps));
    }
    return m;
}

int32_t main()
{
    int T = 0; cin >> T;
    for (int i = 1; i<=T; i++)
    {
        printf("Case #%lld: ",i);
        printf("%lld\n",solve());
    }
}