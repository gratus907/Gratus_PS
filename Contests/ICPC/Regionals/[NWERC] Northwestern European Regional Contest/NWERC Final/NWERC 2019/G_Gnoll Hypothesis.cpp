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
#define INF 0x7f7f7f7f7f7f7f7f
const bool debug = false;

double prob[520];
double newprob[520];
double pp[520];
int n, k;
int32_t main()
{
    cin >> n >> k;
    for (int i = 0; i<n; i++) cin >> prob[i];
    pp[0] = k*1.0/n;
    for (int i = 1; i<=(n-k); i++)
    {
        pp[i] = 1;
        pp[i] *= (k*1.0);
        for (int j = 1; j<=i; j++)
        {
            pp[i] *= n-k-i+j;
            pp[i] /= n-i+j-1;
        }
        pp[i] /= n;
    }
    for (int i = 0; i<n; i++)
        for (int j = 0; j<=500; j++)
            newprob[i] += prob[(i-j+n)%n]*pp[j];
    for (int i = 0; i<n; i++)
        cout << fixed << setprecision(20) << newprob[i] << ' ';
}
