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
const int mod = 1000000007;

vector <int> snuke[105];
int32_t main()
{
    int n, k; cin >> n >> k;
    for (int i = 1; i<=k; i++)
    {
        int d; cin >> d;
        for (int j = 1; j<=d; j++)
        {
            int x; cin >> x;
            snuke[x].push_back(i);
        }
    }
    int ct = 0;
    for (int i = 1; i<=n; i++)
    {
        ct += snuke[i].empty();
    }
    cout << ct << '\n';
}
