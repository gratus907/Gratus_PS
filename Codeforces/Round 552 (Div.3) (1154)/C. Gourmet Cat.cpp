#include <bits/stdc++.h>
#define ll long long
#define MAX(A,B) (A)>(B)?(A):(B)
#define MIN(A,B) (A)>(B)?(B):(A)
#define gcd(A,B) __gcd(A,B)
#define lcm(A,B) A/__gcd(A,B)*B
#define MP make_pair
#define PB push_back
#define EPS 1e-9
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,double> pid;

int consume[7] = {0,1,2,0,2,1,0}; // 3, 2, 2
int consumecount[3] = {3,2,2};
int food[3];
int main()
{
    scanf("%d%d%d",&food[0],&food[1],&food[2]);

    int perfectweek = MIN(MIN(food[0]/3,food[1]/2),food[2]/2);
    int days = 0;
    for (int i = 0; i<7; i++)
    {
        int b[3];
        int d = i , c = 0;
        for (int j = 0; j<3; j++)
            b[j] = food[j] - (perfectweek*consumecount[j]);
        while (1)
        {
            if (b[consume[d]]>0)
            {
                b[consume[d]]--;
                d++;
                c++;
                d%=7;
            }
            else
                break;
        }
        days = MAX(days,c);
    }
    printf("%lld",(ll)days+(ll)perfectweek*7);
}
