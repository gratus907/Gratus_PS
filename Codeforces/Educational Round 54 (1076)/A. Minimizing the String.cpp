#include <bits/stdc++.h>
#define lli long long int
#define MAX(A,B) A>B?A:B
#define MIN(A,B) A<B?A:B
#define gcd(A,B) __gcd(A,B)
#define lcm(A,B) A/(__gcd(A,B))*B
#define MP make_pair
#define PB push_back
#define EPS 1e-9
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,double> pid;

char word[230000];
int main()
{
    int n,c=0;
    scanf("%d",&n);
    scanf("%s",word);
    for (int i = 0; i<n-1; i++)
    {
        if (word[i] > word[i+1])
        {
            word[i] = 0;
            c=1;
            break;
        }
    }
    if(c==0)
        word[n-1] = 0;
    for (int i = 0; i<n; i++)
    {
        if (word[i] != 0)
            printf("%c",word[i]);
    }
}
