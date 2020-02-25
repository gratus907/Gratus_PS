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
    double _time;
    double zero;
    double _nxt;
    int ind;
    const bool operator<(const hike & other) const
    {
        return _time > other._time;
    }
};
struct info
{
    int encounter;
    int min_c;
    double T;
    int event_count;
    priority_queue<hike> pq;
    int minimum_encounter()
    {
        event_count = 0;
        T = 0;
        min_c = INT_MAX;
        encounter = pq.size();
        while (event_count < pq.size()*3)
        {
            while(T == pq.top()._time)
            {
                hike h = pq.top();
                pq.pop();
                T = h._time;
                if (h._time == h.zero)
                    encounter--;
                else
                    encounter++;
                h._time += h._nxt;
                pq.push(h);
                event_count++;
            }
            T = pq.top()._time;
            min_c = min(min_c, encounter);
        }
        return min_c;
    }
};
int solve()
{
    usecppio
    int n;
    cin >> n;
    info data;
    int ct = 1;
    for (int i = 0; i<n; i++)
    {
        int di, hi, mi;
        cin >> di >> hi >> mi;
        for (int j = 0; j<hi; j++)
        {
            double z = (360.0 - di) / (360.0 / (mi + j));
            double dt = (mi + j);
            hike nh = {z, z, dt, ct};
            ct++;
            data.pq.push(nh);
        }
    }
    return data.minimum_encounter();
}

int32_t main()
{
    usecppio
    int T = 0; cin >> T;
    for (int i = 1; i<=T; i++)
    {
        printf("Case #%lld: ",i);
        printf("%lld\n",solve());
    }
}