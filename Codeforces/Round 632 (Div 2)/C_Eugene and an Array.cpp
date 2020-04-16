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
const bool debug = 0;
map<int, vector<int>> mp;
int arr[202020];
deque <pii> zero;
multiset<int> endpoints;
int32_t main()
{
    usecppio
    int n; cin >> n;
    int cur = 0;
    for (int i = 1; i<=n; i++) cin >> arr[i];
    for (int i = 1; i<=n; i++)
    {
        mp[cur].push_back(i);
        cur += arr[i];
    }
    mp[cur].push_back(n+1);
    for (auto it:mp)
    {
        vector <int> u = it.second;
        if (u.size()<=1) continue;
        else
        {
            for (int i = 1; i<u.size(); i++)
            {
                zero.push_back({u[i-1], u[i]});
                endpoints.insert(u[i]);
            }
        }
    }
    endpoints.insert(n+2);
    sort(all(zero));
    int ans = 0;
    for (int i = 1; i<=n; i++)
    {
        while(!zero.empty() && zero.front().first<i)
        {
            if (debug)
                printf("Passed {%lld, %lld}\n",zero.front().first, zero.front().second);
            endpoints.erase(endpoints.lower_bound(zero.front().second));
            zero.pop_front();
        }
        if (debug)
        {
            printf("Print all endpoints\n");
            for (auto it:endpoints)
            {
                cout << it << '\n';
            }
        }
        int end_pos = *(endpoints.begin())-1;
        if (debug)
            printf("End pos for ele %lld = %lld\n",i,end_pos);
        ans += end_pos-i;
    }
    cout << ans << '\n';
}