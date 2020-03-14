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
#define int ll
#define INF 0x7f7f7f7f7f7f7f7f
const bool debug = false;
string s;
int32_t main()
{
    cin >> s;
    if (s.length()==1)
    {
        cout << 1 << '\n';
        return 0;
    }
    int ans = s.length();
    for (int i = 1; i<s.length(); i++)
        if (s[i]!=s[i-1])
            ans = min(ans, max(i, (ll)s.length()-i));
    cout << ans << '\n';
}
