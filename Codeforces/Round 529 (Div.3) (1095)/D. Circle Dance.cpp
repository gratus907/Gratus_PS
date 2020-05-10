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

int mem[201000][2];
int nextp[201000];
int visit[201000];

int checknextmem(int rec, int tar)
{
    return (mem[rec][0]==tar || mem[rec][1]==tar) ;
}

int main()
{
    int n;
    scanf("%d",&n);
    if (n==3)
    {
        printf("1 2 3");
        return 0;
    }
    for (int i = 1; i<=n; i++)
        scanf("%d%d",&mem[i][0],&mem[i][1]);
    for (int i = 1; i<=n; i++)
    {
        int a = mem[i][0];
        int b = mem[i][1];
        if (checknextmem(b,a))
            nextp[i] = b;
        if (checknextmem(a,b))
            nextp[i] = a;
    }
    int p = 0;
    int kid = 1;
    int nextkid;
    while(1)
    {
        nextkid = nextp[kid];
        if (visit[nextp[nextkid]])
        {
            printf("%d %d",kid,nextkid);
            return 0;
        }
        visit[kid] = 1;
        printf("%d ",kid);
        p++;
        if (p==n)
            return 0;
        kid = nextkid;
    }

}