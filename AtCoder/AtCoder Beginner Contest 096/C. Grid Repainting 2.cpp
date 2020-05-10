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
#define mod 1000000007LL
#define usecppio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,double> pid;

char grid[55][55];
int main()
{
    int h,w;
    int c = 0;
    scanf("%d%d",&h,&w);
    for (int i = 1; i<=h; i++)
        scanf("%s",grid[i]);
    for (int i = 1; i<h; i++)
    {
        for (int j = 1; j<w; j++)
        {
            if (grid[i][j] == '#' && grid[i][j-1] != '#' && grid[i-1][j] != '#' && grid[i+1][j] != '#' && grid[i][j+1] != '#')
            {
                c++;
            }
        }
    }
    if (c==0)
        printf("Yes");
    else
        printf("No");
}
