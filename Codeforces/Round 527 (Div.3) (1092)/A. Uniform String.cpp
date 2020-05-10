#include <bits/stdc++.h>
#define lli long long int
#define MAX(A,B) A>B?A:B
#define MIN(A,B) A<B?A:B
#define gcd(A,B) __gcd(A,B)
#define lcm(A,B) A/(__gcd(A,B))*B

using namespace std;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,double> pid;


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        for (int p = 0; p<k; p++)
        {
            for (int i = 0; i<(n/k); i++)
                printf("%c",'a'+p);

        }
        for (int i = 0; i<(n%k); i++)
            printf("%c",'a'+(k-1));
        printf("\n");
    }
}
