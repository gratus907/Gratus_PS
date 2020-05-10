#include <bits/stdc++.h>
#define lli long long int
#define MAX(A,B) (A)>(B)?(A):(B)
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

set <int> s;
set <int> tmp;
int arr[102000];

int main()
{
    int n,m;
    set <int>::iterator it;
    scanf("%d%d",&n,&m);
    int round = 1;
    for (int i = 1; i<=n; i++)
        s.insert(i);
    tmp = s;
    for (int i = 0; i<m; i++)
    {
        int x;
        scanf("%d",&x);
        arr[x]++;
        if (tmp.count(x))
            tmp.erase(x);
        if (tmp.empty())
        {
            printf("1");
            round++;
            tmp = s;
            for (int j = 1; j<=n; j++)
            {
                if (arr[j] >= round)
                {
                    it = tmp.find(j);
                    tmp.erase(it);
                }
            }
        }
        else
            printf("0");
    }
}
