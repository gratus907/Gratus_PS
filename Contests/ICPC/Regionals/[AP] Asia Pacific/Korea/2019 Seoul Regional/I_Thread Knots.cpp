#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
using pii = pair<int, int>;
pii arr[101010];
int n;

bool able(int x)
{
    int cur = arr[0].first;
    for (int i = 1; i<n; i++)
    {
        int u = cur+x;
        if (u > arr[i].second)
        {
            return false;
        }
        cur = max(u,arr[i].first);
    }
    return true;
}
int32_t main()
{
    cin >> n;
    for (int i = 0; i<n; i++)
    {
        int t;
        cin >> arr[i].first >> t;
        arr[i].second = arr[i].first + t;
    }
    sort(arr, arr+n);
    int lo = 0, hi = 1e10; 
    while(lo + 1 < hi)
    {
        int mid = (lo + hi)/2;
        if (able(mid))
            lo = mid;
        else hi = mid;
    }
    cout << lo << '\n';
}