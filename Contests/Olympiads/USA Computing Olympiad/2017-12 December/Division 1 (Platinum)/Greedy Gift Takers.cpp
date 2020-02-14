#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int n;
int greed[101010];

bool ok(int x)
{
    ordered_set S;
    int ct[101010]; memset(ct, 0, sizeof(ct));
    for (int i = 1; i<=x; i++)
    {
        S.insert({greed[i], ct[greed[i]]});
        ct[greed[i]]++;
    }
    for (int i = 1; i<=n; i++)
    {
        int u = S.order_of_key({i+1, -1});
        if (u >= i)
            return false;
    }
    return true;
}

int32_t main()
{
    cin >> n;
    for (int i = 1; i<=n; i++)
    {
        cin >> greed[i];
        greed[i] = n-greed[i];
    }
    int lo = 1, hi = n+1;
    while (lo + 1 < hi)
    {
        int mid = (lo + hi)/2;
        if (ok(mid))
            lo = mid;
        else hi = mid;
    }
    cout << n-hi << '\n';
}