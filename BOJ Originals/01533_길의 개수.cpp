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
const int mod = 1000003;
template<class T, int N> struct Matrix {
    typedef Matrix M;
    array<array<T, N>, N> d{};
    M operator*(const M& m) const {
        M a;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    a.d[i][j] += (d[i][k]*m.d[k][j]);
                    a.d[i][j] %= mod;
                }
            }
        }
        return a;
    }
    M operator^(ll p) const {
        assert(p >= 0);
        M a, b(*this);
        for (int i = 0; i < N; i++) a.d[i][i] = 1;
        while (p) {
            if (p&1) a = a*b;
            b = b*b;
            p >>= 1;
        }
        return a;
    }
};

Matrix<int, 50> G;
int32_t main() {
    usecppio
    int n, s, e, t; cin >> n >> s >> e >> t;
    s--; e--;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            G.d[i*5+j+1][i*5+j] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        string st; cin >> st;
        for (int j = 0; j < n; j++) {
            int k = st[j] - '0';
            if (k == 0) continue;
            else G.d[i*5][j*5+(k-1)] = 1;
        }
    }
    G = G^t;
    cout << G.d[5*s][5*e]%mod << '\n';
}