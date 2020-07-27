#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;

void solve()
{
    string str;
    cin >> str;
    vector <int> v;
    v.push_back(0);
    for (auto it:str)
        v.push_back(it-'0');
    string ans;
    for (int i = 1; i<v.size(); i++)
    {
        int u = v[i]-v[i-1];
        if (u < 0)
        {
            for (int t = 0; t<-u; t++)
                ans.push_back(')');
        }
        else
        {
            for (int t = 0; t<u; t++)
                ans.push_back('(');
        }
        ans.push_back(v[i]+'0');
    }
    int u = -v[v.size()-1];
    if (u < 0)
    {
        for (int t = 0; t<-u; t++)
            ans.push_back(')');
    }
    cout << ans << '\n';
}

int32_t main()
{
    int t;
    cin >> t;
    int tc = 1;
    while(t--)
    {
        printf("Case #%d: ",tc);
        tc++;
        solve();
    }
}