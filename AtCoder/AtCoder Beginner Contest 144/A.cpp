#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main()
{
    int a, b;
    cin >> a >> b;
    if (1 <= a && a <= 9)
    {
        if (1 <= b && b <= 9)
        {
            cout << a*b << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}