#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define int ll
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;
const int mod = 1000000007;

int n;
string s;
int scount[202020];
int32_t main()
{
    usecppio
    cin >> n >> s;
    for (int i = 1; i<=n; i++)
    {
        scount[i] = scount[i-1];
        if (s[i-1]=='s')
            scount[i]++;
    }
    if (scount[n/2]==n/4)
    {
        cout << 1 << '\n' << n/2 << '\n';
        return 0;
    }
    for (int i = 2; i<=n/2; i++)
    {
        //printf("SCOUNT %lld = %lld\n",i ,scount[i+n/2]-scount[i-1]);
        if (scount[i+n/2-1]-scount[i-1]==n/4)
        {
            cout << 2 << '\n' << i-1 << ' ' << i+n/2-1 << '\n';
            return 0;
        }
    }
}