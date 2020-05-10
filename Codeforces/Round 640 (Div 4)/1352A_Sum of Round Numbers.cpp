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

void solve()
{
    int n;
    cin >> n;
    int t = 0;
    vector <int> v;
    while(n)
    {
        if (n%10==0)
        {
            n/=10; t++;
        }
        else
        {
            v.push_back((n%10)*pow(10,t));
            n/=10; t++;
        }
    }
    cout << v.size() << '\n';
    for (auto it:v)
    {
        cout << it << ' ';
    }
    cout << '\n';
}

int32_t main()
{
    usecppio
    int t;
    cin >> t;
    while(t--) solve();
}