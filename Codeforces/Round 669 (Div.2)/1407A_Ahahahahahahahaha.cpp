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

int arr[1010];
void solve()
{
    int a, b;
    a = b = 0;
    int n; cin >> n;
    memset(arr, -1, sizeof(arr));
    for (int i = 1; i<=n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 1) a++;
        else b++;
    }
    if (a > b)
    {
        int k = a;
        if (k%2 == 1) k--;
        cout << k << '\n';
        for (int i = 0; i<k; i++)
            cout << 1 << ' ';
    }
    else
    {
        cout << b << '\n';
        for (int i = 0; i<b; i++)
            cout << 0 << ' ';
    }
    cout << '\n';
}

int32_t main()
{
    usecppio
    int t;
    cin >> t;
    while(t--) solve();
}