#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int ll
using pii = pair<int, int>;
random_device rd;
mt19937 gen(rd());
uniform_real_distribution<> dis(0, 1);
uniform_int_distribution<> randint(0, RAND_MAX);

int n, k;
double p;

double prob(int r)
{
    if (r < k)
        return 0;
    double ans = 1;
    for (int i = 0; i<k-1; i++)
    {
        ans *= (r-i-1);
        ans /= (k-i-1);
    }
    ans *= pow(p,r-k);
    ans *= pow(1-p,k);
    return ans;
}
double D[10000];
double SD[10000];
int32_t main()
{
    cin >> n >> k >> p;
    for (int i = 1; i<10000; i++)
    {
        D[i] = prob(i);
        SD[i] = (SD[i-1] + D[i]);
    }
    double res = 1;
    for (int i = 1; i<10000; i++)
        res -= n*(D[i]*pow(SD[i-1],n-1));
    cout << fixed << setprecision(15) << res << '\n';
}