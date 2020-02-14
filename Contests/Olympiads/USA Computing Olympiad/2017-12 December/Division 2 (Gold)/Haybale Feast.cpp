#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
#define MOD 1000000007
#define int ll
using pii = pair <int, int>;

int spi[101010], fla[101010];
int sumfla[101010];
pii range_ind[101010];
int n, m;
inline int rangesum(int *arr, int l, int r)
{
    return arr[r] - arr[l-1];
}
int32_t main()
{
    cin >> n >> m;
    for (int i = 1; i<=n; i++)
    {
        cin >> fla[i] >> spi[i];
        sumfla[i] = sumfla[i-1] + fla[i];
    }
    int ans = INT_MAX;
    stack <pii> s;
    s.push({spi[1],1});
    for (int i = 2; i<=n; i++)
    {
        if (s.empty())
        {
            s.push({spi[i], i});
            continue;
        }
        while (!s.empty() && s.top().first < spi[i])
        {
            range_ind[s.top().second].second = i-1;
            s.pop();
        }
        s.push({spi[i], i});
    }
    while(!s.empty())
    {
        range_ind[s.top().second].second = n;
        s.pop();
    }
    s.push({spi[n], n});
    for (int i = n-1; i>=1; i--)
    {
        if (s.empty())
        {
            s.push({spi[i], i});
            continue;
        }
        while (!s.empty() && s.top().first < spi[i])
        {
            range_ind[s.top().second].first = i+1;
            s.pop();
        }
        s.push({spi[i], i});
    }
    while(!s.empty())
    {
        range_ind[s.top().second].first = 1;
        s.pop();
    }
    for (int i = 1; i<=n; i++)
    {
        if (rangesum(sumfla,range_ind[i].first, range_ind[i].second) >= m)
        {
            ans = min(ans, spi[i]);
        }
    }
    cout << ans << '\n';
}
