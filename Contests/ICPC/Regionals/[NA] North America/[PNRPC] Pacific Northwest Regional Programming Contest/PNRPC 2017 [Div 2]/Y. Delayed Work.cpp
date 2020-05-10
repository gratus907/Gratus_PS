#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int k, p, x;
    cin >> k >> p >> x;
    double minval = 1e11;
    for (int i = 1; i<=(int)1e7; i++)
    {
        minval = min(minval,p*1.0*k/(double)i + (x*1.0*i));
    }
    printf("%.3lf",minval);
}
