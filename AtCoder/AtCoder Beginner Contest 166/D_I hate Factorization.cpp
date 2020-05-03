#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
#define int ll
using pii = pair <int, int>;
#define INF 0x7f7f7f7f7f7f7f7f
const bool debug = 0;
const int mod = 1000000007;

int possible[401];
int32_t main()
{
    usecppio
    int X; cin >> X;
    for (int i = -200; i<=200; i++)
        possible[i+200] = i*i*i*i*i;
    for (int i = -200; i<=200; i++)
    {
        for (int j = -200; j<=200; j++)
        {
            if (possible[i+200]-possible[j+200]==X)
            {
                cout << i << " " << j << '\n';
                return 0;
            }
        }
    }
}
