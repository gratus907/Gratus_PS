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

char grid[52][52];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

bool able(int i, int j)
{
    if (grid[i][j] == '.')
    {
        for (int t = 0; t<4; t++)
        {
            if (grid[i+dx[t]][j+dy[t]]!='.')
                return 0;
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

void placeblock (int i, int j)
{
    grid[i][j] = '#';
    for (int t = 0; t<4; t++)
    {
        grid[i+dx[t]][j+dy[t]]='#';
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 1; i<=n; i++)
    {
        scanf("%s",grid[i]+1);
    }
    for (int i = 2; i<=n; i++)
    {
        for (int j = 2; j<=n; j++)
        {
            if (able(i, j))
            {
                placeblock(i, j);
            }
        }
    }
    bool flag = true;
    for (int i = 1; i<=n; i++)
        for (int j = 1; j<=n; j++)
            if (grid[i][j] == '.')
                flag = false;
    printf("%s",flag?"YES":"NO");
}
