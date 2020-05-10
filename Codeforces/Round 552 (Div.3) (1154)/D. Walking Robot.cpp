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

int seg[201000];
int acc, bat, n;
int capacc, capbat;
int main()
{
    scanf("%d%d%d",&n,&capbat,&capacc);
    acc = capacc, bat = capbat;
    int pos = 0;
    for (int i = 0; i<n; i++)
        scanf("%d",seg+i);
    while(acc > 0 || bat > 0)
    {
        if (bat == 0)
        {
            acc--;
        }
        else
        {
            if (seg[pos] == 1)
            {
                if (acc<capacc)
                {
                    bat--;
                    acc++;
                }
                else
                {
                    if (acc>0)
                        acc--;
                    else if (acc==0)
                        bat--;
                }
            }
            else
            {
                if (acc>0)
                    acc--;
                else if (acc==0)
                    bat--;
            }
        }
        pos++;
        //printf("%d %d %d\n",pos,acc,bat);
        if (acc==0 && bat==0)
            break;
        if (pos == n)
            break;
    }
    printf("%d",pos);
}
