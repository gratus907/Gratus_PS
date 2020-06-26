#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using pii = pair<int, int>;
multiset<int> L, R;
vector <pii> cow;
int ans;
int main()
{
    usecppio
    int n, d;
    cin >> n >> d;
    for (int i = 0; i<n; i++)
    {
        int x, h; cin >> x >> h;
        cow.push_back({x, h});
    }
    sort(all(cow));
    int lpt = 0, rpt = 0;
    for (int i = 0; i<n; i++)
    {
        while(lpt < n && cow[lpt].first + d < cow[i].first)
        {
            L.erase(L.lower_bound(cow[lpt].second));
            lpt++;
        }
        L.insert(cow[i].second);
        while(rpt < n && cow[rpt].first <= cow[i].first + d)
        {
            R.insert(cow[rpt].second);
            
            rpt++;
        }
        int xm, ym;
        xm = *(--L.end());
        ym = *(--R.end());
        if (min(xm, ym)>= 2*cow[i].second)
            ans++;
        R.erase(R.lower_bound(cow[i].second));
    }
    cout << ans << '\n';
}