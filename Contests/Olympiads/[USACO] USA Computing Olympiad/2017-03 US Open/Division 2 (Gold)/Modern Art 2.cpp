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

int n, ans;
pii color[101010];
int arr[101010];
int stk[201010];
vector <pii> v;
int32_t main()
{
    usecppio
    cin >> n;
    for (int i = 1; i<=100000; i++)
        color[i] = {INT_MAX, -1};
    for (int i = 1; i<=n; i++)
    {
        cin >> arr[i];
        color[arr[i]].first = min(color[arr[i]].first, i*2);
        color[arr[i]].second = max(color[arr[i]].second, i*2+1);
    }
    for (int i = 1; i<=n; i++)
    {
        if (color[i].first == INT_MAX)
            continue;
        v.push_back(color[i]);
        stk[color[i].first] = 1;
        stk[color[i].second] = -1;
    }
    sort(all(v));
    for (int i = 1; i<v.size(); i++)
    {
        if (v[i].first < v[i-1].second)
        {
            if (v[i].second > v[i-1].second)
            {
                goto hell;
            }
        }
    }
    for (int i = 1; i<=2*n+2; i++)
    {
        stk[i] += stk[i-1];
        if (stk[i] < 0)
            goto hell;
        ans = max(ans, stk[i]);
    }
    if (stk[2*n+2]!=0)
        goto hell;
    cout << ans << '\n';
    return 0;
hell:
    cout << -1 << '\n';
    return 0;
}