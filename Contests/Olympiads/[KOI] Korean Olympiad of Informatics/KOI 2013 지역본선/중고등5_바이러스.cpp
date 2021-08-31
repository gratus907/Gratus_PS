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

const int mod = 1000000007;
struct vectorHash {
    vector <int> s;
    int k;
    set <pii> hashset;
    void buildHash() {
        int n = s.size();
        for (int i = 0; i < n-k+1; i++) {
            int h = 0;
            int h2 = 0;
            for (int j = 0; j < k; j++) {
                h *= 10243; h += s[i+j]; h %= mod;
                h2 *= 10069; h2 += s[i+j]; h2 %= mod;
            }
            hashset.insert({h, h2});
        }
    }
};

vectorHash orig[101], rev[101];
set <pii> targ[101];
int32_t main() {
    usecppio
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int l; cin >> l;
        vector <int> v;
        for (int j = 0; j < l; j++) {
            int x; cin >> x;
            v.push_back(x);
        }
        orig[i].s = v;
        reverse(all(v));
        rev[i].s = v;
        orig[i].k = rev[i].k = k;
        orig[i].buildHash(); rev[i].buildHash();
        for (auto it : orig[i].hashset) targ[i].insert(it);
        for (auto it : rev[i].hashset) targ[i].insert(it);
    }
    set<pii> candidates = orig[0].hashset;
    for (int i = 1; i < n; i++) {
        set <pii> tmp;
        set_intersection(candidates.begin(), candidates.end(),
                         targ[i].begin(), targ[i].end(), inserter(tmp, tmp.begin()));
        candidates = tmp;
    }
    cout << (!candidates.empty()?"YES":"NO") << '\n';
}