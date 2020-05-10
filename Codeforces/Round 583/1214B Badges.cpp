#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
int main()
{
    int b, g, n;
    cin >> b >> g >> n;
    b = min(b, n);
    g = min(g, n);
    int lb = n-b;
    int rb = n-g;
    cout << n+1 - lb - rb << '\n';
}