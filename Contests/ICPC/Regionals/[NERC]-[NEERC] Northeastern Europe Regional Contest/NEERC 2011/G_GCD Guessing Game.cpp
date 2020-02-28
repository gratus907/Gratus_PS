#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
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

bool is_prime(int x)
{
    for (int i = 2; i*i<=x; i++)
    {
        if (x%i==0)
            return false;
    }
    return true;
}
deque <int> ps;
int32_t main()
{
    int n; cin >> n;
    int ans = 0;
    ps.push_back(2);
    for (int i = 3; i<=n; i+=2)
        if (is_prime(i))
            ps.push_back(i);
    while(!ps.empty())
    {
        int cur = ps.back();
        ps.pop_back();
        while (!ps.empty() && cur*ps.front()<=n)
        {
            cur *= ps.front();
            ps.pop_front();
        }
        ans++;
    }
    cout << ans << '\n';
}