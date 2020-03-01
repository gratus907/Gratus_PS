#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;
vector <int> num;
int n, m;
int32_t main()
{
    cin >> n >> m;
    num.resize(n);
    fill(all(num),-1);
    while(m--)
    {
        int s, c;
        cin >> s >> c;
        if (num[s-1]!=-1 && num[s-1]!=c)
        {
            cout << -1 << '\n';
            return 0;
        }
        num[s-1] = c;
    }
    if (n == 1)
    {
        for (int i = 0; i<=9; i++)
        {
            if (num[0]==i || num[0] == -1)
            {
                cout << i << '\n';
                return 0;
            }
        }
    }
    if (n == 2)
    {
        for (int i = 10; i<=99; i++)
        {
            if ((num[0]==i/10 || num[0] == -1) && (num[1]==i%10 || num[1] == -1))
            {
                cout << i << '\n';
                return 0;
            }
        }
    }
    if (n == 3)
    {
        for (int i = 100; i<=999; i++)
        {
            if ((num[0]==i/100 || num[0] == -1) && (num[1]==((i%100)/10) || num[1] == -1) && (num[2]==i%10 || num[2] == -1))
            {
                cout << i << '\n';
                return 0;
            }
        }
    }
    cout << -1 << '\n';
    return 0;
}
