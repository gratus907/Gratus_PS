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
#define INF 0x7f7f7f7f7f7f7f7f
const bool debug = 0;

vector <int> seq;
vector <int> pref;
vector <int> suf;
int range_xor(int left, int right)
{
    int a = (left==0?0:pref[left-1]);
    int b = pref[right];
    return a^b;
}
int32_t main()
{
    usecppio
    int k; cin >> k;
    seq.resize(k+1); pref.resize(k+1); suf.resize(k+1);
    for (int i = 0; i<k; i++)
    {
        cin >> seq[i];
        seq[k] ^= seq[i];
    }
    pref[0] = seq[0];
    for (int i = 1; i<=k; i++)
        pref[i] = pref[i-1]^seq[i];
    suf[k] = seq[k];
    for (int i = k-1; i>=0; i--)
        suf[i] = suf[i+1]^seq[i];
    int L = k+1;
    int q; cin >> q;
    while(q--)
    {
        int l, r; cin >> l >> r;
        l--; r--;
        int u = l%L, v = r%L;
        if (l/L == r/L)
            cout << range_xor(u, v);
        else
            cout << (suf[u]^pref[v]);
        cout << '\n';
    }
}