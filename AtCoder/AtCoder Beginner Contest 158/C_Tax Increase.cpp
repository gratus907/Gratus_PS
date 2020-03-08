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

int32_t main()
{
    int a, b; cin >> a >> b;
    for (int i = 1; i<=100000; i++)
    {
        if ((int)(i*0.08) == a)
        {
            if ((int)(i*0.10) == b)
            {
                cout << i << '\n';
                return 0;
            }
        }
    }
    cout << -1 << '\n';
}
