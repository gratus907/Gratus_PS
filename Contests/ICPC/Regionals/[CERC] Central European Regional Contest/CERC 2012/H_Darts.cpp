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
using pii = pair <int, int>;
using pdd = pair<double, double>;

int32_t main()
{
    usecppio
    int t; cin >> t;
    while(t--)
    {
        int sc = 0;
        int n; cin >> n;
        for (int i = 0; i<n; i++)
        {
            int x, y; cin >> x >> y;
            double u = sqrt(x*x+y*y);
            for (int j = 10; j>0; j--)
            {
                if (u <= j*20)
                    sc++;
            }
        }
        cout << sc << '\n';
    }
}