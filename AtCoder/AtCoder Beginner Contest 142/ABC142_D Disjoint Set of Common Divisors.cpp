#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int ll

int n, m, g;
int32_t main()
{
    cin >> n >> m;
    g = __gcd(n,m);
    int ct = 1;
    for (int i = 2; i<=1000000; i++)
    {
        if (g%i==0)
        {
            while(g%i==0)
                g/=i;
            ct++;
        }
    }
    if (g > 1)
        ct++;
    cout << ct << '\n';    
}