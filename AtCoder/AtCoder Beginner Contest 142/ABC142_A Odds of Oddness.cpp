#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main()
{
    int n; 
    cin >> n; 
    int u = n/2;
    if (n % 2)
        printf("%lf",(1.0*u+1) / (1.0*n));
    else printf("%lf",u*1.0/n);
}