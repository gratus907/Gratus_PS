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

struct cloth
{
    int t, w;
    bool operator<(const cloth& other) const
    {
        if (t == other.t) return w < other.w;
        return t < other.t;
    }
};
int n, k;
vector<cloth> C;

int solve(int t1, int t2, int t3)
{
    int s1 = 0, s2 = 0, s3 = 0;
    for (auto c : C)
    {
        if (c.t < t1) return INT_MAX;
        int dt1 = 30 + (c.t - t1)*c.w;
        int dt2 = 30 + (c.t - t2)*c.w;
        int dt3 = 30 + (c.t - t3)*c.w;
        if (c.t >= t1 && dt1 <= s1) continue;
        if (c.t >= t2 && dt2 <= s2) continue;
        if (c.t >= t3 && dt3 <= s3) continue;
        if (c.t >= t3) s3 = max(s3, dt3);
        else if (c.t >= t2) s2 = max(s2, dt2);
        else s1 = max(s1, dt1);
    }
    return s1 + s2 + s3;
}
int32_t main()
{
    usecppio
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int ti, wi; cin >> ti >> wi;
        cloth c = {ti, wi};
        C.push_back(c);
    }
    sort(all(C));
    if (k == 1)
    {
        int opT = C.front().t;
        int ans = 0;
        for (auto c : C)
            ans = max(ans,(30 + (c.t - opT) * c.w));
        cout << ans << '\n';
    }
    else if (k == 2)
    {
        int ans = INT_MAX;
        for (int t1 = 40; t1 <= 100; t1++)
            for (int t2 = t1+1; t2<=100; t2++)
                ans = min(ans, solve(t1, t2, 101));
        cout << ans << '\n';
    }
    else
    {
        int ans = INT_MAX;
        for (int t1 = 40; t1 <= 100; t1++)
            for (int t2 = t1+1; t2<=100; t2++)
                for (int t3 = t2+1; t3<=100; t3++)
                    ans = min(ans, solve(t1, t2, t3));
        cout << ans << '\n';
    }
}