#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int eval(int n)
{
    if (n <= 3) return 0;
    if (n == 4) return 1;
    else return eval((n+1)/2)+2;
}
int32_t main() 
{
    int n;
    scanf("%lld",&n);
    printf("%lld",eval(n));
}