#include <bits/stdc++.h>
#define ll long long
#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
#define gcd(A,B) __gcd(A,B)
#define lcm(A,B) A/(__gcd(A,B))*B
#define MP make_pair
#define PB push_back
#define EPS 1e-9
#define mod 998244353LL
#define usecppio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,long double> pid;

int d[120][120];
int main()
{
    for (int i = 0; i<120; i++)
        for (int j = 0; j<120; j++)
            d[i][j] = (int)1e9;
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 0; i<m; i++)
    {
        int a,b,v;
        scanf("%d %d %d",&a,&b,&v);
        d[a][b] = MIN(d[a][b],v);
    }
    for (int i = 1; i<=n; i++)
        for (int j = 1; j<=n; j++)
            for (int k = 1; k<=n; k++)
                d[j][k] = MIN(d[j][k],d[j][i]+d[i][k]);
    for (int i = 1; i<=n; i++)
    {
        for (int j = 1; j<=n; j++)
        {
            if (i==j)
                d[i][j] = 0;
            if (d[i][j] > 100000000)
                d[i][j] = 0;
            printf("%d ",d[i][j]);
        }
        printf("\n");
    }
}