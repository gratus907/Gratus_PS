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
    int n,k;
    scanf("%d%d",&n,&k);
    lli sum = 0;
    sum += ((2*n)%k == 0)?(2*n)/k : ((2*n)/k+1);
    sum += ((5*n)%k == 0)?(5*n)/k : ((5*n)/k+1);
    sum += ((8*n)%k == 0)?(8*n)/k : ((8*n)/k+1);
    printf("%lld",sum);
}