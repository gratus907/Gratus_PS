#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#define ll long long
#define gcd(A,B) (__gcd(A,B))
using namespace std;

const ll M = 1500000;
int chk[M+1];
int main()
{
    auto start = chrono::steady_clock::now();
    int max_m = (int)sqrt(750000);
    for (int m = 2; m<max_m; m++)
    {
        for (int n = 1; n<m; n++)
        {
            if ((m+n)%2 && (gcd(m,n)==1))
            {
                ll a = (ll)m*m-(ll)n*n;
                ll b = 2*(ll)m*n;
                ll c = (ll)m*m+(ll)n*n;
                ll tr = a+b+c;
                for (int i = 1; i*tr<=M; i++)
                    chk[i*tr]++;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i<=M; i++)
        ans += (chk[i]==1?1:0);
    cout << ans << '\n';
    auto end = chrono::steady_clock::now();
    auto diff = end-start;
    cout << "Execution Time : " << chrono::duration <double, milli> (diff).count() << " ms" << '\n';
}
