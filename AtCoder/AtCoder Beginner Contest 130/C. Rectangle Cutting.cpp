#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll w, h, x, y;
    cin >> w >> h >> x >> y;
    printf("%lf ",(w*h*1.0)/2);
    printf("%d", ((2*x==w)&&(2*y==h))?1:0);
}
