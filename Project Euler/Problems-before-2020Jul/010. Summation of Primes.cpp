#include <bits/stdc++.h>
#define lli long long int
using namespace std;

const int BIGNUM = (int)2e6+1;
int p[BIGNUM];
lli sum;
int pcount;
bool is_composite[BIGNUM];
void sieve()
{
    for (int i = 2; i <= BIGNUM; i++)
    {
        if (!is_composite[i])
        {
            p[pcount++] = i;
            sum += i;
            for (int j = i * 2; j <= BIGNUM; j += i)
                is_composite[j] = true;
        }
    }
}

int main()
{
    sieve();
    printf("%lld",sum);
}
