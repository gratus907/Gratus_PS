#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
#define eps 1e-7
#define int ll
using pii = pair <int, int>;

vector <pair<string, int>> vs;
void solve()
{
    vs.clear();
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i<n; i++)
    {
        string t = s.substr(0, i);
        if ((n-i)%2==1)
            reverse(all(t));
        string u = s.substr(i)+t;
        vs.push_back({u,i+1});
    }
    sort(all(vs));
    cout << vs.front().first << '\n';
    cout << vs.front().second << '\n';
}

int32_t main()
{
    usecppio
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}