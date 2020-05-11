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

int n, x, y, c;

int f(int t)
{
    int ans = 1;
    ans += min(t, x-1);
    ans += min(t, y-1);
    ans += min(t, n-x);
    ans += min(t, n-y);
    int k = min(t, x);
    for (int i = 1; i<k; i++)
    {
        ans += min(t-i, y-1);
        ans += min(t-i, n-y);
    }
    k = min(t, n-x+1);
    for (int i = 1; i<k; i++)
    {
        ans += min(t-i, y-1);
        ans += min(t-i, n-y);
    }
    return ans;
}
int32_t main()
{
    usecppio
    cin >> n >> x >> y >> c;
    int lo = -1, hi = 101010;
    while (lo + 1 < hi)
    {
        int mid = (lo+hi)/2;
        int k = f(mid);
        if (k>=c)
            hi = mid;
        else lo = mid;
    }
    cout << hi << '\n';
    return 0;
}