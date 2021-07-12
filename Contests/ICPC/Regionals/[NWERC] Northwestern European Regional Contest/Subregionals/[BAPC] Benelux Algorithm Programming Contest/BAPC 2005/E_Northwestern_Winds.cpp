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

const int N = 101010;

struct segtree
{
    using elem = int;
    int n;
    elem T[2*N];

    inline elem agg(elem a, elem b) {
        return a + b;
    }

    void build(vector<elem> &v) {
        n = v.size();
        for (int i = 0; i<n; i++)
            T[n+i] = v[i];
        for (int i = n-1; i>0; i--)
            T[i] = agg(T[i<<1], T[(i<<1)|1]);
    }

    void modify(int pos, elem val) {
        for (T[pos += n] += val; pos > 1; pos >>= 1)
            T[pos >> 1] = agg(T[pos], T[pos^1]);
    }

    // query is on [l, r)!!
    elem query(int l, int r) {
        int res = 0;
        for (l += n, r += n; l < r; l >>=1, r>>=1) {
            if (l & 1) res = agg(res, T[l++]);
            if (r & 1) res = agg(res, T[--r]);
        }
        return res;
    }
};

void solve() {
    int n; cin >> n;
    vector <pii> isl;
    vector <pii> comp;
    vector <int> vx, vy;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        isl.push_back({x, y});
        vx.push_back(x); vy.push_back(y);
    }
    sort(all(vx));
    vx.erase(unique(all(vx)), vx.end());
    sort(all(vy));
    vy.erase(unique(all(vy)), vy.end());
    for (int i = 0; i < n; i++) {
        int xid = lower_bound(all(vx), isl[i].first) - vx.begin();
        int yid = vy.size() - 1 - (lower_bound(all(vy), isl[i].second) - vy.begin());
        comp.push_back({xid, yid});
    }
    segtree S; S.n = vx.size();
    memset(S.T, 0, sizeof(S.T));
    int ans = 0;
    sort(all(comp), [](pii p, pii q) -> bool {
        if (p.second == q.second) {
            return p.first > q.first;
        }
        return p.second > q.second;
    });
    for (pii p : comp) {
        S.modify(p.first, 1);
        ans += S.query(p.first, S.n);
    }
    cout << ans - n << '\n';
}
int32_t main() {
    usecppio
    int T; cin >> T;
    while(T--) {
        solve();
    }
}
