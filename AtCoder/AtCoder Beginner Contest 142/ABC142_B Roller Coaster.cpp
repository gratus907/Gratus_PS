#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main()
{
    int n, h;
    cin >> n >> h;
    int ct = 0;
    for (int i = 1; i<=n; i++)
    {
        int x;
        cin >> x;
        if (x >= h)
            ct++;
    }
    cout << ct;
}