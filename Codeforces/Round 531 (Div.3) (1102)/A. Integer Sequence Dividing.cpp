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
#define mod 1000000007LL
#define usecppio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,double> pid;

int main()
{
    lli n;
    scanf("%lld",&n);
    printf("%d",(n*(n+1)/2)%2==0?0:1);
}
