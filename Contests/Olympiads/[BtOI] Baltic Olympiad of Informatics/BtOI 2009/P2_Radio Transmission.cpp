#include <bits/stdc++.h>
#define int ll
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;

vector<int> getPi(string p) {
    int j = 0, plen = p.length();
    vector<int> pi;
    pi.resize(plen);
    for(int i = 1; i< plen; i++) {
        while((j > 0) && (p[i] !=  p[j]))
            j = pi[j-1];
        if(p[i] == p[j]) {
            j++;
            pi[i] = j;
        }
    }
    return pi;
}

int32_t main(){
    usecppio
    int L; cin >> L;
    string s; cin >> s;
    vector <int> v = getPi(s);
    cout << L - v[L-1] << '\n';
}