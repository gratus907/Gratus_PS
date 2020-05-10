#include <bits/stdc++.h>
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
typedef pair<ll,ll> pll;

int top[120][120], front[120], side[120];

int main()
{
    int n, m, h;
    scanf("%d%d%d",&n,&m,&h);

    for (int j = 0; j<m; j++)
        scanf("%d",&front[j]);

    for (int i = 0; i<n; i++)
        scanf("%d",&side[i]);

    for (int i = 0; i<n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &top[i][j]);

    for (int j = 0; j<m; j++)
    {
        for (int i = 0; i<n; i++)
            if (top[i][j] == 1)
                top[i][j] = front[j];
    }

    for(int i = n-1;i>=0;i--)
    {
        for (int j = 0; j<m; j++)
            if (top[i][j] > side[i])
                top[i][j] = side[i];
    }

    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<m; j++)
            printf("%d ", top[i][j]);
        printf("\n");
    }

    return 0;
}
