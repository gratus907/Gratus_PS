#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using pii = pair<int, int>;
int k, n;
vector <pii> fac;
int seen[101010];
int32_t main()
{  
    usecppio
    cin >> k >> n;
    for (int i = 0; i<n; i++)
    {
        int a, b; cin >> a >> b;
        fac.push_back({a, b});
    }
    sort(all(fac));
    int l = 0, r = 0;
    int cnt = 0;
    int lft = INT_MAX, cur = 0;
    while(r < n)
    {
        if (!seen[fac[r].second])
            cnt++;
        seen[fac[r].second]++;
        r++;
        if (cnt == k)
        {
            while(true)
            {
                int t = fac[r-1].first-fac[l].first+1;
                t /= 2;
                if (t < lft)
                {
                    lft = t;
                    cur = fac[r-1].first-t;
                }
                seen[fac[l].second]--;
                if (seen[fac[l].second]==0)
                    cnt--;
                l++;
                if (cnt < k) break;
            }            
        }
    }
    cout << cur << '\n';
}   