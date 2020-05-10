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
using pii = pair<int, int>;

void solve()
{
    int n; cin >> n;
    if (n <= 3)
    {
        cout << -1 << '\n'; return;
    }
    if (n == 4)
    {
        printf("3 1 4 2\n");
        return;
    }
    if (n == 5)
    {
        printf("5 3 1 4 2\n");
        return;
    }
    if (n%2==0)
    {
        for (int i = 0; i<n/2; i++)
            printf("%lld ",n-i*2);
        printf("5 1 3 ");
        for (int i = 7; i<n; i+=2)
            printf("%lld ",i);
        printf("\n");
    }
    else
    {
        for (int i = 0; i<=n/2; i++)
            printf("%lld ",n-i*2);
        printf("4 2 ");
        for (int i = 6; i<n; i+=2)
            printf("%lld ",i);
        printf("\n");
    }
}

int32_t main()
{
    int t;
    cin >> t;
    while(t--)
        solve();
}