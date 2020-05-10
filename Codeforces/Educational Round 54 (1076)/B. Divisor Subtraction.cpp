#include <bits/stdc++.h>
#define lli long long int
#define MAX(A,B) A>B?A:B
#define MIN(A,B) A<B?A:B
#define gcd(A,B) __gcd(A,B)
#define lcm(A,B) A/(__gcd(A,B))*B
#define MP make_pair
#define PB push_back
#define EPS 1e-9
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,double> pid;

vector <lli> prime;
int primecheck(lli n)
{
    lli i;
    int condition = 1;
    if (n == 1)
    {
        condition = 0;
    }
    for (i = 2; i*i <= n; i++)
    {
        if (n%i == 0)
        {
            condition = 0;
            break;
        }
    }
    return condition;
}

int main()
{
    lli n,u;
    scanf("%lld",&n);
    if (n%2==0)
    {
        printf("%lld",n/2);
        return 0;
    }
    if(primecheck(n)==1)
    {
        printf("1");
        return 0;
    }
    for (lli i = 2; i*i<=2*n; i++)
    {
        if (n%i == 0)
        {
            u = n-i;
            break;
        }
    }
    printf("%lld",u/2+1);
}
