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
#define PI acos(-1.0)
using pii = pair<int, int>;

int32_t main()
{
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    double s = (a+b+c+d)/2;
    cout << setprecision(12) << fixed << sqrt((s-a)*(s-b)*(s-c)*(s-d));
}