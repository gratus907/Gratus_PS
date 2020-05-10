#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int ll
using pii = pair<int, int>;
vector <int> coef;
vector <int> diff;

int n, k;
bool fail(int x)
{
    int u = 0;
    for (int i = 0; i<n; i++)
    {
        //printf("%lld %lld -> under %lld chal\n",coef[i], diff[i], x);
        int v = x/diff[i];
        int tmp = max(coef[i] - v, 0LL);
        //printf("%lld train\n",tmp);
        u += tmp; 
    }
    //printf("Under %lld : %lld\n",x,u);
    return (u > k);
}
int32_t main()
{
    usecppio
    int sumn = 0;
    cin >> n >> k;
    for (int i = 0; i<n; i++)
    {
        int x;
        cin >> x;
        coef.push_back(x);
        sumn += x;
    }
    for (int i = 0; i<n; i++)
    {
        int x;
        cin >> x;
        diff.push_back(x);
    }
    if (sumn <= k)
    {
        cout << 0 << '\n'; return 0;
    }
    sort(all(coef));
    sort(all(diff),greater<int>());
    int lo = 0, hi = 1e18;
    while(lo + 1 < hi)
    {
        int mid = (lo+hi)/2;
        //printf("%lld %s\n",mid,(fail(mid)?"NO":"OK"));
        if (fail(mid))
            lo = mid;
        else 
            hi = mid;
    }
    cout << hi << '\n';
}