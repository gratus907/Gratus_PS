#include <bits/stdc++.h>
#define lli long long int
#define bignum (int)1e9
using namespace std;

int main()
{
    lli l ,r;
    scanf("%lld%lld",&l,&r);
    printf("YES\n");
    for (lli i = l; i<=r-1; i+=2)
        printf("%lld %lld\n",i,i+1);
}