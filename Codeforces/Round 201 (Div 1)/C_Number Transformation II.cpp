#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const bool debug = 0;
#define int ll
using pii = pair<int, int>;
int n, a, b;
set <int> s;

int32_t main()
{
    usecppio
    cin >> n;
    for (int i = 0; i<n; i++)
    {
        int x; cin >> x;
        s.insert(x);
    }
    cin >> a >> b;
    int ans = 0;
    while (a > b)
    {
        ans++;
        int newa = a-1;
        vector <int> dead;
        for (auto &it:s)
        {
            int u = a - a%it;
            if (u < b)
                dead.push_back(it);
            else
                newa = min(newa, u);
        }
        a = newa;
        for (auto it:dead)
            s.erase(it);
    }
    cout << ans << '\n';
}