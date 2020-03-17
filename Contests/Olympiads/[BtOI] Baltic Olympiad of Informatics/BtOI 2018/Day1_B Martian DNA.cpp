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
using pii = pair<int, int>;
#define INF 0x7f7f7f7f7f7f7f7f
const bool debug = false;

int n, k, r;
vector <int> dna;
int req[202020];
int occ[202020];
int need;
int ans = INF;
int32_t main()
{
    cin >> n >> k >> r;
    dna.resize(n);
    for (int i = 0; i<n; i++)
    {
        cin >> dna[i];
        occ[dna[i]]++;
    }
    for (int i = 0; i<r; i++)
    {
        int a, b; cin >> a >> b;
        req[a] = b;
        need++;
    }
    int j = 0;
    for (int i = 0; i<n; i++)
    {
        while(need && j < n)
        {
            req[dna[j]]--;
            if (req[dna[j]]==0)
                need--;
            j++;
        }
        if (!need) ans = min(ans, j-i);
        if (!req[dna[i]])
            need++;
        req[dna[i]]++;
    }
    if (ans > n)
        cout << "impossible\n";
    else cout << ans << '\n';
}