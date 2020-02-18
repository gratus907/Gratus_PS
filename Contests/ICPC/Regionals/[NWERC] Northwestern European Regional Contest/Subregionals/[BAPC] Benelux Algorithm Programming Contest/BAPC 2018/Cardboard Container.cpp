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
#define PI acos(-1.0)
using pii = pair<int, int>;

int box_area(int a, int b, int c)
{
    return 2*(a*b+b*c+c*a);
}

int32_t main()
{
    int v; cin >> v;
    int ans = 1e15;
    for (int i = 1; i<=v; i++)
    {
        if (v%i==0)
        {
            int t = v/i;
            for (int j = 1; j*j<=t; j++)
            {
                if (t%j==0)
                {
                    ans = min(ans,box_area(i,j,t/j));
                }
            }
        }
    }
    cout << ans << '\n';
}