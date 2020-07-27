#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int upper = 1e12, lower = -1e12, pre, cur;

int32_t main()
{
    usecppio
    int n; cin >> n;
    for (int i = 0; i<n; i++)
    {
        cin >> cur;
        cur = 2*cur - pre;
        if (i % 2 == 0)
            upper = min(upper, (cur-pre)/2);
        else
            lower = max(lower, (pre-cur)/2);
        pre = cur;
    }
    cout << max(upper-lower+1, 0ll) << '\n';
}