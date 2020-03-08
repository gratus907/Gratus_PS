#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
#define eps 1e-7
#define int ll
using pii = pair <int, int>;

deque<char> d;
string s;
int32_t main()
{
    usecppio
    cin >> s;
    for (auto it:s)
        d.push_back(it);
    int q; cin >> q;
    bool rev = false;
    while(q--)
    {
        int t; cin >> t;
        if (t == 1)
            rev = !rev;
        else
        {
            int f; string c;
            cin >> f >> c;
            if (f == 1)
            {
                if (rev)
                    d.push_back(c[0]);
                else d.push_front(c[0]);
            }
            else
            {
                if (rev)
                    d.push_front(c[0]);
                else
                    d.push_back(c[0]);
            }
        }
    }
    if (rev)
        reverse(all(d));
    for (auto it:d)
        cout << it;
    cout << '\n';
}
