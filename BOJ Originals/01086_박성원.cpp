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

int n, k;
int dp[65535][105];
int arr[15];
string sarr[15];
int p10[1010];

int solve(int bm, int rm) {
    if (bm == (1<<n) - 1) return (rm == 0);
    if (dp[bm][rm] != -1) return dp[bm][rm];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (bm & (1 << i)) continue;
        int nxt_bm = bm | (1 << i);
        int nxt_rm = (rm * p10[sarr[i].length()] + arr[i]) % k;
        ans += solve(nxt_bm, nxt_rm);
    }
    return dp[bm][rm] = ans;
}
int32_t main() {
    usecppio
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> sarr[i];
    }
    cin >> k;
    for (int i = 0; i < n; i++) {
        for (char c : sarr[i]) {
            arr[i] *= 10;
            arr[i] += (c - '0');
            arr[i] %= k;
        }
    }
    p10[0] = 1;
    for (int i = 1; i <= 1000; i++) p10[i] = (p10[i-1] * 10) % k;
    int ans = solve(0, 0);
    int tot = 1; for (int i = 1; i <= n; i++) tot *= i;
    int g = __gcd(ans, tot);
    cout << (ans/g) << '/' << (tot/g) << '\n';
}