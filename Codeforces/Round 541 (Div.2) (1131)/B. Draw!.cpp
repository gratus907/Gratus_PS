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

int ta[10020], tb[10020];

int maxdraws(int a1, int a2, int b1, int b2)
{
    if (a1==a2 && b1==b2)
        return 0;
    if (a1!=a2 || b1!=b2)
    {
        int u;
        u = MIN(a2,b2)-MAX(a1,b1)+1;
        if (a1==b1 && a1!=0)
            u--;
        u = MAX(0, u);
        return u;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 1; i<=n; i++)
        scanf("%d%d",ta+i,tb+i);
    ll draws = 0;
    for (int i = 1; i<=n; i++)
    {
        draws += maxdraws(ta[i-1],ta[i],tb[i-1],tb[i]);
    }
    if (ta[n]==0 || tb[n]==0)
        draws = 1;
    printf("%lld",draws);
}
