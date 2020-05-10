#include <bits/stdc++.h>
#define int ll
#define ll long long
using namespace std;

ll n, k;
ll consum[101010];

ll find(int v)
{
    int lo = 1, hi = n;
    if (consum[n]-consum[v]<k)
    {
        return 0;
    }
    while(lo<hi)
    {
        int mid = (lo+hi)/2;
        if(consum[mid]-consum[v]>=k)
            hi = mid;
        else
            lo = mid+1;
        if(lo == hi)
            break;
    }
    return (n-lo+1);
}

int32_t main()
{
    ll ans = 0;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i<=n; i++)
    {
        ll x;
        cin >> x;
        consum[i] = consum[i-1]+x;
    }
    for (int j = 1; j<=n; j++)
    {
        ans += find(j-1);
    }
    cout << ans;
}
