#include <bits/stdc++.h>
#define lli long long int
#define bignum (int)1000000007
using namespace std;

int main()
{
    int a, b;
    scanf("%d%d",&a,&b);
    if (a>b)
        printf(">");
    else if (a<b)
        printf("<");
    else
        printf("==");
}