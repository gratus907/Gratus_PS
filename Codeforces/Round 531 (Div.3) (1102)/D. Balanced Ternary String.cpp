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

int allnum[3][302000];
deque <int> lefte;
deque <int> neede;
char str[302000];
int countn[3];
int f[3],ba[3];

int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",str);
    for (int i = 0; i<n; i++)
    {
        int u = str[i]-'0';
        allnum[u][countn[u]] = i;
        countn[u]++;
    }
    ba[0] = countn[0]-1;
    ba[1] = countn[1]-1;
    ba[2] = countn[2]-1;
    int dif = 0;
    for (int i = 0; i<3; i++)
    {
        int gap = countn[i]-(n/3);
        if(gap>0)
        {
            for (int j = 0; j<gap; j++)
                lefte.push_front(i);
        }
        if(gap<0)
        {
            gap = abs(gap);
            for (int j = 0; j<gap; j++)
                neede.push_front(i);
        }
    }
    dif = lefte.size();
    if (dif>0)
    {
        if (lefte[0]==lefte[dif-1])
        {
            int t = lefte[0];
            if (t==2)
            {
                for (int i = 0; i<dif/2; i++)
                {
                    int tmp = neede[i];
                    neede[i] = neede[dif-i-1];
                    neede[dif-i-1] = tmp;
                }
            }
        }

    }
    for (int i = 0; i<dif; i++)
    {
        int a = lefte[i], b = neede[i];
        if (a>b)
        {
            str[allnum[a][f[a]]] = b+'0';
            f[a]++;
        }
        else
        {
            str[allnum[a][ba[a]]] = b+'0';
            ba[a]--;
        }
    }
    printf("%s",str);
}
