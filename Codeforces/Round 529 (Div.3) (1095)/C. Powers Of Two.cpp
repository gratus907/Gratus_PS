#include <bits/stdc++.h>
#define lli long long int
#define MAX(A,B) A>B?A:B
#define MIN(A,B) (A)<(B)?(A):(B)
#define gcd(A,B) __gcd(A,B)
#define lcm(A,B) A/(__gcd(A,B))*B
#define MP make_pair
#define PB push_back
#define EPS 1e-9
#define ld long double
#define modulo 998244353
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,double> pid;

int popcount(int x)
{
    return __builtin_popcount((unsigned int)x);
}

void func(int n, int k)
{
    if (k==0)
        return;
    for (int i = 31; i>=0; i--)
    {
        int tmp = n-(1<<i);
        int p = popcount(tmp);
        if ((k-1)<=tmp && p<=tmp)
        {
            printf("%d ",1<<i);
            func(tmp,k-1);
            return;
        }
    }
}

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int m = popcount(n);
    if (k<m || k>n)
    {
        printf("NO");
        return 0;
    }
    else
    {
        printf("YES\n");
        func(n,k);
    }
}