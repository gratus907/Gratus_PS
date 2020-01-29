#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
#define MOD 1000000007
#define int ll
using pii = pair <int, int>;

int n, k, m;
int able (int x)
{
    int g = 0;
    int d = 0, nxt = n;
    while(d < k && nxt > m && g < n)
    {
        nxt = (n-g)/x;
        if (nxt <= m) break;
        if (nxt == (n-g-nxt)/x)
        {
            int targ = n-x*(nxt);
            int gp = targ-g;
            int past = gp/nxt;
            d+=past; g+=(past*nxt);
        }
        else
        {
            d++; g+=nxt;
        }
    }
    g += (k-d)*m;
    return g;
}
int32_t main()
{
    ifstream fin("loan.in");
    ofstream fout("loan.out");
    fin >> n >> k >> m;
    int lo = 1, hi = 1e13;
    while(lo + 1 < hi)
    {
        int mid = (lo + hi)/2;
        if (able(mid) >= n)
            lo = mid;
        else
            hi = mid;
    }
    fout << lo;
}