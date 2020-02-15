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

vector <int> ver, hor;
int a, b, n, m;
int ans;
int gap_ver[25252], gap_hor[25252];
int32_t main()
{
    cin >> a >> b >> n >> m;
    for (int i = 0; i<n; i++)
    {
        int x;
        cin >> x;
        ver.push_back(x);
    }
    for (int i = 0; i<m; i++)
    {
        int x;
        cin >> x;
        hor.push_back(x);
    }
    ver.push_back(a);
    hor.push_back(b);
    sort(all(ver));
    sort(all(hor));
    for (int i = 0; i<n; i++)
        gap_ver[i] = ver[i+1]-ver[i];
    for (int i = 0; i<m; i++)
        gap_hor[i] = hor[i+1]-hor[i];
    gap_ver[n] = ver[0];
    gap_hor[m] = hor[0];
    sort(gap_ver,gap_ver+n+1);
    sort(gap_hor,gap_hor+m+1);
    int vpt = 1, hpt = 1;
    while(vpt <= n && hpt <= m)
    {
        if (gap_ver[vpt] > gap_hor[hpt])
        {
            ans += gap_hor[hpt]*(n-vpt+1);
            hpt++;
        }
        else
        {
            ans += gap_ver[vpt]*(m-hpt+1);
            vpt++;
        }
    }
    cout << ans + gap_ver[0]*m+gap_hor[0]*n << '\n';
}