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


int grid[120][120];
void printgrid(int q)
{
    for (int i = 0; i<=q; i++)
    {
        for (int j = 0; j<=q; j++)
        {
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }

}

int main()
{
    int tc;
    scanf("%d",&tc);
    for (int tct = 0; tct < tc; tct++)
    {
        vector <pair<pii, char>> people;
        vector <pii> candidate;
        printf("Case #%d: ",tct+1);
        int p, q;
        scanf("%d %d",&p, &q);
        for (int i = 0; i<p; i++)
        {
            char dir;
            int ix, iy;
            scanf("%d %d %c", &ix, &iy, &dir);
            people.PB(MP(MP(ix, iy),dir));
        }
        memset(grid,0,sizeof(grid));
        int cur_max = INT_MIN;
        for (int i = 0; i<=q; i++)
        {
            for (int j = 0; j<=q; j++)
            {
                for (auto it:people)
                {
                    if (it.first.first<i && it.second == 'E')
                    {
                        grid[i][j]++;
                        continue;
                    }
                    if (it.first.first>i && it.second == 'W')
                    {
                        grid[i][j]++;
                        continue;
                    }
                    if (it.first.second<j && it.second == 'N')
                    {
                        grid[i][j]++;
                        continue;
                    }
                    if (it.first.second>j && it.second == 'S')
                    {
                        grid[i][j]++;
                        continue;
                    }
                }

                if (grid[i][j] > cur_max)
                {
                    candidate.clear();
                    candidate.PB(MP(i, j));
                    cur_max = grid[i][j];
                }
                else if (grid[i][j] == cur_max)
                    candidate.PB(MP(i, j));
            }
        }
        //printgrid(q);
        sort(all(candidate));
        printf("%d %d",candidate[0].first,candidate[0].second);
        printf("\n");
    }
}
