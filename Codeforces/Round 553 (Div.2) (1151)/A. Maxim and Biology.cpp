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

char str[52];
char gen[4] = {'A','C','T','G'};
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",str);
    int ans = INT_MAX;
    for (int i = 0; i<(n-3); i++)
    {
        int u = 0;
        for (int j = 0; j<4; j++)
        {
            int c = abs(str[i+j]-gen[j]);
            c = MIN(c, 26-c);
            u += c;
        }
        ans = MIN(ans,u);
    }
    printf("%d",ans);
}
