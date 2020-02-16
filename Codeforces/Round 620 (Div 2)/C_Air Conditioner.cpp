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
 
void solve()
{
    int n, m;
    cin >> n >> m;
    int lo = m, hi = m;
    int bef_time = 0;
    bool able = true;
    for (int i = 0; i<n; i++)
    {
        int ti, li, ri;
        cin >> ti >> li >> ri;
        int have_time = ti - bef_time;
        int nhi = hi+have_time;
        int nlo = lo-have_time;
        lo = max(nlo, li);
        hi = min(nhi, ri);
        //printf("Current range of my work = %lld %lld\n",nlo,nhi);
        bef_time = ti;
        if (hi >= lo) continue;
        else
            able = false;
    }
    if (able)
        cout << "YES\n";
    else
        cout << "NO\n";
}
 
int32_t main()
{
    usecppio
    int t;
    cin >> t;
    while(t--) solve();
}