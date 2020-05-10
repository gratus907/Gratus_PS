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

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int a[102000];
int main()
{
    int n;
    scanf("%d",&n);
    int M = 0;
    int u = 0;
    for (int i = 0; i<n; i++)
    {
        scanf("%d",a+i);
        M = MAX(a[i],M);
    }
    int cur = 0;
    for (int i = 0; i<n; i++)
    {
        if (a[i] == M)
            cur++;
        else
            cur=0;
        u = MAX(cur,u);
    }
    printf("%d",u);
}
