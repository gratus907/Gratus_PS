#include <bits/stdc++.h>
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define int ll
const bool debug = 0;
using pii = pair<int, int>;
typedef long double D;

int32_t main()
{
    usecppio
    int n, m; cin >> n >> m;
    if (n%2==1)
        for (int i = 1; i<=m; i++)
            cout << i << ' ' << n-i << '\n';
    else
    {
        int odd = (m+1)/2;
        for (int i = 1; i<=odd; i++)
            cout << i << ' ' << n-i+1 << '\n';
        for (int i = odd+1; i<=m; i++)
            cout << i << ' ' << n-i << '\n';
    }
}
