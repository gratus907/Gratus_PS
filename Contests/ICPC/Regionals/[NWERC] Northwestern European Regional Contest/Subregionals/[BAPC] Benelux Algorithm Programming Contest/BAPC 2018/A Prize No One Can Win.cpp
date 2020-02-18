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

int n, x;
vector <int> v;
vector <int> p;
int32_t main()
{
    usecppio
    cin >> n >> x;
    for (int i = 0; i<n; i++)
    {
        int a; cin >> a; v.push_back(a);
    }
    sort(all(v));
    for (auto it:v)
    {
        if (p.empty()) p.push_back(it);
        else
        {
            if (p.back()+it<=x)
                p.push_back(it);
        }
    }
    cout << p.size() << '\n';
}