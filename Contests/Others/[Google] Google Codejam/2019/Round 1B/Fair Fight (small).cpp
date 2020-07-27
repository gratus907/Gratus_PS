#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#define ll long long
#define MAX(A,B) (A)>(B)?(A):(B)
#define MIN(A,B) (A)<(B)?(A):(B)
#define gcd(A,B) __gcd(A,B)
#define lcm(A,B) A/(__gcd(A,B))*B
#define MP make_pair
#define PB push_back
#define EPS 1e-9
#define ld long double
#define mod 1000000007LL
#define all(x) x.begin(), x.end()
#define usecppio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,double> pid;

int c[102000], d[102000];

int query(int l, int r, int k)
{
    int cmax, dmax;
    cmax = INT_MIN;
    dmax = INT_MIN;
    for (int i = l; i<=r; i++)
    {
        cmax = MAX(cmax, c[i]);
        dmax = MAX(dmax, d[i]);
    }
    //printf("%d %d %d %d\n",l, r, cmax, dmax);
    return abs(cmax-dmax)<=k? 1 : 0;
}

int main()
{
    int tc;
    scanf("%d",&tc);
    for (int tct = 0; tct < tc; tct++)
    {
        int n;
        memset(c, 0, sizeof(c));
        memset(d, 0, sizeof(d));
        ll intervals = 0;
        int k;
        printf("Case #%d: ",tct+1);
        scanf("%d %d",&n,&k);
        for (int i = 0; i<n; i++)
        {
            scanf("%d",c+i);
        }
        for (int i = 0; i<n; i++)
        {
            scanf("%d",d+i);
        }
        for (int i = 0; i<n; i++)
        {
            for (int j = i; j<n; j++)
            {
                intervals += query(i, j, k);
            }
        }
        printf("%lld",intervals);
        printf("\n");
    }
}
