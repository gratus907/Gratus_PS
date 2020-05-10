#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#define ll long long
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair <int, int> pii;

int n, I;
vector <int> arr;
vector <int> uniqarr;
int maxk, maxdistinct;

bool chk(int l, int r)
{
    int u = (upper_bound(uniqarr.begin(),uniqarr.end(),r) - lower_bound(uniqarr.begin(),uniqarr.end(),l));
    return (u <= maxdistinct);
}

int32_t main()
{
    usecppio
    cin >> n >> I;
    arr.reserve(n);
    for (int i = 0; i<n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end());
    uniqarr = arr;
    uniqarr.erase(unique(uniqarr.begin(),uniqarr.end()),uniqarr.end());
    int totalbit = 8*I;
    maxk = totalbit / n;
    if (maxk >= 19)
    {
        cout << 0 << '\n';
        return 0;
    }
    maxdistinct = (1<<maxk);
    if (maxdistinct >= uniqarr.size())
    {
        cout << 0 << '\n';
        return 0;
    }
    int ans = n;
    for (auto it:uniqarr)
    {
        int lo = it, hi = 1e9;
        if (chk(it, 1e9))
        {
            int newans = n - (arr.end() - lower_bound(arr.begin(),arr.end(),it));
            ans = min(ans, newans);
            continue;
        }
        while(lo+1 < hi)
        {
            int mid = (lo + hi) / 2;
            if (chk(it, mid))
                lo = mid;
            else
                hi = mid;
        }
        int newans = (upper_bound(arr.begin(),arr.end(),lo) - lower_bound(arr.begin(),arr.end(),it));
        newans = n - newans;
        ans = min(ans, newans);
    }
    cout << ans << '\n';
}
