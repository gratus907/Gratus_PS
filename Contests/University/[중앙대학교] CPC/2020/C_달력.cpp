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
using pii = pair<ll, ll>;
int n, A[367], c, t, l;

int32_t main()
{
    usecppio
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int s, e; cin >> s >> e;
        while(s <= e) A[s++]++;
    }
    for (int i = 1; i <= 366; i++)
    {
        if (!A[i])
        {
            t += ((i - l - 1) * c);
            l = i; c = 0;
        }
        else
            c = max(c, A[i]);
    }
    cout << t << '\n';
}