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
#define modulo 998244353
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,double> pid;

int main()
{
    int n;
    char word[70];
    scanf("%d",&n);
    scanf("%s",word);
    int i = 0, j = 1;
    while(i < n)
    {
        printf("%c",word[i]);
        for (int k = 0; k<j; k++)
            i++;
        j++;
    }
}