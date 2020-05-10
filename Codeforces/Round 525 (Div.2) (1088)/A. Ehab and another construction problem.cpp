#include <bits/stdc++.h>
#define lli long long int
#define MAX(A,B) A>B?A:B
#define MIN(A,B) A<B?A:B
#define gcd(A,B) __gcd(A,B)
#define lcm(A,B) A/(__gcd(A,B))*B
#define MP make_pair
#define PB push_back
#define EPS 1e-9
#define ld long double
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,double> pid;

int main()
{
    int a, b, x;
    int flag = 0;
    scanf("%d",&x);
    for (a = 1; a<=x; a++)
    {
        for (b = 1; b<=a; b++)
        {
            if (a%b == 0 )
            {
                if (a*b > x)
                {
                    if (a/b < x)
                    {
                        printf("%d %d",a,b);
                        return 0;
                    }
                }
            }
        }
    }
    printf("-1");
}
