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
int n, m;
bool ok[3][3];
int num[3][3];

int32_t main()
{
    for (int i = 0; i<3; i++)
        for (int j = 0; j<3; j++)
            cin >> num[i][j];
    cin >> n;
    while(n--)
    {
        int x;
        cin >> x;
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                if (x == num[i][j])
                    ok[i][j] = true;
            }
        }
    }
    for (int i = 0; i<3; i++)
    {
        if (ok[i][0] && ok[i][1] && ok[i][2])
        {
            cout << "Yes\n"; return 0;
        }
    }
    for (int i = 0; i<3; i++)
    {
        if (ok[0][i] && ok[1][i] && ok[2][i])
        {
            cout << "Yes\n"; return 0;
        }
    }
    if (ok[0][0] && ok[1][1] && ok[2][2])
    {
        cout << "Yes\n"; return 0;
    }
    if (ok[2][0] && ok[1][1] && ok[0][2])
    {
        cout << "Yes\n"; return 0;
    }
    cout << "No\n"; return 0;
}
