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
 
vector <int> min_case;
vector <int> max_case;
vector <pii> v, v2;
 
void vprint(vector <int> &a, int len)
{
    for (int i = 1; i<=len; i++)
    {
        cout << a[i] << ' ';
    }
    cout << '\n';
}
void solve()
{
    v.clear();
    v2.clear();
    min_case.clear();
    max_case.clear();
    int n;
    string s;
    cin >> n >> s;
    int minlis = 0;
    int maxlis = 1;
    int cnt = 0;
    min_case.resize(n+10);
    max_case.resize(n+10);
    for (int i = 0; i<n-1; i++)
    {
        if (s[i] == '<')
        {
            cnt++;
            maxlis++;
        }
        else
        {
            if (cnt>0)
            {
                v.push_back({i+1,cnt+1});
                minlis = max(minlis, cnt+1);
            }
            cnt = 0;
        }
    }
    v.push_back({n,cnt+1});
    minlis = max(minlis, cnt+1);
    cnt = 0;
    int cur_max = n;
    for (int i = 0; i<v.size(); i++)
    {
        pii p = v[i];
        v[i] = {p.first-p.second+1,p.first};
    }
    for (int i = 1; i<=n; i++)
    {
        min_case[i] = cur_max;
        cur_max--;
    }
    for (auto it:v)
    {
        int swaplen = it.second-it.first+1;
        for (int i = 0; i<swaplen/2; i++)
            swap(min_case[it.first+i],min_case[it.second-i]);
    }
    vprint(min_case, n);
 
 
    int cur_min = 1;
    for (int i = 0; i<n-1; i++)
    {
        if (s[i] == '>')
            cnt++;
        else
        {
            if (cnt>0)
            {
                v2.push_back({i+1,cnt+1});
            }
            cnt = 0;
        }
    }
    v2.push_back({n,cnt+1});
    for (int i = 0; i<v2.size(); i++)
    {
        pii p = v2[i];
        v2[i] = {p.first-p.second+1,p.first};
    }
    for (int i = 1; i<=n; i++)
    {
        max_case[i] = cur_min;
        cur_min++;
    }
    for (auto it:v2)
    {
        int swaplen = it.second-it.first+1;
        for (int i = 0; i<swaplen/2; i++)
            swap(max_case[it.first+i],max_case[it.second-i]);
    }
    vprint(max_case, n);
}
 
int32_t main()
{
    usecppio
    int t;
    cin >> t;
    while(t--) solve();
}
