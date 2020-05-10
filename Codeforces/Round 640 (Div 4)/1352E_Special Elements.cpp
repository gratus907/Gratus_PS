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
    vector<int> cnt(8080, 0);
    int arr[8080], acc[8080];
    memset(arr, 0, sizeof(arr));
    memset(acc, 0, sizeof(acc));
    for (int i = 1; i<=n; i++)
    {
        cin >> arr[i];
        acc[i] = acc[i-1]+arr[i];
    }
    for (int i = 1; i<=n; i++)
        for (int j = 0; j<i-1; j++)
            if (0 <= acc[i]-acc[j] && acc[i]-acc[j] <= 8000)
                cnt[acc[i]-acc[j]]++;
    int ans = 0;
    for (int i = 1; i<=n; i++)
    {
        if (cnt[arr[i]]) ans++;
    }
    cout << ans << '\n';
}

int32_t main()
{
    usecppio
    int t;
    cin >> t;
    while(t--)
        solve();
}