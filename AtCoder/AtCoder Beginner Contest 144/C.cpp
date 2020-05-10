#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int ll

int n;
int a, b;
int32_t main()
{
    cin >> n;
    for (int i = 1; i*i<=n; i++)
    {
        if (n%i==0)
        {
            a = i, b = n/i;
        }
    }
    cout << a + b -2 << '\n';
}