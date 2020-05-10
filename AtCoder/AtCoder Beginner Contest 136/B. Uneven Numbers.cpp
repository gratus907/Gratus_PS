#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair <int, int> pii;


int main()
{
    int n;
    int ct = 0;
    cin >> n;
    for (int i = 1; i<=9; i++)
    {
        if (i<=n)
            ct++;
    }
    for (int i = 100; i<=999; i++)
    {
        if (i<=n)
            ct++;
    }
    for (int i = 10000; i<100000; i++)
    {
        if (i<=n)
            ct++;
    }
    cout << ct;
}
