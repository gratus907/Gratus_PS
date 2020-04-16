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

vector <int> a, b;
bool solve()
{
    int n; cin >> n;
    a.clear(); b.clear();
    a.resize(n), b.resize(n);
    vector <int> vind[2];
    for (int i = 0; i<n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
            vind[0].push_back(i);
        else if (a[i] == -1)
            vind[1].push_back(i);
    }
    for (int i = 0; i<n; i++)
        cin >> b[i];
    for (int i = n-1; i>=0; i--)
    {
        if (!vind[0].empty() && vind[0].back()==i) vind[0].pop_back();
        if (!vind[1].empty() && vind[1].back()==i) vind[1].pop_back();
        if (b[i]-a[i]==0)
            continue;
        else if (b[i]-a[i]>0)
        {
            if (vind[0].empty())
                return false;
        }
        else if (b[i]-a[i]<0)
        {
            if (vind[1].empty())
                return false;
        }
    }
    return true;
}

int32_t main()
{
    usecppio
    int t;
    cin >> t;
    while(t--)
    {
        cout << (solve()?"YES\n":"NO\n");
    }
}