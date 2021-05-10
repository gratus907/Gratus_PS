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

string s, t;
vector <int> occ[26];
int32_t main()
{
    usecppio
    cin >> s >> t;
    for (int i = 0; i < t.length(); i++){
        int idx = t[i] - 'a';
        occ[idx].push_back(i);
    }
    int n = 1, pt = 0;
    for (auto _c : s) {
        int c = _c - 'a';
        back:
        if (occ[c].empty()) {
            cout << -1 << '\n';
            return 0;
        }
        auto b = lower_bound(all(occ[c]), pt);
        if (b == occ[c].end()) {
            pt = 0; n++; goto back;
        }
        pt = *b + 1;
    }
    cout << n << '\n';
}