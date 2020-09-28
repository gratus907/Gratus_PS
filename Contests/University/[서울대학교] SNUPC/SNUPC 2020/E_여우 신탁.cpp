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

int prob[1010101];
int arr[303030];
double expect = 0.0;
int32_t main()
{
    usecppio
    int n;
    cin >> n;
    int x0; cin >> x0;
    for (int i = 0; i<x0; i++)
        prob[i]++;
    int cur = x0-1;
    for (int i = 2; i<=n; i++)
    {
        int xi; cin >> xi;
        if (xi > cur)
            continue;
        else
        {
            while(cur >= xi)
            {
                prob[cur%xi] += prob[cur];
                cur--;
            }
        }
    }
    for (int i = 0; i<=cur; i++)
        expect += (prob[i]*1.0)/(x0*1.0) * i;
    cout << fixed << setprecision(12) << expect << '\n';
}