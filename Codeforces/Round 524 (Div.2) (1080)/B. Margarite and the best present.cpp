#include <bits/stdc++.h>
#define lli long long int
#define MAX(A,B) ((A)>(B))?(A):(B)
#define MIN(A,B) ((A)<(B))?(A):(B)
#define gcd(A,B) __gcd(A,B)
#define lcm(A,B) A/__gcd(A,B)*B
#define MP make_pair
#define PB push_back
#define EPS 1e-9
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,double> pid;


int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        lli l,r;
        scanf("%lld %lld",&l,&r);
        lli sum=0;
        if (l%2 == 1)
        {
            sum += (1-2*l);
        }
        else
        {
            sum += (2*l - 1);
        }
        if (r%2 == 1)
        {
            sum += (-1-2*r);
        }
        else
        {
            sum += (1+2*r);
        }
        sum = sum/4;
        printf("%lld\n",sum);
    }
}