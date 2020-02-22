#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
using pii = pair <int, int>;
const int mod = 1000000007;

int32_t main()
{
    usecppio
    string s;
    cin >> s;
    int cand_1 = 0;
    int cand_2 = 1e9;
    for (auto it:s)
    {
        int cur = it - '0';
        int a = min(min(cand_1+cur, cand_1+11-cur),min(cand_2+cur+1, cand_2+10-cur));
        int b = min(min(cand_1+cur+1, cand_1+10-cur),min(cand_2+cur+2, cand_2+9-cur));
        cand_1 = a; cand_2 = b;
    }
    cout << min(cand_1, cand_2+1) << "\n";
}