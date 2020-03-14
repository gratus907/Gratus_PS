#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx,avx2,fma")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int ll
#define all(x) ((x).begin()),((x).end())
#define eps 1e-7
using pii = pair<int, int>;
#include "boxes.h"
int pl[10101010], mi[10101010];
long long delivery(int32_t N, int32_t K, int32_t L, int32_t p[]) {
    int n = N, k = K, l = L;
    for (int i = 0; i<n; i++)
    {
        if (i >= k)
            pl[i] = pl[i-k]+p[i]+min((ll)p[i],l-p[i]);
        else pl[i] = p[i]+min(l-p[i],(ll)p[i]);
    }
    for (int i = n-1; i>=0; i--)
    {
        if ((n-i)>=k)
            mi[i] = mi[i+k]+l-p[i]+min(l-p[i],(ll)p[i]);
        else mi[i] = (l-p[i])+min(l-p[i],(ll)p[i]);
    }
    int ans = mi[0];
    for (int i = 0; i<n; i++)
        ans = min(ans, pl[i]+mi[i+1]);
    ans = min(ans, pl[n-1]);
    return ans;
}