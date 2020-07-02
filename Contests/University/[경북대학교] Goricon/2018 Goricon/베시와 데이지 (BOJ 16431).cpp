#include <bits/stdc++.h>
#define ll long long
#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
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
    int bx,by,dx,dy,jx,jy;
    scanf("%d%d %d%d %d%d",&bx,&by,&dx,&dy,&jx,&jy);
    int bdx,bdy,ddx,ddy;
    bdx = abs(bx-jx);
    bdy = abs(by-jy);
    ddx = abs(dx-jx);
    ddy = abs(dy-jy);
    int bt,dt;
    bt = MAX(bdx,bdy);
    dt = ddx+ddy;
    if (dt<bt)
        printf("daisy");
    if (dt==bt)
        printf("tie");
    if (dt>bt)
        printf("bessie");
}