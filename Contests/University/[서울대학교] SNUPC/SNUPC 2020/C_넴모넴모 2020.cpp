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
int n, q;
int A[252525];
int32_t main()
{
    usecppio
    cin >> n >> q;
    for (int i = 1; i<=n; i++)
    {
        cin >> A[i];
    }
    while(q--)
    {
        int xi, yi; cin >> xi >> yi;
        int hor, ver;
        hor = max(A[yi]-xi+1, 0ll);
        int lo = yi, hi = n+1;
        while(lo + 1 < hi)
        {
            int mid = (lo + hi)/2;
            if (A[mid] >= xi)
                lo = mid;
            else hi = mid;
        }
        ver = lo - yi;
        cout << hor + ver << '\n';
    }
}