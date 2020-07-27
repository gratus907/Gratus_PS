#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define ll long long
#define int ll
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;

int32_t main()
{
    int a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
    for (int x = -999; x<=999; x++)
    {
        for (int y = -999; y<=999; y++)
        {
            if (a*x+b*y==c && d*x+e*y==f)
            {
                cout << x << ' ' << y <<'\n';
                return 0;
            }
        }
    }
}