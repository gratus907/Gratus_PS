#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,a,b;
vector <ll> v;

bool check(ll t)
{
    ll u = a-b;
    ll ans = 0;
    for (auto it:v)
    {
        if (it <= t*b)
            continue;
        else
            ans += ((it-t*b)/u + (((it-t*b)%u) ? 1 : 0));
    }
    if (ans <= t)
        return true;
    else
        return false;
}

int main()
{
    scanf("%d%d%d",&n,&a,&b);
    for (int i = 0; i<n; i++)
    {
        ll h;
        scanf("%lld",&h);
        v.push_back(h);
    }
    int lo = 0, hi = 1000000000;
    while(lo<hi)
    {
        int mid = (lo+hi)/2;
        if (check(mid))
            hi = mid;
        else
            lo = mid+1;
        if (hi==lo)
            break;
    }
    printf("%d",lo);
}
