#include<bits/stdc++.h>
using namespace std;
#define int ll
#define ll long long

int n;

int32_t main()
{
    cin >> n;
    int targ = n*(n-1)/2;
    int m = (1-sqrt(0.5))*n-3;
    m = max(0LL, m);
    while(m*(m-1) <= targ)
        m++;
    cout << n+1-m;
}
