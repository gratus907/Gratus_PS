#include <bits/stdc++.h>
#define lli long long int
#define MAX(A,B) (A)>(B)?(A):(B)
#define MIN(A,B) (A)<(B)?(A):(B)
#define gcd(A,B) __gcd(A,B)
#define lcm(A,B) A/(__gcd(A,B))*B
#define MP make_pair
#define PB push_back
#define EPS 1e-9
#define ld long double
#define mod 1000000007LL
#define usecppio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,double> pid;

lli primecheck(lli n)
{
    lli i;
    lli condition = 1;
    if (n == 1)
        return 0;
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

void solve()
{
    double u = 0;
    int ind = 2;
    for (int i = 2; i<=1000000; i++)
    {
        lli n = i;
        lli on=n;
        lli p=2;
        while(p*p<=n)
        {
            if (n%p == 0)
                on = on/p * (p-1);
            while(n%p==0)
                n/=p;
            p++;
        }
        if (primecheck(n)==1)
            on = on/n * (n-1);
        if (u < (double)i/on)
        {
            ind = i;
            u = ((double)i/on);
        }
    }
    printf("%d, change to %lf\n",ind,u);
}

int main()
{
    clock_t start;
    start = clock();
    solve();
    clock_t end;
    end = clock();
    double timeelapsed = (end-start)/CLOCKS_PER_SEC;
    printf("\n---------- %lf seconds took ----------\n",timeelapsed);
}
