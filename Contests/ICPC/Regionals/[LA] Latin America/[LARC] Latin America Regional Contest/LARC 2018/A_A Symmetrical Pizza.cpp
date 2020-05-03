#include <bits/stdc++.h>
#define lli long long int
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
    double d;
    scanf("%lf",&d);
    int r = (int)(100*d+EPS);
    int tmp = gcd(r,36000);
    printf("%d",36000/tmp);
}