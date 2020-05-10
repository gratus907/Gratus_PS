#include <bits/stdc++.h>
#define ll long long
#define MAX(A,B) A>B?A:B
#define MIN(A,B) A>B?B:A
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
    int a[4];
    scanf("%d%d%d%d",a,a+1,a+2,a+3);
    sort(a,a+4);
    printf("%d %d %d",a[3]-a[0],a[3]-a[1],a[3]-a[2]);
}
