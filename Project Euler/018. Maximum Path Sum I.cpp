#include <bits/stdc++.h>
#define lli long long
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

int num[504][504];
int dp[504][504];
int main()
{
    int n,maxsum=0;
    scanf("%d", &n);
    for (int i = 1; i<=n; i++)
        for (int j = 1; j<=i; j++)
            scanf("%d",&num[i][j]);
    dp[1][1] = num[1][1];
    for (int i = 2; i<=n; i++)
    {
        for (int j = 1; j<=i; j++)
        {
            int tmp = MAX(dp[i-1][j-1],dp[i-1][j]);
            tmp += num[i][j];
            dp[i][j] = tmp;
        }
    }
    for (int i = 1; i<= n; i++)
    {
        maxsum = MAX(maxsum,dp[n][i]);
    }
    printf("%d",maxsum);
}
