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
#define FIO ifstream fin("race.in");ofstream fout("race.out");
#define int ll
using pii = pair <int, int>;
int k, n;
inline bool able(int msp, int endsp)
{
    return msp*msp - endsp*(endsp+1)/2 < k;
}
inline int tmcal(int msp, int endsp)
{
    int mt = msp*msp - endsp*(endsp+1)/2 + endsp;
    int u = (k-mt);
    int tp = 2*msp-endsp;
    if (u <= 0)
    {
        return tp;
    }
    tp+= ((u/msp) + 1 - (u%msp==0?1:0));
    return tp;
}
int32_t main()
{
    FIO
    fin >> k >> n;
    while(n--)
    {
        int x;
        fin >> x;
        if ((x*(x+1))/2 >= k)
        {
            int llo = 0, hhi = 1e10;
            while(llo + 1 < hhi)
            {
                int mm = (llo + hhi)/2;
                if (mm*(mm+1)/2 >= k)
                    hhi = mm;
                else llo = mm;
            }
            fout << hhi;
        }
        else
        {
            int lo = 0, hi = 1e10;
            while(lo + 1 < hi)
            {
                int mid = (lo + hi)/2;
                if (able(mid, x))
                    lo = mid;
                else hi = mid;
            }
            fout << tmcal(lo,x);
        }
        if (n>=1) fout << '\n';
    }
}
