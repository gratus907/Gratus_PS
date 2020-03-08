#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
#define eps 1e-7
#define int ll
using pii = pair <int, int>;
int mobius[50505];
int mertens[50505];
void mobiusfunction(int upto)
{
    for (int i = 1; i <= upto; i++)
        mobius[i] = 1;
    for (int i = 2; i*i <= upto; i++)
    {
        if (mobius[i] == 1)
        {
            for (int j = i; j <= upto; j += i)
                mobius[j] *= -i;
            for (int j = i * i; j <= upto; j += i * i)
                mobius[j] = 0;
        }
    }
    for (int i = 2; i <= upto; i++)
    {
        if (mobius[i] == i)
            mobius[i] = 1;
        else if (mobius[i] == -i)
            mobius[i] = -1;
        else if (mobius[i] < 0)
            mobius[i] = 1;
        else if (mobius[i] > 0)
            mobius[i] = -1;
    }
}

int32_t main()
{
    mobiusfunction(50000);
    for (int i = 1; i<=50000; i++)
        mertens[i] = mertens[i-1]+mobius[i];
    int q; cin >> q;
    while(q--)
    {
        int a, b, c, ans = 0;
        cin >> a >> b >> c;
        a /= c;
        b /= c;
        ans = a*b;
        int u = min(a, b);
        for (int i = 2; i<=u;)
        {
            int ni = min(a/(a/i), b/(b/i));
            ans += (a/i)*(b/i)*(mertens[ni]-mertens[i-1]);
            i = ni;
            i++;
        }
        cout << ans << '\n';
    }
}