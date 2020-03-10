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

bool solve()
{
    int n, k;
    cin >> n >> k;
    vector <int> target;
    target.resize(n);
    vector <int> npo(100, 0);
    for (int i = 0; i<n; i++)
    {
        cin >> target[i];
        int p = target[i];
        int u = 0;
        while(p)
        {
            npo[u]+=(p%k);
            //printf("Need to add %lld^%lld to %lldth position\n",k,u,i);
            p/=k;
            u++;
        }
    }
    for (int i = 0; i<100; i++)
    {
        if (npo[i]>1)
            return false;
    }
    return true;
}
int32_t main()
{
    usecppio
    int t; cin >> t;
    while(t--)
    {
        cout << (solve()?"YES\n":"NO\n");
    }
}