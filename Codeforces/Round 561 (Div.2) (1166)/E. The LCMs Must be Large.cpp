#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#define ll long long
#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
#define gcd(A,B) (__gcd(A,B))
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

bool bb[51][10010];
int n,m;
bool comsub(int a, int b) // check if b is subset of complementary of a.
{
    for (int i = 0; i<10010; i++)
    {
        if (bb[b][i])
        {
            if (bb[a][i])
                return false;
        }
    }
    return true;
}
int main()
{
    scanf("%d %d",&m,&n);
    for (int i = 0; i<m; i++)
    {
        int s;
        scanf("%d",&s);
        for (int j = 0; j<s; j++)
        {
            int buy;
            scanf("%d",&buy);
            bb[i][buy] = 1;
        }
    }
    bool ans = true;
    for (int i = 0; i<m; i++)
    {
        for (int j = 0; j<m; j++)
        {
            if (comsub(i, j))
            {
                //printf("%d is comsub of %d\n",i,j);
                ans = false;
                break;
            }
        }
        if (!ans)
            break;
    }
    printf("%s",ans?"possible":"impossible");
}
