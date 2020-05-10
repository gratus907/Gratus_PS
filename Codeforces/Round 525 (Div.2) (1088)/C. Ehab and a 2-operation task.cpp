#include <bits/stdc++.h>
#define lli long long int
#define MAX(A,B) A>B?A:B
#define MIN(A,B) A<B?A:B
#define gcd(A,B) __gcd(A,B)
#define lcm(A,B) A/(__gcd(A,B))*B
#define MP make_pair
#define PB push_back
#define EPS 1e-9
#define ld long double
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,double> pid;

lli arr[2500];
int main()
{
    int n;
    int p = 346943;
    scanf("%d",&n);
    for (int i = 1; i<=n; i++)
        scanf("%lld",&arr[i]);
    printf("%d\n",n+1);
    for (int i = n; i>=1;i--)
    {
        lli u = p-(n-i+1)-(arr[i]%p);
        if (u < 0)
            u+=p;
        printf("1 %d %lld\n",i,u);
        for (int j = 1; j<=i; j++)
            arr[j] += u;
    }
    printf("2 %d %d\n",n,p);
}
