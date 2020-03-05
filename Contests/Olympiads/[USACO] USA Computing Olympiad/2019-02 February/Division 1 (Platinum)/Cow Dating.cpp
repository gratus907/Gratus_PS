#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
#define int ll
using pii = pair <int, int>;
using DB = double;
int n;
DB prob[1010100];
DB arr1[1010100];
DB arr2[1010100];
int32_t main()
{
    usecppio
    cin >> n;
    arr1[0] = 1;
    for (int i = 1; i<=n; i++)
    {
        int x;
        cin >> x;
        prob[i] = x/1000000.0;
        arr1[i] = 1-prob[i];
        arr2[i] = prob[i] / arr1[i];
    }
    int left = 1, right = 1;
    DB best_current = 0;
    DB a = 1, b = 0;
    while (left <= n)
    {
        while (right <= n && b<1)
        {
            b += arr2[right];
            a *= arr1[right];
            right++;
            best_current = max(best_current, a*b);
        }
        best_current = max(best_current, a*b);
        a /= arr1[left];
        b -= arr2[left];
        left++;
        best_current = max(best_current, a*b);
    }
    int ans = best_current*1000000;
    cout << ans << '\n';
}