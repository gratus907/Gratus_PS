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

int n, x;
int k;
int arr[1010100];
int32_t main()
{
    usecppio
    cin >> n >> x;
    for (int i = 2; i<=n; i++)
        k += (n-i);
    k -= x;
    if (k < 0)
    {
        cout << -1 << '\n'; return 0;
    }
    int cur = n-1;
    int pt = 2;
    arr[1] = n;
    while(k>=cur)
    {
        arr[pt] = n-pt+1;
        pt++;
        k -= (cur-1);
        cur--;
    }
    for (int i = pt; i<=n; i++)
    {
        arr[i] = i-pt+1;
    }
    int b = n;
    while(k)
    {
        swap(arr[b], arr[b-1]);
        k--; b--;
    }
    for (int i = 1; i<=n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}