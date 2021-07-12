#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
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
using namespace __gnu_pbds;

const int N = 202020;
struct segtree
{
    using elem = int;
    int n;
    elem T[2*N];

    inline elem agg(elem a, elem b) {
        return max(a, b);
    }

    void build(vector<elem> &v) {
        n = v.size();
        for (int i = 0; i<n; i++)
            T[n+i] = v[i];
        for (int i = n-1; i>0; i--)
            T[i] = agg(T[i<<1], T[(i<<1)|1]);
    }
    void modify(int pos, int val) {
        for (T[pos += n] = val; pos > 1; pos >>= 1)
            T[pos >> 1] = agg(T[pos], T[pos^1]);
    }
    // query is on [l, r)!!
    elem query(elem l, elem r){
        elem res = 0;
        for (l += n, r += n; l < r; l >>=1, r>>=1) {
            if (l & 1) res = agg(T[l++], res);
            if (r & 1) res = agg(T[--r], res);
        }
        return res;
    }
} s;

int dp[202020];

void solve() {
    for (int i = 0; i < N; i++)
        s.T[i] = s.T[i+N] = dp[i] = 0;
    int n; cin >> n;
    s.n = n;
    vector <pii> arr(n);
    vector <int> dp1(n), dp2(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        arr[i] = {x, i};
    }
    if (n == 1) {
        cout << 1 << '\n'; return;
    }
    dp1[0] = dp2[n-1] = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i].first > arr[i-1].first) dp1[i] = dp1[i-1] + 1;
        else dp1[i] = 1;
    }
    for (int i = n-2; i >= 0; i--) {
        if (arr[i].first < arr[i+1].first) dp2[i] = dp2[i+1] + 1;
        else dp2[i] = 1;
    }
    sort(all(arr), [](pii a, pii b)->bool {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    });
    int ans = 0;
    for (int i = n-1; i >= 0; i--) {
        int u = arr[i].second;
        int q = s.query(u, n);
        s.modify(u, dp2[u]);
        dp[u] = dp1[u] + q;
        ans = max(ans, dp[u]);
    }
    cout << ans << '\n';
}

int32_t main()
{
    usecppio
    int T; cin >> T;
    while(T--) {
        solve();
    }
}