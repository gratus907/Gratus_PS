#include <bits/stdc++.h>
#define ll long long
#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
#define gcd(A,B) __gcd(A,B)
#define lcm(A,B) A/(__gcd(A,B))*B
#define MP make_pair
#define PB push_back
#define EPS 1e-9
#define mod 1000000007LL
#define usecppio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,long double> pid;

int sch[402000];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i<n; i++)
    {
        scanf("%d",sch+i);
    }
    for (int i = n; i<2*n; i++)
        sch[i] = sch[i-n];
    int cont = 0, maxcont = 0;
    for (int i = 0; i<2*n; i++)
    {
        if (sch[i] == 1)
            cont++;
        else
        {
            maxcont = MAX(maxcont,cont);
            cont = 0;
        }
    }
    printf("%d",maxcont);
}
