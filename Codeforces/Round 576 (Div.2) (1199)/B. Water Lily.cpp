#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#define ll long long
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair <int, int> pii;

long double h, l;
int main()
{
    usecppio
    cin >> h >> l;
    cout << fixed << setprecision(10) << (l*l-h*h)/(2*h);
}
